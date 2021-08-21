from django.shortcuts import render
from myapp import models
from django.contrib import messages


def select(request):
    selectList = [
        {
            'name': "技术指标",
            'checked': False,
            'show': True,
            'variable': 'tech',
            'childrenList': [
                {
                    'checked': False,
                    'isInput': True,
                    'name': "权利要求数量 ≥ ",
                    'variable': 'Claims_number'
                },
                {
                    'checked': False,
                    'isInput': True,
                    'name': "被引频次 ≥ ",
                    'variable': 'Cited_times'
                },
                {
                    'checked': False,
                    'isInput': False,
                    'name': "专利类型 : ",
                    'variable': 'Patent_type',
                    'childrenList': [
                        {'name': "A", 'variable': 'Patent_type_A', },
                        {'name': "B", 'variable': 'Patent_type_B', },
                        {'name': "C", 'variable': 'Patent_type_C', },
                    ]
                },

                {
                    'checked': False,
                    'isInput': True,
                    'name': "专利分类号数量 ≥ ",
                    'variable': 'Classification_id_num'
                }
            ]
        },
        {
            'name': "经济指标",
            'checked': False,
            'show': True,
            'variable': 'econ',
            'childrenList': [
                {
                    'checked': False,
                    'isInput': True,
                    'name': "同族专利数量 ≥ ",
                    'variable': 'PatentFamily_number'
                },
                {
                    'checked': False,
                    'isInput': False,
                    'name': "申请国家/地区 : ",
                    'childrenList': [
                        {'name': "US", 'variable': 'Appl_ctry_US'},
                        {'name': "JP", 'variable': 'Appl_ctry_JP'},
                        {'name': "CN", 'variable': 'Appl_ctry_CN'},
                        {'name': "WO", 'variable': 'Appl_ctry_WO'},
                        {'name': "EP", 'variable': 'Appl_ctry_EP'},
                        {'name': "GB", 'variable': 'Appl_ctry_GB'},
                        {'name': "FR", 'variable': 'Appl_ctry_FR'},
                        {'name': "DE", 'variable': 'Appl_ctry_DE'},
                        {'name': "CH", 'variable': 'Appl_ctry_CH'}
                    ],
                    'variable': 'Application_country_region'
                }
            ]
        },
        {
            'name': "法律指标",
            'checked': False,
            'show': True,
            'variable': 'law',
            'childrenList': [

                {
                    'checked': False,
                    'isInput': True,
                    'name': "专利维持时间（天） ≥ ",
                    'variable': 'Patent_duration'
                },
                {
                    'checked': False,
                    'isInput': True,
                    'name': "专利法律状态数量 ≥ ",
                    'variable': 'Litigation_information_num'}
            ]
        }
    ]

    return render(request, "select.html", {'selectList': selectList})
