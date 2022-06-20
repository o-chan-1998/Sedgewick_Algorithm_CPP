from itertools import accumulate
from collections import defaultdict

n,k=6,5
a=list([0, -3, 5, 7, 0, -4])

# 累積和
b=[0]+list(accumulate(a))
print(b)

# 連想配列
d=defaultdict(int)

ans=0
for i in range(1,n+1):
    # インデックスの一つ前の要素までの累積和が取る値の回数
    d[b[i-1]]+=1

    # 対象要素からKを引いた値が出現する回数
    ans+=d[b[i]-k]
    
    print(d)
    input(ans)

print(d)
print(ans)