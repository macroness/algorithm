from operator import itemgetter
import sys
n = int(input())
arr = []

for _ in range(n):
    ab = list(map(int, input().split()))
    arr.append(ab)


arr.sort(key=itemgetter(0,1))

if n == 1:
    print (min(arr[0]))
    sys.exit()

minn = min(arr[0])
for a in arr:
    if minn <= a[1]:
        minn = a[1]
    else:
        minn = a[0]

print(minn)