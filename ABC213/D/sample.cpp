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
    constexpr mint &operator+=(const mint &a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
};

vvi to;
vi ans;

void dfs(int v, int p = -1)
{
    ans.push_back(v);
    for (int u : to[v])
    {
        if (u == p)
            continue;   // 無限ループに陥らないように親に戻らないようにする
        dfs(u, v);
        ans.push_back(v);
    }
}

int main()
{
    int n;
    cin >> n;
    to.resize(n);

    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        to[a-1].push_back(b-1);
        to[b-1].push_back(a-1);
    }

    // グラフを昇順に並べ替える
    rep(i, n) 
        sort(to[i].begin(), to[i].end());

    dfs(0);

    for (int v : ans)
        cout << v + 1 << " ";
    cout << endl;

    return EXIT_SUCCESS;
}
