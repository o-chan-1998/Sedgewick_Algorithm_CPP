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
using vvll = vv<ll>;

#define MOD 1000000007

int h, w;
string field[1100];
ll dp[1100][1100];

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> field[i];

    dp[h - 1][w - 1] = 1;

    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            if (i == h - 1 && j == w - 1)
                continue;
            dp[i][j] = 0;
            if (i + 1 < h)
                dp[i][j] += dp[i + 1][j];
            if (j + 1 < w)
                dp[i][j] += dp[i][j + 1];
            dp[i][j] %= MOD;
            if (field[i][j] == '#')
                dp[i][j] = 0;
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}