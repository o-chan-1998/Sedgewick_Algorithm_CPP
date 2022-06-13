from math import gcd

def main():
    n, k = 10, 4 
    h = list([40,10,20,70,80,10,20,70,80,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])

    dp = list([99999]*20)
    dp[0]=0

    for i in range(n):
        for j in range(1,k+1):
            print(i,"番目の足の置き場")
            print(i,"から",i+j,"の足場へジャンプ")
            print("【",i+j,"番目のDPテーブル】(",dp[i+j],")と【",i,"番目のDPテーブル】(",dp[i],")に",i,"から",i+j,"へジャンプするコストを加算したものの小さい方")
            print("足場",i,"のコストは",h[i],"、足場",i+j,"番目のコストは",h[i+j],"なので支払うコストは",abs(h[i+j]-h[i]),"となる")
            print("更新前DPテーブルの内容")
            input(dp)
            dp[i+j] = min(dp[i+j],dp[i]+abs(h[i+j]-h[i]))
            print("更新後DPテーブルの内容")
            input(dp)
            print("-"*30)

    print(dp[n-1])

if __name__ == '__main__':
    main()