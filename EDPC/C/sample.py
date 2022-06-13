def main():
    # N = int(input())
    # a = [[int(x) for x in input().split()] for i in range(N)]
    N = 7
    a = [[6,7,8],[8,8,3],[2,5,2],[7,8,6],[4,6,8],[2,3,4],[7,5,1]]
    dp_A = [0]*N
    dp_B = [0]*N
    dp_C = [0]*N
    dp_A[0] = a[0][0]
    dp_B[0] = a[0][1]
    dp_C[0] = a[0][2]
    print(dp_A[0],dp_B[0],dp_C[0])
    print("海で泳ぐときの幸福度\t\t",dp_A)
    print("山で虫取りをするときの幸福度\t",dp_B)
    print("家で宿題をするときの幸福度\t",dp_C)

    for i in range(1, N):
        print(i,"日目に海の幸福度【",a[i][0],"】、山に行く幸福度",a[i][1],"、宿題する幸福度",a[i][2])
        print(i,"日目に海へ行く場合の幸福度を考える。")
        print(dp_A)
        print(i-1,"日目に山へ行った場合の幸福度",dp_B[i-1],"に加えるか、",i-1,"日目に宿題をした時の幸福度", dp_C[i-1],"を加えるか最大にする方を選択する")
        if dp_B[i-1] + a[i][0] < dp_C[i-1] + a[i][0]:
            dp_A[i] = dp_C[i-1] + a[i][0]
        else:
            dp_A[i] = dp_B[i-1] + a[i][0]
        print(dp_A)
        input("-/"*15)

        print(i,"日目に海の幸福度",a[i][0],"、山に行く幸福度【",a[i][1],"】、宿題する幸福度",a[i][2])
        print(i,"日目に山に行く場合の幸福度を考える。")
        print(dp_B)
        print(i-1,"日目に海へ行った場合の幸福度",dp_A[i-1],"に加えるか、",i-1,"日目に宿題をした時の幸福度", dp_C[i-1],"を加えるか最大にする方を選択する")
        if dp_C[i-1] + a[i][1] < dp_A[i-1] + a[i][1]:
            dp_B[i] = dp_A[i-1] + a[i][1]
        else:
            dp_B[i] = dp_C[i-1] + a[i][1]
        print(dp_B)
        input("/_"*15)

        print(i,"日目に海の幸福度",a[i][0],"、山に行く幸福度",a[i][1],"、宿題する幸福度【",a[i][2],"】")
        print(i,"日目に宿題する場合の幸福度を考える。")
        print(dp_C)
        print(i-1,"日目に海へ行った場合の幸福度",dp_A[i-1],"に加えるか、",i-1,"日目に山へ行った場合の幸福度", dp_B[i-1],"を加えるか最大にする方を選択する")
        if dp_B[i-1] + a[i][2] < dp_A[i-1] + a[i][2]:
            dp_C[i] = dp_A[i-1] + a[i][2]
        else:
            dp_C[i] = dp_B[i-1] + a[i][2]
        print(dp_C)
        input("-"*30)
        print(dp_A)
        print(dp_B)
        print(dp_C)
        input("."*30)

    print(max(dp_A[N-1], dp_B[N-1], dp_C[N-1]))


if __name__ == '__main__':
    main()
