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

struct UnionFind
{
    vector<int> parent, rank, cnt;

    UnionFind(int n) : parent(n), rank(n, 0), cnt(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    bool same(int v, int w)
    {
        return find(v) == find(w);
    }

    void unite(int v, int w)
    {
        v = find(v);
        w = find(w);

        if (v == w)
        {
            return;
        }

        if (rank[v] > rank[w])
        {
            parent[w] = v;
            cnt[v] += cnt[w];
        }
        else
        {
            parent[v] = w;
            cnt[w] += cnt[v];
            if (rank[v] == rank[w])
            {
                rank[w] += 1;
            }
        }
    }

    int count(int v)
    {
        return cnt[find(v)];
    }
};

UnionFind uf(200100);

int main()
{
    int N;
    cin >> N;

    vi A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    rep(i, N / 2)
    {
        if (A[i] != A[N - i - 1])
        {
            uf.unite(A[i], A[N - 1 - i]);
        }
    }

    int res = 0;

    rep1(i, 200000)
    {
        if (uf.find(i) == i)
        {
            res += uf.count(i) - 1;
        }
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}
