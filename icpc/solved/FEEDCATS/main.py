from collections import deque
n, m = [int(x) for x in raw_input().split(' ')]

if n-1 == m:
    print "meow"
    exit()
    

g = [ [] for i in range(n)]
indeg = [ 0 for i in range(n)]
for i in range(m):
    a,b = [int(x) for x in raw_input().split('>')]
    g[a].append((b,i))
    indeg[b] += 1

q = deque()
d = []
for i in range(n):
    if indeg[i] == 0:
        q.append(i)
while len(q) != 0:
    node = q.popleft()
    for b,i in g[node]:
        indeg[b] -= 1
        if indeg[b] == 0:
            q.append(b)
        else:
            d.append(i)

for i in sorted(d):
    print i
