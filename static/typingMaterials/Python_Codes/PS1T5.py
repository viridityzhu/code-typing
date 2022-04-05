print('?')
n = input()
d = int(input())
print(str(int(n) // (10**(len(n) - d - 1))))
# n=12345 d=2
# n//100=123, n%10=5
