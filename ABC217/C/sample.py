# 入力の受け取り
N=int(input())
# P[0]を埋めるため、[0]+にする
P=[0]+list(map(int, input().split()))

# Qを用意
Q=[0]*(N+1)

# i=1~Nまで
for i in range(1,N+1):
    # Q[P[i]]=iを順に埋める
    Q[P[i]]=i

# 答えを出力
# *(リスト)にすると[]なしで出力
# Q[0]は不要なのでQ[1:](1以降を出力)
print(*Q[1:])