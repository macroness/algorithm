import sys

n = int(input())
s = input()
res = ''
for i in range(n-1):
    if s[i] > s[i+1]:
        res = s[0:i] + s[i+1:]
        print(res)
        sys.exit()

print(s[:-1])
