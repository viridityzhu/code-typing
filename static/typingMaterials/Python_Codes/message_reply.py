# -*- coding: UTF-8 -*-
import time
from lxml import etree
from flask import request
from flask import Flask, make_response    # 这些是本例中所有用到的库
import requests
import paddle.fluid as fluid
import numpy as np
from PIL import Image


class Message(object):

    def __init__(self, req):
        self.request = req
        self.token = '111'


class Post(Message):

    def __init__(self, req):
        super(Post, self).__init__(req)
        self.xml = etree.fromstring(req.stream.read())
        self.MsgType = self.xml.find("MsgType").text
        self.ToUserName = self.xml.find("ToUserName").text
        self.FromUserName = self.xml.find("FromUserName").text
        self.CreateTime = self.xml.find("CreateTime").text
        self.MsgId = self.xml.find("MsgId").text
        print(self.MsgType, self.ToUserName, self.FromUserName)

        hash_table = {
            'text': ['Content'],
            'image': ['PicUrl', 'MediaId'],
            'voice': ['MediaId', 'Format'],
            'video': ['MediaId', 'ThumbMediaId'],
            'shortvideo': ['MediaId', 'ThumbMediaId'],
            'location': ['Location_X', 'Location_Y', 'Scale', 'Label'],
            'link': ['Title', 'Description', 'Url'],
        }
        attributes = hash_table[self.MsgType]
        self.Content = self.xml.find(
            "Content").text if 'Content' in attributes else '抱歉，暂未支持此消息。'
        print(self.Content)
        self.PicUrl = self.xml.find(
            "PicUrl").text if 'PicUrl' in attributes else '抱歉，暂未支持此消息。'
        # self.MediaId = self.xml.find(
        #     "MediaId").text if 'MediaId' in attributes else '抱歉，暂未支持此消息。'
        self.Format = self.xml.find(
            "Format").text if 'Format' in attributes else '抱歉，暂未支持此消息。'
        self.ThumbMediaId = self.xml.find(
            "ThumbMediaId").text if 'ThumbMediaId' in attributes else '抱歉，暂未支持此消息。'
        self.Location_X = self.xml.find(
            "Location_X").text if 'Location_X' in attributes else '抱歉，暂未支持此消息。'
        self.Location_Y = self.xml.find(
            "Location_Y").text if 'Location_Y' in attributes else '抱歉，暂未支持此消息。'
        self.Scale = self.xml.find(
            "Scale").text if 'Scale' in attributes else '抱歉，暂未支持此消息。'
        self.Label = self.xml.find(
            "Label").text if 'Label' in attributes else '抱歉，暂未支持此消息。'
        self.Title = self.xml.find(
            "Title").text if 'Title' in attributes else '抱歉，暂未支持此消息。'
        self.Description = self.xml.find(
            "Description").text if 'Description' in attributes else '抱歉，暂未支持此消息。'
        self.Url = self.xml.find(
            "Url").text if 'Url' in attributes else '抱歉，暂未支持此消息。'
        self.Recognition = self.xml.find(
            "Recognition").text if 'Recognition' in attributes else '抱歉，暂未支持此消息。'


class Reply(Post):

    def __init__(self, req):
        super(Reply, self).__init__(req)
        self.xml = f'<xml><ToUserName><![CDATA[{self.FromUserName}]]></ToUserName>' \
            f'<FromUserName><![CDATA[{self.ToUserName}]]></FromUserName>' \
            f'<CreateTime>{str(int(time.time()))}</CreateTime>'

    def text(self, Content):
        # 复读机
        # self.xml += f'<MsgType><![CDATA[text]]></MsgType>' \
        #     f'<Content><![CDATA[{Content}]]></Content></xml>'
        self.xml += f'<MsgType><![CDATA[text]]></MsgType>' \
            '<Content><![CDATA[{}]]></Content></xml>'.format(
                '一只人工智障不小心被放出来了……发送猫/狗的图片试试？')

    def image(self, PicUrl):
        model_save_dir = '/usr/etc/catdog.inference.model/catdog.inference.model'
        picDir = '/usr/etc/{}.png'.format(PicUrl.split('/')[-2])

        def load_image(file):
            # 打开图片
            im = Image.open(file)
            # 将图片调整为跟训练数据一样的大小32*32，ANTIALIAS即抗锯齿.
            im = im.resize((32, 32), Image.ANTIALIAS)
            # 建立图片矩阵 类型为float32
            im = np.array(im).astype(np.float32)
            # 矩阵转置
            im = im.transpose((2, 0, 1))
            # 将像素值从【0-255】转换为【0-1】
            im = im / 255.0
            # print(im)
            im = np.expand_dims(im, axis=0)
            # 保持和之前输入image维度一致
            return im

        # save image
        r = requests.get(PicUrl)
        with open(picDir, 'wb') as f:
            f.write(r.content)

        # prepare to predict
        place = fluid.CPUPlace()
        infer_exe = fluid.Executor(place)
        inference_scope = fluid.core.Scope()
        with fluid.scope_guard(inference_scope):
            # 从指定目录中加载推理model:inference model
            [inference_program,  # 预测用的program
             feed_target_names,  # 是一个str列表，它包含需要在推理 Program 中提供数据的变量的名称。
             # fetch_targets：是一个 Variable 列表，从中我们可以得到推断结果。
             fetch_targets] = fluid.io.load_inference_model(model_save_dir,
                                                            infer_exe)  # infer_exe: 运行 inference model的 executor

            img = load_image(picDir)

            results = infer_exe.run(inference_program,  # 运行预测程序
                                    # 喂入要预测的img
                                    feed={feed_target_names[0]: img},
                                    fetch_list=fetch_targets)  # 得到推测结果
            print('预测结果：', results)
            label_list = [
                "猫猫",  "狗狗"
            ]
            predict_stuff = label_list[np.argmax(results[0][0][3:6:2])]
        print("这一定是一只可爱的 %s" % predict_stuff)
        sentence = '这一定是一只可爱的{}！'.format(predict_stuff)
        self.xml += '<MsgType><![CDATA[text]]></MsgType><Content><![CDATA[{}]]></Content></xml>'.format(
            sentence)

    def voice(self, MediaId):
        pass

    def video(self, MediaId, Title, Description):
        pass

    def music(self, ThumbMediaId, Title='', Description='', MusicURL='', HQMusicUrl=''):
        pass

    def reply(self):
        response = make_response(self.xml)
        response.content_type = 'application/xml'
        return response


app = Flask(__name__)


@app.route("/weixin", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        message = Reply(request)
        if message.MsgType == 'text':
            message.text(message.Content)
        elif message.MsgType == 'image':
            message.image(message.PicUrl)
        return message.reply()


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80)
