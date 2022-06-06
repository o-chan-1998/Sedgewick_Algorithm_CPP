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

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	// n : aの次数
	// m : bの次数
	// n+m : cの次数
	cin >> n >> m;
	vi a(n+1), c(n+m+1);
	vi b(m+1);
	rep(i,n+1){
		// aの次数を標準入力
		cin >> a[i];
	}
	rep(i,n+m+1){
		// cの次数を標準入力
		cin >> c[i];
	}
	drep(i,m+1){
		// bの最高位から順に求める
		// cの最高位÷aの最高位
		b[i] = c[n+i]/a[n];
		// 筆算の次数下げ
		rep(j,n+1){
			c[i+j] -= a[j]*b[i];
		}
	}
	rep(i,m+1){
		cout << b[i] << endl;
	}

    return EXIT_SUCCESS;
}