two, three, five, six = list(map(int, input().split()))

minX = min(two, five,six)

result = minX * 256

minY = min(two - minX, three)

print(result + (minY * 32))
