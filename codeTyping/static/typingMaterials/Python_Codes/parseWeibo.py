from bs4 import BeautifulSoup
import bs4


soup = BeautifulSoup(open('/Users/jiayinzhu/Downloads/m.html'), 'html.parser')
out = ''
total = 0
for t in soup.select('.list_con > .WB_text'):
    # print(t.contents)  one piece of item
    # print(t.contents[1].string)  user name
    username = t.contents[1].string
    s = ''
    for i in t.contents[2:]:
        if isinstance(i, bs4.element.NavigableString):
            s += i.string.replace(',', '，')
    # print(s)      text content
    try:
        thumbNum = t.find_next_sibling('div').find_next_sibling('div').select(
            'div.WB_handle.W_fr em')[1].string
        if thumbNum == '赞':
            thumbNum = '0'
    except:
        thumbNum = '0'
    try:
        time = t.find_next_sibling('div').find_next_sibling('div').select(
            'div.WB_from.S_txt2')[0].string
    except:
        try:
            time = t.find_next_sibling('div').select(
                'div.WB_from.S_txt2')[0].string
        except:
            time = 'None'
    total += 1
    s = s[1:]
    lenth = len(s)
    if s == ' ' or s == '  ':
        s = '@了某人'

    out += str(total) + ',' + username + ',' + \
        s + ',' + str(lenth) + ',' + thumbNum + ',' + time + '\n'


with open('outWeibo.csv', 'w') as f:
    f.write('顺序号,用户名,内容,内容长度,赞数,时间\n')
    f.write(out)

print('all is ok, total = ' + str(total))
