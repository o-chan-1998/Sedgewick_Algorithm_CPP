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

ll a[3300];
// l以上r未満の範囲を与えられた時、X-Yの最大値または最小値
ll dp[3300][3300];
ll n;

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	rep(i,n){
		cin >> a[i];
	}
	rep(i,n){
		dp[i][i] = 0;
	}

	rep1(width, n){
		for(int l=0;l+width<=n;l++){
			int r=l+width;
			if(width%2==n%2){
				dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
			}else{
				dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
			}
		}
	}

	cout << dp[0][n] << endl;

    return EXIT_SUCCESS;
}