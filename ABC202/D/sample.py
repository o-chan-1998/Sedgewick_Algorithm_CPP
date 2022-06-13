def main():
    C = [[0 for i in range(7)] for j in range(7)]
    for debug_data in C:
        print(debug_data)
        print("_"*30)
    C[0][0] = 1
    for i in range(5):
        for j in range(i+1):
            C[i+1][j] += C[i][j]
            for debug_data in C:
                print(debug_data)
            input("-"*30)
            C[i+1][j+1] += C[i][j]
            for debug_data in C:
                print(debug_data)
            input("*"*30)


if __name__ == '__main__':
    main()

    # C[0][0]=1;
    # rep(i,10){
    #     rep(j,i+1){
    #         C[i+1][j]+=C[i][j]; // パスカルの三角形イメージ
    #         C[i+1][j+1]+=C[i][j];   // パスカルの三角形イメージ
    #     }
    # }
