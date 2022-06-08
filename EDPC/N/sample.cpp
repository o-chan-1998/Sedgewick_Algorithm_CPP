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

ll sum[440][440];
ll dp[440][440];
ll a[440];
ll n;

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int l = 0;l < n;l++){
        sum[l][l+1] = a[l];
        for(int r = l+2;r <= n;r++){
            sum[l][r] = sum[l][r-1] + a[r-1];
        }
    }
 
    for(int width = 2;width <= n;width++){
        for(int l = 0;l+width <= n;l++){
            int r = l + width;
            dp[l][r] = LINF;
            for(int m = l + 1;m < r;m++){
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r] + sum[l][r]); 
            }
        }
    }
    cout << dp[0][n] << endl;

    return EXIT_SUCCESS;
}
