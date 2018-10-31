import math

n, m = list(map(int, input().split()))

def isPrime(x):
	for i in range(2, int(math.sqrt(x)+1)):
		if x % i == 0:
			return False

	return True

res = False
for i in range(n + 1, 51):
	if isPrime(i) is True:
		if i == m:
			res = True

		break

if res:
	print('YES')
else:
	print('NO')
