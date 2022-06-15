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

#define INF 1LL<<60

int n, W;
// [品物の数][価値✕品物の数]
ll dp[110][110000];
ll w[110], v[110];

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> W;
	rep1(i,n){
		cin >> w[i] >> v[i];
	}
	rep1(i,110000-1){
		dp[0][i] = INF;
	}

	rep1(i,n){
		rep(j,110000){
			dp[i][j] = dp[i-1][j];
			if(j-v[i]>=0){
				dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]]+w[i]);
			}
		}
	}

	int ans = 0;
	rep(v, 110000){
		if(dp[n][v]<=W){
			ans = max(ans, v);
		}
	}

	cout << ans << endl;

    return EXIT_SUCCESS;
}