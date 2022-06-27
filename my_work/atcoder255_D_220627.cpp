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

	int n=5, q=3;

	vector<int> a{6, 11, 2, 5, 5};

	// 与えられた数列を昇順に整列

	sort(a.begin(), a.end());
	
	// 累積和
	vector<ll> s(n+1);
	rep(i,n) {
		s[i+1] = s[i]+a[i];
	}

	vi qq{5,20,0};
	rep(qi,q) {
		int x = qq[qi];
		int k = lower_bound(a.begin(), a.end(), x)-a.begin();

		ll ans = (ll)k*x - s[k];

		// s[n]-s[k]はx以上の要素数の和
		// n-kはx以上の要素数
		ans += (s[n]-s[k]) - ll(n-k)*x;
		cout << ans << '\n';
	}

    return EXIT_SUCCESS;
}
