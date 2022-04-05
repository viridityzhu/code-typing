# 打开a.txt
with open('a.txt', 'r') as f:
    # 读每行
    for line in f.readlines():
        # 处理每行
        if len(line) > 3:
            # 把需要的line写进b
            with open('b.txt', 'a+') as f2:
                f2.write(line)
