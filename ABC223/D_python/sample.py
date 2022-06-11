# Dr_pilot
import heapq

n,m=map(int,input().split())

g=[[] for _ in range(n+1)]

deg=[0]*(n+1);
deg[0]=1

for _ in range(m):
    a,b=map(int,input().split())
    g[a].append(b)
    deg[b]+=1

ans=[]
q=[]

for i in range(1,n+1):
    if deg[i]==0:
        heapq.heappush(q,i)

while q:
    now=heapq.heappop(q)
    ans.append(now)
    for to in g[now]:
        deg[to]-=1
        if deg[to]==0:
            heapq.heappush(q,to)

if len(ans)!=n:
    print(-1)
else:
    print(*ans)