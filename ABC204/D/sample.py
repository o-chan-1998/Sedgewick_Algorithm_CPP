import math

N = 5
times = list([8,3,7,2,5])

# N品の料理に使う合計値の半分を計算する
half = math.ceil(sum(times)/2)

# N品✕合計時間
dp = [[0]*(sum(times)+1) for i in range(N+1)]
for debug_data in dp:
    print(debug_data)

for n in range(N+1):
  if n == 0:
    print("一品目",times[0],"時間にチェック")
    dp[1][0] = 1
    dp[1][times[0]] = 1
    for debug_data in dp:
        print(debug_data)
  if n != 0:
    print(n,"品目(n>1)")
    for x in range(sum(times)+1):
      if dp[n-1][x] == 1:
        print("前の品(",n-1,")でフラグが立っている(",x,")コピー")
        dp[n][x] = 1
        if x+times[n-1] <= sum(times)+1:
          print(x,"+times[",n-1,"](",times[n-1],") <= 総時間以下の場合")
          dp[n][x+times[n-1]] = 1

        for debug_data in dp:
            print(debug_data)
        input("_"*10)

input("-"*30)

for i in range(half,sum(times)+1):
  # 半分以上のうちで最小のもの
  if dp[-1][i] == 1:
    print(i)
    break
  else:
    continue