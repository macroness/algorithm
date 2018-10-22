x = int(input())

nine = 9
sum = 0
low = 0

for i in range(1, 10):
    if (low * 10) + 9 < x:
        sum = sum + (nine * i)
    else:
        sum = sum + ((x - low) * i)
        break

    nine = nine * 10
    low = (low * 10) + 9

if x == 1000000000:
    sum = sum + 10

print (sum)