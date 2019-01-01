y, b, r = list(map(int, input().split()))

minNum = min(y, b, r)

if y == minNum:
    if b == minNum:
        if r == minNum:
            y = y - 2
        else:
            y = y - 1
    else:
        if r == minNum:
            y = y - 2
        else:
            if r == minNum + 1:
                y = y - 1
elif b == minNum:
    if r == minNum:
        y = b - 2
    else:
        y = b - 1
else:
    y = r - 2

print((3*y) + 3)

