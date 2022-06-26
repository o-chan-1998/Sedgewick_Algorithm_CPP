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

	int n=5;
	vi a{3, 1, 4, 1, 5};
	vvi is(n+1);
	rep(i,n){
		is[a[i]].push_back(i);
	}
	int q=4;
	vvi query{{1,5,1},{2,4,3},{1,5,2},{1,3,3}};
	rep(qi,q) {
		int l=query[qi][0], r=query[qi][1], x=query[qi][2];
		--l; --r;
		auto f = [&](vector<int>& is, int r) {
			return upper_bound(is.begin(),is.end(),r)-is.begin();
		};
		int ans = f(is[x], r) - f(is[x], l-1);
		printf("%d\n", ans);
	}

    return EXIT_SUCCESS;
}

