n,k=4,3
a=list([1,1,3,4])

def check(x):
    print("mid",x)
    cnt=0
    for i in range(n):
        cnt+=min(x,a[i])
        input(cnt)
    return cnt

ok=0;ng=10

while ng-ok>1:
    mid=(ok+ng)//2
    if check(mid)>=mid*k:
        ok=mid
    else:
        ng=mid

print(ok)