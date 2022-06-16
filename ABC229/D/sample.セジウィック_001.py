##########################################################################
### 【ロバート セジウィック】セジウィック：アルゴリズムC 第1～4部(P.10)
##########################################################################

import random

N=10

id=[0 for _ in range(N)]
for i in range(N):
    id[i]=i

for _ in range(10):
    p = random.randint(0, N-1)
    q = random.randint(0, N-1)

    if id[p] == id[q]:
        continue

    t = id[p]
    for i in range(N):
        if(id[i]==t):
            id[i] = id[q]

print(id)

##########################################################################
### 【ロバート セジウィック】セジウィック：アルゴリズムC 第1～4部(P.13)
##########################################################################

import random

N=10

id=[0 for _ in range(N)]
for i in range(N):
    id[i]=i

for _ in range(10):
    p = random.randint(0, N-1)
    q = random.randint(0, N-1)

    i=p
    while(i != id[i]):
        i = id[i]

    j=q
    while(j != id[j]):
        j = id[j]

    if i==j:
        continue

    id[i] = j

    print(p,q)

print(id)


##########################################################################
### 【ロバート セジウィック】セジウィック：アルゴリズムC 第1～4部(P.14)
### 加重高速合併法
##########################################################################

import random

N=10

id=[0 for _ in range(N)]
sz=[0 for _ in range(N)]

for i in range(N):
    id[i] = i
    sz[i] = 1

for _ in range(10):
    p = random.randint(0, N-1)
    q = random.randint(0, N-1)
    print("入力値p=",p,",q=",q,"id配列",id)

    i=p
    while(i != id[i]):
        i = id[i]

    j=q
    while(j != id[j]):
        j = id[j]

    if i==j:
        continue

    if sz[i]<sz[j]:
        id[i] = j
        sz[j] += sz[i]
    else:
        id[j] = i
        sz[i] += sz[j]

    print(p,q)

print(id)
