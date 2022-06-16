def lcs(s, t):
    m, n = len(s), len(t)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for debug_data in dp:
        print(debug_data)

    # 文字列sループのインデックス
    for i in range(1, m + 1):
        # 文字列tループのインデックス
        for j in range(1, n + 1):
            if s[i - 1] == t[j - 1]:
                print("s[",i-1,"](",s[i-1],")==t[",j-1,"](",t[j-1],")")
                dp[i][j] = dp[i - 1][j - 1] + 1
                for debug_data in dp:
                    print(debug_data)
            else:
                if dp[i - 1][j] > dp[i][j - 1]:
                    print("文字列sの一つ前のDPテーブルの値を代入")
                    dp[i][j] = dp[i - 1][j]
                    for debug_data in dp:
                        print(debug_data)

                else:
                    print("文字列tの一つ前のDPテーブルの値を代入")
                    dp[i][j] = dp[i][j - 1]
                    for debug_data in dp:
                        print(debug_data)
            input("-"*30)
 
    res = ""
    while (m and n):
        if s[m - 1] == t[n - 1]:
            res += s[m - 1]
            m -= 1
            n -= 1
        elif dp[m - 1][n] > dp[m][n - 1]:
            m -= 1
        else:
            n -= 1
    

    return res[::-1]


s = "abracadabra"
t = "avadakedavra"
print(lcs(s, t))

