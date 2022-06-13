# 入力の受け取り
N=4
S=list([1,1,1,1])
T=list([100,10,20,1])

# 1週目
for i in range(N):
    # 次のすぬけ君の番号。i=N-1のとき、次のすぬけ君の番号=Nではなく=0とするため%Nとする。
    next=(i+1)%N
    # 高橋君からもらうのが早いか、左隣のすぬけ君からもらうのが早いか
    T[next]=min(T[next], T[i] + S[i])
    input(T)

# 2周目
for i in range(N):
    # 次のすぬけ君の番号。i=N-1のとき、次のすぬけ君の番号=Nではなく=0とするため%Nとする。
    next=(i+1)%N
    # 高橋君からもらうのが早いか、左隣のすぬけ君からもらうのが早いか
    T[next]=min(T[next], T[i] + S[i])
    input(T)

# 答えの出力
for ans in T:
  print(ans)