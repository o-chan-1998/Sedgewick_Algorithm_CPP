# 入力の受け取り
N=128
# 答え(最初は空)
ans=""

# Nが0より大きい間
while 0<N:
    # Nが偶数なら
    if N%2==0:
        # ansの左端にBを追加
        ans="B"+ans
        # 2で割る
        N//=2
    # それ以外(Nが奇数なら)
    else:
        # ansの左端にAを追加
        ans="A"+ans
        # 1を引く
        N-=1

# 答えを出力
print(ans)