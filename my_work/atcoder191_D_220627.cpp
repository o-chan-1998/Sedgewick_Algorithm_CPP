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

// 小数を整数として扱う
int in(double x) {
  x *= 10000;
  return round(x);
}

bool ok(ll dx, ll dy, ll z) {
  return dx*dx+dy*dy <= z*z;
}

ll f(ll x, ll y, ll z, ll lim) {
  int l = 0, r = 1;
  ll res = 0;
  for (int i = int(1e9)+50000; i >= lim; i -= 10000) {
    while (ok(x-l*10000,i-y,z)) --l;
    while (ok(r*10000-x,i-y,z)) ++r;
    res += r-l-1;
  }
  return res;
}


int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll x = in(0.2);
	ll y = in(0.8);
	ll z = in(1.1);
	x %= 10000;
	y %= 10000;
	ll ans = f(x,y,z,10000);	// 上半分
	ans += f(x,-y,z,0);			// 下半分
	cout << ans << endl;

    return EXIT_SUCCESS;
}

