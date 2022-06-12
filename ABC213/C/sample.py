from math import gcd


def main():
    # 入力の受け取り
    # H,W,N=map(int, input().split())
    H, W, N = 4, 5, 2

    # カードの[行番号,列番号]受け取り用リスト
    cards = []
    # 行番号だけ受け取るリスト
    gyou = []
    # 列番号だけ受け取るリスト
    retu = []

    # i=0～Nまで
    # for i in range(N):
    #     # 入力の受け取り
    #     A, B = map(int, input().split())
    for A, B in [[3,2],[2,5]]:
        # カードの[行番号,列番号]を受け取り
        cards.append([A, B])
        # 行番号を受け取り
        gyou.append(A)
        # 列番号を受け取り
        retu.append(B)

    # 重複の削除(setにする)
    gyou = set(gyou)
    # リストに直す
    gyou = list(gyou)
    # ソートする
    gyou.sort()

    # 変換先を記録する連想配列(conv=convert)
    gyou_conv = dict()

    # 重複削除後の行の個数分
    for i in range(len(gyou)):
        # もとの行番号→インデックス番号+1と変換できるように記録(小さい方から何番目にあるか？)
        gyou_conv[gyou[i]] = i+1

    # 列も同じことをする
    retu = set(retu)
    retu = list(retu)
    retu.sort()

    retu_conv = dict()

    for i in range(len(retu)):
        retu_conv[retu[i]] = i+1

    # それぞれのカードについて行、列番号を変換して出力
    for gyou, retu in cards:
        # 行の変換
        ans_gyou = gyou_conv[gyou]
        # れつの変換
        ans_retu = retu_conv[retu]
        # 答えを出力する
        print(ans_gyou, ans_retu)


if __name__ == '__main__':
    main()
