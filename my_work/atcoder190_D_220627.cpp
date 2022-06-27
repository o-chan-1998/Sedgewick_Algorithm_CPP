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

	// 整数からなる公差 1 の等差数列のうち、総和が N であるものはいくつあるでしょうか？
	ll n=12;

	ll n2 = n*2;
	int ans = 0;
	
	auto check = [&](ll l) {
		ll tmp = n2/l-l+1;
		if (abs(tmp)%2 == 0) 
			++ans;	// 2N/L-L+1が偶数であるのが必要条件
	};
	
	for (ll x = 1; x*x <= n2; x++) {
		if (n2%x) 
			continue;
		ll y = n2/x;
		check(x);
		if (x != y) 
			check(y);
	}
	cout << ans << endl;

    return EXIT_SUCCESS;
}
