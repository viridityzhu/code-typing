from django.shortcuts import render
# from django.http import HttpResponse
from myapp import models
from django.contrib import messages
from django.http import HttpResponseRedirect
import pymysql
import pandas as pd
from numpy import mean, median, ptp, var, std
import re
from sklearn import linear_model
import numpy as np


def query(sql):
    '''返回查询据结果'''
    config = dict(zip(['host', 'user', 'port', 'password'],
                      ['127.0.0.1', 'root', 3306, 'root123!']))
    config.update(database='PatentSelection')
    conn = pymysql.connect(**config)
    cursor = conn.cursor()
    cursor.execute(sql)
    data = cursor.fetchall()  # 以元组形式返回查询数据
    header = [t[0] for t in cursor.description]
    df = pd.DataFrame(list(data), columns=header)  # pd.DataFrem 对列表具有更好的兼容性
    # 关闭光标对象
    cursor.close()
    # 关闭数据库连接
    conn.close()
    # header = [t[0] for t in cursor.description]
    # df = pd.DataFrame(list(data), columns=header)  # pd.DataFrem 对列表具有更好的兼容性
    return df


def dataSelect(request):
    sql = 'select * from patents where '
    if(request.GET):
        logTrans = {
            '权利要求数量': 'Claims_number',
            "被引频次": 'Cited_times',
            "专利类型": 'Patent_type',
            "专利分类号": 'Classification_id_num',
            "同族专利数量": 'PatentFamily_number',
            "申请国家/地区": 'Application_country_region',
            "专利维持时间": 'Patent_duration',
            "专利法律状态": 'Litigation_information_num',
        }
        # sql = 'select * from patents where'
        log = eval(request.GET['log'])
        print(log)

        for cnt, item in log.items():
            if '筛选维度' in item.keys():
                continue
            key = logTrans[item['筛选指标']]
            if item['筛选方式'] == 'range':
                tmp = '{} >= {} and {} <= {}'.format(key, item[
                    'value'][0], key, item['value'][1])
            elif item['筛选方式'] == 'choose':
                tmp = ''
                for choseI in item['value']:
                    ttmp = '{}=\'{}\''.format(key, choseI)
                    tmp += ttmp + ' or '
                tmp = tmp[:-4]
            elif item['筛选方式'] == 'biggerThan':
                tmp = '{} >= {}'.format(key, item['value'])
            elif item['筛选方式'] == 'smallerThan':
                tmp = '{} <= {}'.format(key, item['value'])
            sql += '(' + tmp + ') and '
        sql = sql[:-4]
    print(sql)
    tableCnt = query(sql)  # df

    return tableCnt


def stat(data):
    l = []
    # 计算均值
    l.append(mean(data))
    # 计算中位数
    l.append(median(data))
    l.append(ptp(data))
    l.append(var(data))
    l.append(std(data))
    return l


def extractPieData(data):
    labels = ['US', 'JP', 'CN', 'WO', 'EP', 'GB', 'FR', 'DE', 'CH']
    countryGroup = {}
    for i in labels:
        countryGroup[i] = 0
    for i in data:
        countryGroup[i] = countryGroup.get(i, 0) + 1
    return countryGroup


def extractPlotData(heights):
    # 创建直方图
    # 第一个参数为待绘制的定量数据，不同于定性数据，这里并没有事先进行频数统计
    # 第二个参数为划分的区间个数

    iGroup = {}
    for i in heights:
        iGroup[i] = iGroup.get(i, 0) + 1
    d = []
    for i in sorted(iGroup):
        # print((i, iGroup[i]), end=" ")
        d.append([i, iGroup[i]])
    dd = {}

    for i in d:
        k, v = i[0], i[1]
        dd[k] = dd.get(k, 0) + v
    return dd


def analysis(request):
    if request.GET and ('log' in request.GET.keys()):
        d = dataSelect(request)
        qList = stat(d['Claims_number'])
        bList = stat(d['Cited_times'])
        pie = extractPieData(d['Application_country_region'])
        barData = extractPlotData(
            pd.to_datetime(d['Application_date']).dt.year)
        analyData = re.search(r'log=.*', request.get_full_path())[0]
        return render(request, "analysis.html", {'data': d, 'q': qList, 'b': bList, 'pie': pie, 'barData': barData, 'analyData': analyData})


def pred(request):
    if request.GET and ('log' in request.GET.keys()):
        d = dataSelect(request)
        analyData = re.search(r'log=.*', request.get_full_path())[0]
        barData = extractPlotData(
            pd.to_datetime(d['Application_date']).dt.year)
        X, y = list(barData.keys()), list(barData.values())
        maxX = max(X)
        X = np.array(X).reshape(-1, 1)
        y = np.array(y).reshape(-1, 1)
        model = linear_model.LinearRegression()
        model.fit(X, y)
        co = model.coef_
        intercept = model.intercept_
        X_ = np.array([maxX + 1, maxX + 2, maxX + 3,
                       maxX + 4, maxX + 5]).reshape(-1, 1)
        y_ = model.predict(X_)
        preds = []
        for i in range(len(X_)):
            preds.append([X_[i][0], y_[i][0]])
        return render(request, "pred.html", {'data': d,  'barData': barData, 'analyData': analyData, 'co': co, 'preds': preds, 'intercept': intercept})
