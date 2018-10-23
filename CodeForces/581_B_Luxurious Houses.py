n = int(input())
arr = list(map(int, input().split()))

maxArr = arr.copy()
maxArr.reverse()
maxArr[0] = maxArr[0] * -1
for i in range(1, len(arr)):
    if maxArr[i] > abs(maxArr[i-1]):
        maxArr[i] = maxArr[i] * -1
    else:
        maxArr[i] = abs(maxArr[i-1])

maxArr.reverse()

resultArr = []
for i in range(len(arr)):
    if maxArr[i] < 0:
        print('0', end=' ')
    else:
        print((maxArr[i] - arr[i] + 1), end=' ')
