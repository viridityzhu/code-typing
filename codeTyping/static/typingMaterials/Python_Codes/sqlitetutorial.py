import sqlite3

conn = sqlite3.connect('myFirstDB.db')
curr = conn.cursor()

# curr.execute("""create table myFirsttb(
# 	title text,
# 	author text,
# 	describe text
# 	)""")
curr.execute("""insert into myFirsttb values(
	'wow','zhu','hahaha, my first db is successed!'
	)""")

conn.commit()
conn.close()
