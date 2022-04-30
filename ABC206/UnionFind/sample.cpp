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
using vll = vc<ll>;

class UnionFind
{
public:
    vll par; // 各元の親を表す配列
    vll siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1)
    {
        for (ll i = 0; i < sz_; ++i)
            par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_)
    {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (ll i = 0; i < sz_; ++i)
            par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x)
    { // 根の検索
        while (par[x] != x)
        {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y)
    { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x)
    { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main()
{
    // input(sunippets: inpv, inpn, inps)
    ll N, Q, P, A, B;
    cin >> N >> Q;
    UnionFind uf(N);

    // calculation
    rep(i, Q)
    {
        cin >> P >> A >> B;
        if (P == 0)
        {
            uf.merge(A, B);
        }
        else
        {
            if (uf.issame(A, B))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return EXIT_SUCCESS;
}
