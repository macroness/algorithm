n = int(input())

maxCount = -1
count = 1
prevMin = -1
for _ in range(n):
    h, m = list(map(int, input().split()))
    m = (60*h) + m
    if prevMin == m:
        count = count+1
    else:
        if maxCount < count:
            maxCount = count
        count = 1
    prevMin = m

print(maxCount)