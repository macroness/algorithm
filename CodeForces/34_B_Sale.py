n, m = list(map(int, input().split()))
arr = list(map(int, input().split()))

arr.sort()

sum = 0

for i in range(m):
    if arr[i] < 0:
        sum = sum - arr[i]

print(sum)