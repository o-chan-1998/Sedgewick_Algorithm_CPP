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

ll dp[1 << 21];
ll n;
ll a[23][23];
ll bitcnt[1 << 21];

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }

    dp[0] = 1;
    for(int s=1; s<(1<<n); s++){
        bitcnt[s] = bitcnt[s/2]+s%2;
        rep(l,n){
            if((s>>l)%2==0){
                continue;
            }
            dp[s] += dp[s-(1<<l)]*a[bitcnt[s]-1][l];
            dp[s] %= MOD;
        }
    }

    cout << dp[(1<<n)-1] << endl;

    return EXIT_SUCCESS;
}