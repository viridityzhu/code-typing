# -*- coding: UTF-8 -*-
import paddle.fluid as fluid
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

model_save_dir = '/Users/jiayinzhu/Downloads/catdog.inference.model'
picDir = '/Users/jiayinzhu/Documents/Python_codes_of_mine/test_pics/1.jpg'


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


# prepare to predict
place = fluid.CPUPlace()
infer_exe = fluid.Executor(place)
inference_scope = fluid.core.Scope()
with fluid.scope_guard(inference_scope):
    img = Image.open(picDir)
    plt.imshow(img)  # 根据数组绘制图像
    plt.show()  # 显示图像
    img = load_image(picDir)
    # 从指定目录中加载推理model:inference model
    [inference_program,  # 预测用的program
     feed_target_names,  # 是一个str列表，它包含需要在推理 Program 中提供数据的变量的名称。
     # fetch_targets：是一个 Variable 列表，从中我们可以得到推断结果。
     fetch_targets] = fluid.io.load_inference_model(model_save_dir,
                                                    infer_exe)  # infer_exe: 运行 inference model的 executor

    results = infer_exe.run(inference_program,  # 运行预测程序
                            feed={feed_target_names[0]: img},  # 喂入要预测的img
                            fetch_list=fetch_targets)  # 得到推测结果
    print('预测结果：', results)
    # [np.array([[4.8919302e-27, 1.6038109e-28, 6.2789530e-24, 1.0000000e+00,1.6038109e-28, 5.5096767e-09, 2.9356311e-13, 1.6038109e-28,6.8492938e-21, 1.6038109e-28]],0)]
    # label_list = [
    #     "飞机", "汽车", "鸟", "猫猫", "鹿鹿", "狗狗", "青蛙", "马马",
    #     "船", "大卡车"
    # ]
    label_list = [
        "猫猫",  "狗狗"
    ]
    predict_stuff = label_list[np.argmax(results[0][0][3:6:2])]
print("这一定是一只可爱的 %s" % predict_stuff)
