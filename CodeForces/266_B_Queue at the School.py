n, t = list(map(int, input().split()))
s = input()

for _ in range(t):
    check = False
    for i in range(len(s) - 1):
        if check:
            check = False
            continue

        if s[i] == 'B' and s[i+1] == 'G':
            s = s[:i] + 'GB' + s[i+2:]
            check = True;

print(s)