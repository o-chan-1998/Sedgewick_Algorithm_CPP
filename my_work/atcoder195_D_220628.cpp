#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <bitset>
#include <numeric> // iota関数
#include <fstream>

using namespace std;

#define rep(i, H) for (int i = 0; i < H; i++)
#define rep1(i, H) for (int i = 1; i <= H; i++)
#define drep(i, H) for (int i = H - 1; i >= 0; i--)
#define drep1(i, H) for (int i = H; i >= 1; i--)
#define srep(i, S, T) for (int i = S; i < T; i++)
#define rng(a) a.begin(), a.end()

template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
template <typename T>
using vvv = vv<vc<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using vvvi = vvv<int>;
using vl = vc<long>;
using vvl = vv<long>;
using ll = long long;
using vll = vc<ll>;
using vvll = vv<ll>;

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 1 から N の番号がついた N 個の荷物と、1 から M の番号がついた M 個の箱があります。
	// 荷物 i の大きさは W_iで、価値は V_iです。
	// 箱 i には大きさが X_i以下の荷物を入れることができます。1 つの箱に 2 つ以上の荷物を入れることはできません。
	// Q 個のクエリが与えられます。各クエリでは 2 つの整数 L,R が与えられるので、次の問題を解いてください。

	// 問題：M 個の箱のうち、箱 L,L+1,…,R の R−L+1 個の箱が使えなくなってしまいました。 残りの箱の中に同時に入れることができる荷物の価値の合計の最大値を求めてください。

	// 解説だけでコードは未着手(22/06/28時点)

    return EXIT_SUCCESS;
}