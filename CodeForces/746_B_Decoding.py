n = int(input())
strArr = input()

resStr = strArr[0]
count = 0
strLen = n
if strLen % 2 == 0:
    strLen = strLen - 1

for i in range(1, strLen, 2):
    if n % 2 == 0:
        resStr = strArr[i + 1] + resStr + strArr[i]
    else:
        resStr = strArr[i] + resStr + strArr[i + 1]

if n % 2 == 0:
    resStr = resStr + strArr[-1]

print(resStr)
