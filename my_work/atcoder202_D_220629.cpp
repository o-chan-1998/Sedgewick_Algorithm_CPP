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
#include <complex>

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
using C = complex<double>;

ll c[61][61];

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// A 個の a と B 個の b からなる長さ A+B の文字列のうち、辞書順で K 番目のものを求めてください。
	int a=2, b=2;
	ll k=4;

	c[0][0] = 1;

	// パスカルの三角形
	rep(i,60) {
		rep(j,i+1) {
		c[i+1][j] += c[i][j];
		c[i+1][j+1] += c[i][j];
		}
	}

	string ans;
	while (a+b > 0) {
		ll x = 0;

		// Combination計算(計算結果の値を取得)
		if (a >= 1) 
			x = c[a+b-1][a-1];
		
		if (k <= x) {
			ans += 'a';
			--a;
		} else {
			ans += 'b';
			--b;
			k -= x;
		}
	}
	cout << ans << endl;

    return EXIT_SUCCESS;
}

