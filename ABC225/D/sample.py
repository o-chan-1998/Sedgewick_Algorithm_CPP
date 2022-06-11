
# n, q = map(int, input().split())
n, q = 7, 14

head = [-1]*(n+1)
tail = [-1]*(n+1)

for l in [[1,6,3],[1,4,1],[1,5,2],[1,2,7],[1,3,5],[3,2],[3,4],[3,6],[2,3,5],[2,4,1],[1,1,5],[3,2],[3,4],[3,6]]:

    if l[0] == 1:
        x = l[1]
        y = l[2]
        tail[x] = y
        head[y] = x

    elif l[0] == 2:
        x = l[1]
        y = l[2]
        tail[x] = -1
        head[y] = -1

    else:
        x = l[1]
        ans = []
        now = x
        while head[now] != -1:
            now = head[now]
        while now != -1:
            ans.append(now)
            now = tail[now]
        print(len(ans), *ans)
