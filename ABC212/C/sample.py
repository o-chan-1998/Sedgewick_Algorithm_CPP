def main():
    # 入力の受け取り
    # N,M=map(int, input().split())
    # A=list(map(int, input().split()))
    # B=list(map(int, input().split()))
    N,M=6,8
    A=list([82, 76, 82, 82, 71, 70])
    B=list([17, 39, 67, 2, 45, 35, 22, 24])

    # A,Bをソート
    A.sort()
    B.sort()

    # i：Aのインデックス番号
    # j：Bのインデックス番号
    i=0
    j=0

    # 答え(最小を取るので最初はバカでかい数)
    ans=10**20

    # i<N,j<Mの範囲で
    while i<N and j<M:
        # |A[i]-B[j]|を計算、今までの答えより小さければ答えを更新
        ans=min(ans,abs(A[i]-B[j]))

        # もしA[i]<B[j]ならば
        if A[i]<B[j]:
            # Aを次へ
            i+=1
        # もしB[j]<A[i]ならば
        elif B[j]<A[i]:
            # Bを次へ
            j+=1
        # もしA[i]=B[j]ならば
        else:
            # 答えは0
            print(0)
            # 終了
            exit()

    # 答えの出力
    print(ans)

if __name__ == '__main__':
    main()