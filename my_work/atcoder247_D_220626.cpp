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

	ll Q = 4;

	deque<ll> X;
	deque<ll> C;

	vll qq{1,2,1,2};
	vll xx{2,-1,3,-1};
	vll cc{3,2,4,3};

	rep(i, Q) {
		ll q = qq[i];
		if (q == 1) {
			ll x = xx[i], c = cc[i];
			X.emplace_back(x);
			C.emplace_back(c);
		}
		else if (q == 2) {
			ll c = cc[i];
			ll sum = 0;
			while (c - C[0] >= 0) {
				sum += X[0] * C[0];
				c -= C[0];
				C.pop_front();
				X.pop_front();

				if (C.size() == 0)
					break;
			}
			if (c > 0) {
				sum += X[0] * c;
				C[0] -= c;
			}
			cout << sum << endl;
		}
	}

    return EXIT_SUCCESS;
}
