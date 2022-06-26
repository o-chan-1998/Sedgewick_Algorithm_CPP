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

ll f(ll a, ll b) {
  return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// Aで調査しなければならない最大の桁数
	const int M = 1e6;
	ll n=9;
	ll ans = 1e18;
	ll b = M;
	
	// aは昇順に調査、bは降順に調査
	for (ll a = 0; a <= M; ++a) {
		while (b > 0 && f(a,b-1) >= n){
			--b;
		} 
		ans = min(ans, f(a,b));
	}
	cout << ans << endl;

    return EXIT_SUCCESS;
}

