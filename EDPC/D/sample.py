N, W = 6, 15

dp = [[0]*(W+1) for i in range(N+1)]

print(N, "個の商品に対して、持ち帰り可能な重さは最大", W, "である")
print("DPテーブルの初期状態")
for debug_data in dp:
    print(debug_data)
print("-"*30)

for n, wi, vi in [[1, 6, 5], [2, 5, 6], [3, 6, 4], [4, 6, 6], [5, 3, 5], [6, 7, 2]]:

    print(n,"番目の品物")

    for w in range(W+1):
        print(w,"の重さに対してDPテーブル更新")
    
        if w-wi < 0:
            print(n,"番目の商品を持ち帰れない(",wi,")ので、前のテーブルをコピーする")
            dp[n][w] = dp[n-1][w]
        else:
            print(n,"番目の商品：重さ",wi,"、価値",vi,"でテーブル更新")
            if dp[n-1][w] > dp[n-1][w-wi]+vi:
                dp[n][w] = dp[n-1][w]
                for debug_data in dp[n-1:n+1]:
                    print(debug_data)
                input("*"*30)
            else :
                dp[n][w] = dp[n-1][w-wi]+vi
                for debug_data in dp[n-1:n+1]:
                    print(debug_data)
                input("*"*30)

for debug_data in dp:
    print(debug_data)
print(dp[-1][-1])
