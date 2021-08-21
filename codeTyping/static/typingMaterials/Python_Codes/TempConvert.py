#TempConvert.py

if input('Tell me your temperature:')[-1]in['f','F']:
    c=(eval(t[0:-1])-32)/1.8
    print('So the Celsius is: {:.0f}'.format(c))
elif input('Tell me your temperature:')[-1] in ['C','c']:
    f=eval(t[0:-1])*1.8+32
    print('So the Fabrenheit is:{:.0f}'.format(f))
else:
    print('Your format is wrong.')
