import sys

n, s = list(map(int,input().split()))
goR = list(map(int,input().split()))
goL = list(map(int,input().split()))

s = s - 1
if goR[0] == 0:
    print ("NO")
    sys.exit()

if (goR[s] == 0) and (goL[s] == 0):
    print ("NO")
    sys.exit()

if goR[s] == 1:
    print ("YES")
    sys.exit()

for i in range(s+1, n):
    if goR[i] == 1 and goL[i] == 1:
        print ("YES")
        sys.exit()

print("NO")
