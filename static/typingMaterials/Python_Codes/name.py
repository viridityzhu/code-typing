import random
chars = [
    '典',
    '引',
    '听',
    '可',
    '叹',
    '歌',
    '策',
    '闻',
    '朝',
    '纷',
    '垠',
    '皆',
    '凭',
    '轩',
    '秉',
    '笔',
    '乐',
    '久',
    '含',
    '熏',
    '任',
    '道',
    '惜',
    '同',
    '由',
    '赏',
    '理',
    '布',
    '嗨',
    '首',
    '综',
    '律',
    '无',
    '派',
    '林',
    '唐',
    '印',
    '不',
    '出',
    '有',
    '结',
    '',
    '以',
    '虽',
    '舟',
    '扶',
    '苏'
]
for i in range(10):
    print('余' + random.choice(chars) + random.choice(chars))


from chinesename import ChineseName  # 导包
cn = ChineseName()  # 实例化
print(cn.getNames(count=10, char_count=2, lastname="余", sex="boy"))
