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

	const int M = 1e6;

	// 素数表の作成
	vector<bool> isP(M+1, true);
	vector<int> primes;
	isP[0] = isP[1] = false;	// 0と1は素数ではない
	for (int i = 2; i <= M; ++i) {
		if (!isP[i]) continue;
		primes.push_back(i);
		for (ll j = (ll)i*i; j <= M; j += i) {
		isP[j] = false;
		}
	}

	vector<int> s(M+1);
	for (int p : primes) {
		s[p] = 1;
	}
	// 累積和
	rep(i,M){
		s[i+1] += s[i];
	} 

	ll n=250;
	ll ans = 0;
	for (int q : primes) {
		int r = min<ll>(n/q/q/q, q-1);
		ans += s[r];
	}
	cout << ans << endl;

    return EXIT_SUCCESS;
}

