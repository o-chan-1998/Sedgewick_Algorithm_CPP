#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <climits>
#include <bitset>
#include <numeric> // iota関数

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

const int MAXN=1005;
ll a[MAXN][MAXN], pref[MAXN][MAXN][5], v[MAXN][MAXN][5];

int main()
{
    int H, W;
    ll c;
    cin >> H >> W >> c;
    rep1(i,H)
    {
        rep1(j,W){
            cin >> a[i][j]; // 標準入力
        }
    }

    // 最適値配列
    rep(i,MAXN)
    {
        rep(j,MAXN)
        {
            rep(k,5)
                pref[i][j][k] = 1e18;
        }
    }

    // 
    rep1(i,H)
    {
        rep1(j,W)
        {
            v[i][j][1] = a[i][j] - c * i - c * j;
            v[i][j][2] = a[i][j] - c * i + c * j;
            v[i][j][3] = a[i][j] + c * i - c * j;
            v[i][j][4] = a[i][j] + c * i + c * j;
        }
    }

    // パターン1
    rep1(i,H)
    {
        rep1(j,W)
        {
            pref[i][j][1] = min(pref[i - 1][j][1], min(pref[i][j - 1][1], v[i][j][1]));
        }
    }

    // パターン2
    rep1(i,H)
    {
        drep1(j,W)
        {
            pref[i][j][2] = min(pref[i - 1][j][2], min(pref[i][j + 1][2], v[i][j][2]));
        }
    }

    // パターン3
    drep1(i,H)
    {
        rep1(j,W)
        {
            pref[i][j][3] = min(pref[i + 1][j][3], min(pref[i][j - 1][3], v[i][j][3]));
        }
    }

    // パターン4
    drep1(i,H)
    {
        drep1(j,W)
        {
            pref[i][j][4] = min(pref[i + 1][j][4], min(pref[i][j + 1][4], v[i][j][4]));
        }
    }

    ll ans = 1e18;
    rep1(i,H)
    {
        rep1(j,W)
        {
            ans = min(ans, v[i][j][4] + min(pref[i][j - 1][1], pref[i - 1][j][1]));
            ans = min(ans, v[i][j][3] + min(pref[i][j + 1][2], pref[i - 1][j][2]));
            ans = min(ans, v[i][j][2] + min(pref[i][j - 1][3], pref[i + 1][j][3]));
            ans = min(ans, v[i][j][1] + min(pref[i][j + 1][4], pref[i + 1][j][4]));
        }
    }

    cout << ans << endl;
    
    return EXIT_SUCCESS;
}