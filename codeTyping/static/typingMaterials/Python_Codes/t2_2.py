#RMBandDollar.py
m=input('How much do you have?')
if m[-1] in ['rmb','y']:
    print('So you have {} dollar.'.format(eval(m[0:-1])/6))
elif m[-1] in ['dollar','d']:
    print('So you have {} yuan.'.format(eval(m[0:-1])*6))
