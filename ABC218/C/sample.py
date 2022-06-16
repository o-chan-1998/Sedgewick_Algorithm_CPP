# #の個数を確認する関数
def count_sharp(X):
    # #の個数をカウントする変数
    count=0
    # 行0～Nまで
    for gyou in range(N):
        # 列0～Nまで
        for retu in range(N):
            # もしx[行番号][列番号]が#なら
            if X[gyou][retu]=="#":
                # カウントにプラス1
                count+=1
    # カウント数を返す
    return count

# 90度時計回りに回転する関数
def rotate(X):
    # 回転後のグリッド
    rotate_X=[["."]*N for i in range(N)]
    # 行0～Nまで
    for gyou in range(N):
        # 列0～Nまで
        for retu in range(N):
            # (行番号,列番号)→(列番号,(N-1)-行番号)
            rotate_X[retu][N-1-gyou]=X[gyou][retu]
    # 回転後のグリッドを返す
    return rotate_X

# 左上から探索して初めて#が出てくる行番号,列番号を返す関数
def first_sharp(X):
    # 行0～Nまで
    for gyou in range(N):
        # 列0～Nまで
        for retu in range(N):
            # もしx[行番号][列番号]が#なら
            if X[gyou][retu]=="#":
                # 行番号,列番号を返して終了
                return gyou,retu

# 下方向へmove_gyou,右方向へmove_retu平行移動する関数
def Translation(X,move_gyou,move_retu):
    # 平行移動後のグリッド
    move_X=[["."]*N for i in range(N)]
    # 行0～Nまで
    for gyou in range(N):
        # 列0～Nまで
        for retu in range(N):
            # 行番号+move_gyou,列番号+move_retuがグリッドの中にあれば
            if 0<=gyou+move_gyou<N and 0<=retu+move_retu<N:
                # (行番号,列番号)→(行番号+move_gyou,列番号+move_retu)
                move_X[gyou+move_gyou][retu+move_retu]=X[gyou][retu]
    # 平行移動後のグリッドを返す
    return move_X

# S,Tが一致しているか確認する関数
def check(S,T):
    # 行0～Nまで
    for gyou in range(N):
        # 列0～Nまで
        for retu in range(N):
            # もしS[gyou][retu]とT[gyou][retu]が一致しなければ
            if S[gyou][retu]!=T[gyou][retu]:
                # Falseを返して終了
                return False
    # 完全に一致していればTrueを返す
    return True

# 入力の受け取り
N=5
# S,Tを用意
S=[]
T=[]

# N行受け取り
for S_tmp in [".....","..#..",".###.",".....","....."]:
    # リストに変換
    S_tmp=list(S_tmp)
    # Sへ格納
    S.append(S_tmp)

# N行受け取り
for T_tmp in [".....",".....","....#","...##","....#"]:
    # リストに変換
    T_tmp=list(T_tmp)
    # Tへ格納
    T.append(T_tmp)

# #の数が違う場合
if count_sharp(S)!=count_sharp(T):
    # Noを出力
    print("No")
    # 終了
    exit()

# 4回回転する(90→180→270→360(0))
for i in range(4):
    # Sを回転
    S=rotate(S)
    # S,Tの最初の#が出てくる行番号、列番号を確認
    S_first_gyou,S_first_retu=first_sharp(S)
    T_first_gyou,T_first_retu=first_sharp(T)

    # 行平行移動量=Tの最初の#が出てくる行番号-Sの最初の#が出てくる行番号
    move_gyou=T_first_gyou-S_first_gyou
    # 列平行移動量=Tの最初の#が出てくる列番号-Sの最初の#が出てくる列番号
    move_retu=T_first_retu-S_first_retu

    # Sを下方向へmove_gyou,右方向へmove_retu平行移動
    S_Trans=Translation(S,move_gyou,move_retu)

    # 一致しているかチェック
    if check(S_Trans,T)==True:
        # 一致していたらYesを出力
        print("Yes")
        # 終了
        exit()

# 4回転試して一致しなければNoを出力
print("No")