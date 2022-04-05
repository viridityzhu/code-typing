import sqlite3  # 调用sqlite数据库
conn = sqlite3.connect('聊天记录数据库.db')  # 链接“聊天记录数据库.db"
# 建立游标，用sql语句进行筛选，其中，限定了talkername为我们要找的username，并将content长度限定30以下，因为content中会有聊天时所发送的长链接等，需要排除
cursor.execute(
    'select content from tablename where talker=? and length(content)<30', ('目标username',))
value = cursor.fetchall()  # 利用fetchall返回筛选结果
data = open("聊天记录筛选.txt", 'w+', encoding='utf-8')
print(value, file=data)
data.close()  # 将筛选结果写入”聊天记录筛选.txt”
cursor.close()
conn.close()  # 关闭连接
