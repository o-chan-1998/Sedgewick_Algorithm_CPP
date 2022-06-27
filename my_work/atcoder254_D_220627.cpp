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

	int n=10;
	vector<int> f(n+1);
	rep(i,n+1) f[i] = i;
	for (int i = 2; i <= n; i++) {
		int x = i*i;
		if (x > n) 
			break;
		for (int j = x; j <= n; j += x) {
			while (f[j]%x == 0) {
				f[j] /= x;	// 平方数で割る
			}
		}
	}
	vector<int> c(n+1);
	for (int i = 1; i <= n; i++) 
		c[f[i]]++;
	ll ans = 0;
	rep(i,n+1) 
		ans += ll(c[i])*c[i];
	cout << ans << endl;

    return EXIT_SUCCESS;
}
