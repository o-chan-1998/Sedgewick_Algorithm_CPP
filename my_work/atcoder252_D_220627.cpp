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

ll dp[200005][4];

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n=4;
	map<int,int> cnt;
	vi a{3, 1, 4, 1};
	rep(i,n) {
		cnt[a[i]]++;
	}

	vector<int> c;
	for (auto p : cnt) {
		c.push_back(p.second);
	}

	int m = c.size();

	dp[0][0] = 1;
	rep(i,m) {
		rep(j,4) {
			dp[i+1][j] = dp[i][j];
			if (j) {
				dp[i+1][j] += dp[i][j-1]*c[i];
			}
		}
	}
	cout << dp[m][3] << endl;

    return EXIT_SUCCESS;
}

