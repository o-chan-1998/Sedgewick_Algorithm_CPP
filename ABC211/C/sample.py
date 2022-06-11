def main():
    # 入力の受け取り
#    S = input()
    S = "cahchokudaai"
    # 文字数=N
    N = len(S)

    # Sの0文字目を?にする
    S = "?"+S   # index整理
    # T=?chokudai(?は0文字目)
    T = "?chokudai" # index整理
    
    # 余りの定義
    mod = 10**9+7
    # dp表を作る(Nの文字列長✕9)
    dp = [[0]*9 for i in range(N+1)]

    # Sのi文字目までを使う
    for i in range(N+1):
        # chokudaiのj文字目までを作る
        for j in range(len("chokudai")+1):
            print(i,j,S[i],T[j])
            for dpp in dp:
                print(dpp)
            input("-----"*5)
            # j=0(chokudaiの0文字目までを作る→1通り)
            if j == 0:
                # 1通り(dp[0][*]を1通りにする)
                dp[i][j] = 1
                # j=1~8
            else:
                # i=0(Sの0文字目までを使う→使える文字なし)
                if i == 0:
                    # 作りようがないから0
                    dp[i][j] = 0
                # i=1～N
                else:
                    # もしSのi文字目とchokudaiのj文字目が違うなら
                    if S[i] != T[j]:
                        # Sのi-1文字目までを使ってchokudaiのj文字目を作る場合と同じ数
                        dp[i][j] = dp[i-1][j]
                    # もしSのi文字目とchokudaiのj文字目が同じなら
                    else:
                        # dp[i-1][j]：Sのi-1文字目までを使ってchokudaiのj文字目を作る場合(Sのi文字目を使わない)
                        # dp[i-1][j-1]：Sのi-1文字目までを使ってchokudaiのj-1文字目を作る場合(Sのi文字目を使う)
                        dp[i][j] = dp[i-1][j]+dp[i-1][j-1]
        # 余りを取る
        dp[i][j] %= mod

    # SのN文字目までを使ってchokudaiの8文字目までを作る方法の数
    print(dp[N][8])


if __name__ == '__main__':
    main()
