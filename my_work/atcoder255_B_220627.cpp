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

	// n人いて、K番目の人に明かりを持たせる
	int n=4, k=2;
	vector<int> a{2,3};
	rep(i,k) a[i]--;	// インデックス調整
	vector<int> x{0,0,1,2}, y{0,1,2,0};

	vector<double> r(n);
	rep(i,n) {
		r[i] = 1e18;
		rep(j,k) {
			double dx = x[i]-x[a[j]];
			double dy = y[i]-y[a[j]];
			double dist = sqrt(dx*dx + dy*dy);	// 人同士のユークリッド距離
			r[i] = min(r[i], dist);	// 最も近い光源を配列に格納する
		}
	}

	double ans = 0;
	rep(i,n) {
		ans = max(ans, r[i]);
	}
	printf("%.10f\n", ans);

    return EXIT_SUCCESS;
}
