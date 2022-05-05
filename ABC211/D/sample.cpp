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

constexpr int mod = 1000000007;
class mint
{
public:
    long long x;
    constexpr mint(long long x = 0) : x((x % mod + mod) % mod) {}
    constexpr mint operator-() const
    {
        return mint(-x);
    }
    constexpr mint &operator+=(const mint &a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    constexpr mint &operator-=(const mint &a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    constexpr mint &operator*=(const mint &a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    constexpr mint operator+(const mint &a) const
    {
        mint res(*this);
        return res += a;
    }
    constexpr mint operator-(const mint &a) const
    {
        mint res(*this);
        return res -= a;
    }
    constexpr mint operator*(const mint &a) const
    {
        mint res(*this);
        return res *= a;
    }
    constexpr mint pow(long long t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    constexpr mint inv() const
    {
        return pow(mod - 2);
    }
    constexpr mint &operator/=(const mint &a)
    {
        return (*this) *= a.inv();
    }
    constexpr mint operator/(const mint &a) const
    {
        mint res(*this);
        return res /= a;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vvi G(N);

    // グラフの読み込み(標準入力)
    rep(i, M)
    {
        int A, B;
        cin >> A >> B;
        G[A - 1].push_back(B - 1);
        G[B - 1].push_back(A - 1);
    }

    const int INF = INT_MAX;

    vi dist(N, INF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    vi vs;           // キューで取り出された経路を格納していく
    while (q.size()) // キューに値がある間ループする
    {
        int v = q.front();
        q.pop();
        vs.push_back(v);
        for (int u : G[v])
        {
            if (dist[u] != INF) // 深さが付いている場合はスキップ
                continue;
            dist[u] = dist[v] + 1; // 深さを+1
            q.push(u);             // キューを吐き出す
        }
    }

    // 距離が1の経路のみを数え上げていく
    vector<mint> dp(N);
    dp[0] = 1;
    for (int v : vs)
    {
        for (int u : G[v])
        {
            if (dist[u] == dist[v] + 1)
            {
                dp[u] += dp[v];
            }
        }
    }
    mint ans = dp[N - 1];
    cout << ans.x << endl;

    return EXIT_SUCCESS;
}