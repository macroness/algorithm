import sys

m, s = list(map(int, input().split()))
if m == 1 and s == 0:
    print ("0 0")
    sys.exit()

if (s > (9*m)) or (s <= 0) :
    print ("-1 -1")
    sys.exit()

max, min = "", ""

minS = s
for i in range(m):
    if s - 9 >= 0:
        max = max + '9'
        s = s - 9
    else:
        max = max + "{0}".format(s)
        s = 0

s = minS
for i in range(m - 1):
    if s - 1 >= 9:
        min = min + '9'
        s = s - 9
    else:
        min = min + "{0}".format(s - 1)
        s = 1

if s == 1:
    min = min + '1'
else:
    min = min + "{0}".format(s)



print (min[::-1], max)

