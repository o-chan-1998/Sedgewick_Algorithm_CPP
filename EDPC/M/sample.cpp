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

#define MOD 1000000007

int n, k;
ll dp[110][110000];
ll dp_sum[110][110000];
ll a[110];

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    // n:子供の数、k:飴の数
    cin >> n >> k;
    rep1(i,n){
        cin >> a[i];
    }
    dp[0][0] = 1;
    rep(j,k+1){
        dp_sum[0][j]=1;
    }
    rep1(i,n){
        rep(j,k+1){
            // i番目の人まで、j個の飴を分ける時の場合の数
            dp[i][j]=dp_sum[i-1][j];
            // a[i]各人が取って良い飴の数
            if(j-a[i]-1>=0){
                dp[i][j] -= dp_sum[i-1][j-a[i]-1];
            }
            if(j-1>=0){
                dp_sum[i][j] = dp_sum[i][j-1]+dp[i][j];
            }else{
                dp_sum[i][j] = dp[i][j];
            }
            dp[i][j] %= MOD;
            dp_sum[i][j] %= MOD;
        }
    }

    if(dp[n][k]<0){
        dp[n][k] += MOD;
    }
    cout << dp[n][k] << endl;

    return EXIT_SUCCESS;
}