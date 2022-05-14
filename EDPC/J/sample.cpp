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

ll n, a;
ll cnt[4];
double dp[330][330][330];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cnt[a]++;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int nonzero = i + j + k;
                if (nonzero == 0)
                {
                    dp[i][j][k] = 0;
                    continue;
                }
                dp[i][j][k] = (double)n / nonzero;
                if (i - 1 >= 0)
                    dp[i][j][k] += dp[i - 1][j + 1][k] * i / nonzero;
                if (j - 1 >= 0)
                    dp[i][j][k] += dp[i][j - 1][k + 1] * j / nonzero;
                if (k - 1 >= 0)
                    dp[i][j][k] += dp[i][j][k - 1] * k / nonzero;
            }
        }
    }
    printf("%.10lf\n", dp[cnt[3]][cnt[2]][cnt[1]]);
    return 0;
}
