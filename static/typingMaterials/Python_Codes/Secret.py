s = u'中国'
# s为unicode先转为utf-8
s_utf8 = s.encode('UTF-8')
assert(s_utf8.decode('utf-8') == s)
print(s_utf8)
