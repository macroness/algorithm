n = int(input())
a = list(map(int, input().split()))

count = 0
prevPos = -2
for i in range(1, n-1):
    if (a[i-1] == 1) and (a[i+1] == 1) and (a[i] == 0):
        if prevPos == i - 2:
            count = count + 1
            prevPos = -2
        elif prevPos == -2:
            prevPos = i
        else:
            count = count + 1
            prevPos = i

if prevPos != -2:
    count = count + 1

print (count)

