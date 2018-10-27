n, m = list(map(int, input().split()))
cat = list(map(int, input().split()))
cat.insert(0,0)
tree = {}
count = 0
visit = set()
for _ in range(n-1):
	x, y = list(map(int, input().split()))
	if x not in tree:
		tree[x] = []
	if y not in tree:
		tree[y] = []

	tree[x].append(y)
	tree[y].append(x)

def goRstr(p, catsNum, count):
	if p in visit:
		return count

	visit.add(p)

	if cat[p] is 1:
		catsNum = catsNum + 1
		if catsNum > m:
			return count
	else:
		catsNum = 0

	if len(tree[p]) is 1 and p is not 1:
		return count + 1

	for x in tree[p]:
		count = goRstr(x, catsNum, count)

	return count

count = goRstr(1, 0, count)

print(count)
