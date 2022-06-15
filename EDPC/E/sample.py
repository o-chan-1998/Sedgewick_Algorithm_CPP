N, cap = 6,15
w, v = [], []

for W, V in [[6,5],[5,6],[6,4],[6,6],[3,5],[7,2]]:
    w.append(W)
    v.append(V)

# 価値の総和
s = sum(v)

dp = [99] * (s + 1)

dp[0] = 0
print(dp)
for i in range(N):
    for j in range(s, v[i] - 1, -1):
        print("dp[",j,"]とdp[",j,"-v[",i,"](",v[i],")] + w[",i,"](",w[i],")を比較する")
        if dp[j]<dp[j - v[i]] + w[i]:
            print("dp[",j,"](",dp[j],")の方がdp[",j - v[i],"] + w[",i,"](",dp[j - v[i]] + w[i],")より小さいので未更新")
            dp[j] = dp[j]
            input(dp)
        else:
            print("dp[",j - v[i],"] + w[",i,"](",dp[j - v[i]] + w[i],")の方がdp[",j,"](",dp[j],")より小さいので更新")
            dp[j] = dp[j - v[i]] + w[i]
            input(dp)

res = 0
for i in range(s + 1):
    if dp[i] <= cap:
        res = max(i, res)
print(res)
