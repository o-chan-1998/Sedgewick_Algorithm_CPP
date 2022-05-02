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

vll depth;
vvi edge;

void dfs(int, int, int);

int main()
{
    int N, Q;
    cin >> N >> Q;
    depth.resize(N, 0); // 大きさを設定し、0で初期化
    edge.resize(N);

    rep(i, N - 1) // 1行目はN,Q値なので、実質N-1個がA, Bの値
    {
        int A, B;
        cin >> A >> B;
        edge[A - 1].push_back(B - 1);
        edge[B - 1].push_back(A - 1);
    }

    dfs(0, -1, 0);

    rep(i, Q)
    {
        int C, D;
        cin >> C >> D;
        if ((depth[C - 1] + depth[D - 1]) % 2 == 0)
        { // 深さの和が偶数
            cout << "Town" << endl;
        }
        else
        {
            cout << "Road" << endl;
        }
    }

    return EXIT_SUCCESS;
}

void dfs(int now, int par, int d)
{
    depth[d] = now;
    for (int nextD : edge[now])
    {
        if (nextD == par)
        {
            continue; // 次の要素が親の場合はスキップ
        }
        dfs(nextD, now, d + 1); // 要素(edge)がなくなるまで再帰(深さ+1)
    }
    return;
}
