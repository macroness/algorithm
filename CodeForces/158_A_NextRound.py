n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))
res = 0;
for i in range(n):
    if arr[k - 1] <= arr[i] and arr[i] > 0:
        res = res + 1
        
    if arr[k - 1] > arr[i]:
        break
    
print (res)
