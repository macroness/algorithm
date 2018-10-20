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

partArr = arr[first:last+1]
partArr.reverse()

answer = True
for i in range(len(partArr)):
	if sortArr[i+first] is partArr[i]:
		answer = False
		break

if answer:
	print('yes')
	print(first + 1, ' ', last + 1)
else:
	print('no')
