from wxpy import *
bot = Bot()
# 打印来自其他好友、群聊和公众号的消息


@bot.register()
def print_others(msg):
    print(msg)
