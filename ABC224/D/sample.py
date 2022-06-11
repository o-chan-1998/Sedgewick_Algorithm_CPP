# Dr_pilot
from collections import defaultdict, deque

# m = int(input())
m = 5

g = [[] for _ in range(10)]

# for _ in range(m):
#     u,v=map(int,input().split())
#     g[u].append(v)
#     g[v].append(u)
for u, v in zip([1, 1, 1, 2, 3], [2, 3, 9, 9, 9]):
    g[u].append(v)
    g[v].append(u)

# p=list(map(int,input().split()))
p = list([3, 9, 2, 4, 5, 6, 7, 8])

now = ''
for i in p:
    now += str(i)

for i in range(1, 10):
    if str(i) not in now:
		# 1～9のうち抜けている値を求める
        hole = i

d = defaultdict(int)
d[now] = 0

q = deque()
q.append((now, hole, 0))

while q:
    now, hole, cnt = q.popleft()
    for to in g[hole]:
        tmp = now.replace(str(to), str(hole))
        if tmp not in d:
            d[tmp] = cnt+1
            q.append((tmp, to, cnt+1))

if '12345678' in d:
    print(d['12345678'])
else:
    print(-1)
