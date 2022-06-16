from bisect import bisect_left
N, Q = 4, 3
A = list([3, 5, 6, 7])
D = []

# インデックス番号と与えられた値の差
for i, a in enumerate(A):
    D.append(a - i - 1)

for k in [2,5,3]:
    i = bisect_left(D, k)
    print(A)
    print(D,k,i)
    input("-"*30)
    if i == 0:
        print(k)
    else:
        a = k - D[i - 1] + A[i - 1]
        print(a)
