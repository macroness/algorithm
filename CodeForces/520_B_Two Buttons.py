import sys
b, e = list(map(int, input().split()))

if b >= e:
    print(b - e)
    sys.exit()

count = 0
while b is not e:
    if e > b:
        if (e % 2) is 0:
            e = e // 2
        else:
            e = e + 1
    else:
        count = count + b - e
        break

    count = count + 1

print(count)