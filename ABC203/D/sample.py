N,K=3,2
A=[[1,7,0],[5,8,11],[10,4,2]]

#達成できる中央値で二分探索
ng=-1
ok=10**9

while ok-ng!=1:
    ima=(ng+ok)//2
    print(ima)
    #imaが達成できるか？
    l=[[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if j==0 and A[i][j]<=ima:
                l[i][j]=1
            elif A[i][j]<=ima:
                l[i][j]=1+l[i][j-1]
            else:
                l[i][j]=l[i][j-1]
    for debug_data in l:
        print(debug_data)
    print("o"*30)

    # 縦方向の累積和
    for j in range(N):
        for i in range(1,N):
            l[i][j]+=l[i-1][j]
    for debug_data in l:
        print(debug_data)
    print("_"*30)

    # K*Kの区画を確認
    for i in range(K-1,N):
        for j in range(K-1,N):
            print(i,j,"の座標を探索")
            small=l[i][j]   
            print("l[",i,"][",j,"]の値は",small)
            if i!=K-1:
                print(i,"!=",K-1,"となる場合")
                small-=l[i-K][j]
            if j!=K-1:
                print(j,"!=",K-1,"となる場合")
                small-=l[i][j-K]
            if i!=K-1 and j!=K-1:
                small+=l[i-K][j-K]
            if small>=(K**2+1)//2:
                ok=ima
                break
        else:
            print("continue")
            continue
        break
    else:
        ng=ima
        print("ng:",ng)
    input("-"*30)
print(ok)
