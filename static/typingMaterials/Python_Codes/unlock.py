import string
import itertools


def get_strings():
    chars = string.printable[:10]
    strings = []
    for i in range(minN, maxN + 1):
        strings.append((itertools.product(chars, repeat=i),))
    return itertools.chain(*strings)


def make_dict():
    f = open('t.txt', 'a')
    for x in list_str:
        for y in x:
            f.write("".join(y))
            f.write('\n')
    f.close()
    print('Done')


minN = int(input('min:'))
maxN = int(input('max:'))

if minN <= maxN:
    while True:
        list_str = get_strings(minN, maxN)
        make_dict()
        sys.exit(0)
