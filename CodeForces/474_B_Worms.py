n = int(input())
listA = list(map(int,input().split()))

mm = int(input())
listM = list(map(int,input().split()))

for i in range(1,n):
    listA[i] = listA[i] + listA[i-1]

listA.insert(0, 0)

def getPos(l, u, x):
    m = int((l + u) / 2)

    if listA[m] >= x and listA[m-1] < x:
        print(m)
        return

    if listA[m] > x:
        return getPos(l, m-1, x)
    else:
        return getPos(m+1, u, x)

for a in listM:
    getPos(0, n, a)
 
