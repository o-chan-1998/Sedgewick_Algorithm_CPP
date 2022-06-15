# 入力の受け取り(Kも文字列として)
S="baba"
# Kを整数に変換
K=4

# 作れる文字を格納するセット(リストだと重複するものも入ってしまうためセットを使う)
S_set=set()

# itertoolsをインポート
import itertools
# seq=(0,1,2),(0, 2, 1),(1, 0, 2),(1, 2, 0),...
for seq in itertools.permutations(range(len(S))):
    # 作った文字列を記録する変数
    S_tmp=""
    # seqを使って文字を作成
    # 例：seq=(2,0,1)ならS_tmp=Sの2文字目+Sの0文字目+Sの1文字目
    input(seq)
    for i in seq:
        S_tmp+=S[i]
    # できた文字をS_setに格納(setへの追加はappendではなくaddであることに注意)
    S_set.add(S_tmp)

# ソートするためにリストへ変換
S_list=list(S_set)

# 辞書順にソート
S_list.sort()

# K-1番目の要素を出力
print(S_list[K-1])