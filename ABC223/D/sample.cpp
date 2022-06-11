#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <bitset>
#include <numeric> // iota関数
#include <fstream>

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

int main()
{
    // IO高速化のおまじない
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    vector<int> deg(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        // indexの調整
        a--;
        b--;
        // aの後ろに現れる値(b)を追加していく
        to[a].push_back(b);
        // 頂点bの入次数を加算
        deg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;

    // Directed Acyclic Graph問題では入次数が0の頂点が存在するので、順に取っていく。
    rep(i, n){
        if (deg[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;

    // 順序ありキューに溜まったサイズ分ループする
    while (q.size()){
        int v = q.top();
        q.pop();
        ans.push_back(v);
        for (int u : to[v]){
            deg[u]--;
            if (deg[u] == 0){
                q.push(u);
            }
        }
    }

    //   解が存在するのはans変数の数が、標準入力nと一致した場合
    if (ans.size() != n){
        cout << -1 << endl;
    }
    else{
        for (int v : ans){
            cout << v + 1 << endl;
        }
    }

    return EXIT_SUCCESS;
}