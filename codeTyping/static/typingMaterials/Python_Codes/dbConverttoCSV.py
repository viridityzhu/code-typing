import sqlite3


conn = sqlite3.connect('/Users/jiayinzhu/Downloads/zhihu_topic.db')
curr = conn.cursor()

rows = curr.execute("""select * from firstpage_tb;""")
for row in rows:
    print(row[1])
    print()
    # row[5] = str(row[5]).replace(';', '；')
    print(row[5])
    curr.execute(
        "UPDATE firstpage_tb set content = (?) where title=(?)", (row[5], row[1]))


# curr.execute("""drop table if exists new_tb""")
# curr.execute("""create table new_tb(
#                             type text,
#                             title text,
#                             question_link text,
#                             author text,
#                             author_link text,
#                             content text,
#                             agreements text)""")
# for row in rows:
#     for line in row:
#         line.replace(';', '；')
#         print(line)
#     row = list(row)
# curr.execute("""insert into new_tb values(?,?,?,?,?,?,?)""", (
#     row[0],
#     row[1],
#     row[2],
#     row[3],
#     row[4],
#     row[5],
#     row[6]
# ))
print('ok.')
conn.commit()
conn.close()
