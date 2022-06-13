h=0
w=0
a = [[0 for j in range(5)] for i in range(5)]
visited = [[0 for j in range(5)] for i in range(5)]
memo = [[0 for j in range(5)] for i in range(5)]

saiki_flag = []
saiki_counter = 0

def f(i,j) :
    global memo
    global visited
    global a

    global saiki_flag
    global saiki_counter

    print(i,j,"の座標を確認する")
    if i == h-1 and j == w-1:
        print("終端に来たので、0を戻す")
        for output_data in memo:
            print(output_data)
        return 0
    if visited[i][j]:
        print(i,j,"が訪問済みなのではmemo[i][j]の値(",memo[i][j],")を返す")
        for output_data in memo:
            print(output_data)
        return memo[i][j]
    
    visited[i][j] = 1;
    print(i,j,"を訪問済みとして扱う")
    for output_data in visited:
        print(output_data)
    
    res = -9999999
    if j+1 < w:
        print("◇",saiki_counter,"回目の呼び出し")
        print(i,j+1,"は未訪問なので、右の座標データを確認する")
        print(res,"と(",i,j+1,")の座標の値",a[i][j+1],"から(",i,j+1,")の計算から得られた値の大きい方を求める")
        saiki_flag.append(saiki_counter)
        saiki_counter += 1
        input("再帰前-01")

        res = max(res, a[i][j+1]-f(i,j+1))

        print("◆",saiki_flag.pop(),"回目の呼び出しに対する応答")
        input("再帰後-02")

    if i+1 < h:
        print("◇",saiki_counter,"回目の呼び出し")
        print(i+1,j,"は未訪問なので、下の座標データを確認する")
        print(res,"と(",i+1,j,")の座標の値",a[i+1][j],"から(",i+1,j,")の計算から得られた値の大きい方を求める")
        saiki_flag.append(saiki_counter)
        saiki_counter += 1
        input("再帰前-03")

        res = max(res, a[i+1][j]-f(i+1,j))

        print("◆",saiki_flag.pop(),"回目の呼び出しに対する応答")
        input("再帰後-04")
    memo[i][j] = res
    print(i,j,"の座標に",res,"を代入")
    for output_data in memo:
        print(output_data)
    input("-"*30)
    return res

#   if (visited[i][j]) return memo[i][j];
#   visited[i][j] = true;
#   int res = -INF;
#   if (j+1 < w) res = max(res, a[i][j+1]-f(i,j+1));
#   if (i+1 < h) res = max(res, a[i+1][j]-f(i+1,j));
#   return memo[i][j] = res;
# }

def main():
    global h
    global a
    global w

    h = 3
    w = 3
    a=[]
    temp_a=[]
    s = [["-","-","-"],["+","-","+"],["+","-","-"]]
    for temp_s in s:
        for inn_s in temp_s:
            if(inn_s=="-") :
                temp_data = -1
            else :
                temp_data = 1
            temp_a.append(temp_data)
        a.append(temp_a)
        temp_a = []
    for output_data in a:
        print(output_data)
    input("盤面")
    score = f(0,0)
    print(score)

if __name__ == '__main__':
    main()
#   int score = f(0,0);
#   if (score == 0) cout << "Draw" << endl;
#   if (score < 0) cout << "Aoki" << endl;
#   if (score > 0) cout << "Takahashi" << endl;
#   return 0;
# }
