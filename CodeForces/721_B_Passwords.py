n, k = list(map(int, input().split()))
lengths = []
countDict = {}
for _ in range(n):
	length = len(input())
	if length in countDict:
		countDict[length] = countDict[length] + 1
	else:
		countDict[length] = 1
		lengths.append(length)

pwd = len(input())

lengths.sort()

minEnter = 0
maxEnter = 0

for x in lengths:
	if x is pwd:
		maxEnter = minEnter + countDict[x]
		break
	minEnter = minEnter + countDict[x]

minEnter = minEnter + 1

minSec = (((minEnter-1)//k)*5) + minEnter
maxSec = (((maxEnter-1)//k)*5) + maxEnter

print(minSec, maxSec)
