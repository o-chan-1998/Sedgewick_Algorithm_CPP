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

using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (int i = 1; i <= N; i++)
#define drep(i, N) for (int i = N - 1; i >= 0; i--)
#define srep(i, S, T) for (int i = S; i < T; i++)
#define rng(a) a.begin(), a.end()
#define MAX 210

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

int main()
{
    int N;
    cin >> N;
    bitset<100001> dp;

    dp[0] = 1;

    int tot = 0;
    rep(i, N)
    {
        int t;
        cin >> t;
        tot += t;
        dp |= dp << t; // 動的更新
    }
    int ans = tot;  // シリアルに進めた場合の時間
    rep(i, tot + 1)
    {
        if (dp[i])
        {
            ans = min(ans, max(i, (tot - i)));
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}
