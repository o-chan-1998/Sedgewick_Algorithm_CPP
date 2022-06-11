# Dr_pilot
from math import gcd


def main():
    # n=int(input())
    n = 3

    magic = set()

    city = []

    # for _ in range(n):
    #     x,y=map(int,input().split())
    for x, y in zip([1, 2, 4], [2, 2, 2]):
        city.append([x, y])

    for i in range(n):
        for j in range(i):
            diffx = city[i][0]-city[j][0]
            diffy = city[i][1]-city[j][1]

            if diffx == 0:  # 縦のみの動き
                if diffy > 0:
                    magic.add((0, 1))
                elif diffy < 0:
                    magic.add((0, -1))

            elif diffy == 0:  # 横のみの動き
                if diffx > 0:
                    magic.add((1, 0))
                elif diffx < 0:
                    magic.add((-1, 0))

            else:
                # 傾きの最大公約数を求める
                num = gcd(diffx, diffy)
                diffx //= num   # 単位長にする
                diffy //= num   # 単位長にする
                magic.add((diffx, diffy))

    print(len(magic)*2)


if __name__ == '__main__':
    main()
