from math import gcd

def a():
    # 二次元配列の要素表示
    for debug_data in visited:
        print(debug_data)
    
    # 二次元配列
    datadata = [[0 for i in range(3)] for j in range(3)]

def main():
    pass

import itertools
# 順列
#(1,2,3),(1,3,2),(2,1,3),(2,3,1),...,(3,2,1)
for seq in itertools.permutations(range(1,4)):
# 重複なしの組み合わせ
# (1,2,3),(1,2,4),...,(7,8,9)
for seq in itertools.combinations(range(1,10),3):
# 重複ありの組み合わせ
#(1,1,1),(1,1,2),...,(9,9,9)
for seq in itertools.combinations_with_replacement(range(1,10),3):
# 直積
#(1,1),(1,2),(1,3),(2,1),(2,2),...,(3,3)
for seq in itertools.product(range(1,4),range(1,4)):

if __name__ == '__main__':
    main()
