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

	string s;
	int q;
	cin >> s >> q;
	
	rep(qi,q) {
		ll t, k;
		cin >> t >> k;
		k--;
		int si = 0;
		// 2^60>10^18(tがある程度小さい時は分母を計算する)
		if (t <= 60) {
			ll b = 1ll<<t;
			si = k/b;
			k %= b;
		}
		// 右に行く回数
		// __builtin_popcountll()
		ll r = __builtin_popcountll(k);
		// 左に行く回数
		ll l = t-r;
		ll x = l + r*2 + (s[si]-'A');
		char ans = 'A'+(x%3);
		cout << ans << endl;
	}

    return EXIT_SUCCESS;
}