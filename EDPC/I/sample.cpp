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

double dp[3300][3300];
int n;
double p[3300];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j] * (1 - p[i]);
            if (j - 1 >= 0)
                dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
    }

    double ans;
    for (int i = 0; i <= n; i++)
    {
        if (i > n - i)
            ans += dp[n][i];
    }
    printf("%.15lf\n", ans);

    return 0;
}