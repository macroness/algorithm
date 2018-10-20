import sys

n = int(input())
arr = list(map(int, input().split()))

sortArr = arr.copy()
sortArr.sort()

first = -1
last = -1
# find diff
for i in range(n): 
	if arr[i] is not sortArr[i]:
		if first is -1:
			first = i

		last = i

if first is -1:
	print('yes')
	print('1 1')
	sys.exit()

partArr = arr[first:last+1]
partArr.reverse()

for i in range(len(partArr)):
	if sortArr[i+first] is not partArr[i]:
		print('no')
		sys.exit()

print('yes')
print(first + 1, ' ', last + 1)
