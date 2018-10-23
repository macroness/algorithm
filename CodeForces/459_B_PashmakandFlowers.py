def factorial(n):
    if n <= 1: 
        return 1
    else:
        result = 1
        for i in range(2, n + 1):
            result *= i
    return result

def nCr(n, r):
    numerator = 1
    denominator = 1
    r = min(n-r, r)
    for i in range(1, r+1):
        denominator *= i
        numerator *= n+1-i
    return numerator/denominator


n = int(input())
flowers = list(map(int, input().split()))

flowers.sort()

a = flowers[-1] - flowers[0]
b = 0
if a == 0:
    b = int(nCr(n, 2))
else:
    b = flowers.count(flowers[-1]) * flowers.count(flowers[0])

print (a, b)