n = int(input());

for _ in range(n):
    a, b, k = list(map(int, input().split()))
    print((k//2)*(a-b) + (k%2)*a)
