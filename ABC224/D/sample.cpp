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
	int n = 9;
	// 9 個の頂点と M 本の辺からなる無向グラフ、および、8 つのコマで構成される
	int m;
	cin >> m;
	
	// 頂点aと頂点bを連結
	vvi to(n);
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	// 駒の置き位置
	vi s(n, -1);
	rep(i, n - 1){
		int p;
		cin >> p;
		p--;
		// 駒pが、i番目に置かれている
		s[p] = i;
	}

	vi t(n, -1);
	rep(i, n - 1){
		t[i] = i;
	}

	// map変数とは、順序あり集合
	map<vi, int> dist;
	queue<vi> q;

	// 初期盤面
	dist[s] = 0;
	q.push(s);

	// 全盤面調査(BFS(幅優先探索)アルゴリズム)
	while (q.size()){
		s = q.front();
		q.pop();
		int d = dist[s];
		rep(v, n) {
			// -1が置かれている駒に対して操作を行う
			if (s[v] == -1){
				for (int u : to[v]){
					swap(s[u], s[v]);
					// 新しい盤面をキューに追加
					if (dist.find(s) == dist.end()){
						dist[s] = d + 1;
						q.push(s);
					}
					swap(s[u], s[v]);
				}
			}
		}
	}

	// 目標の盤面
	if (dist.find(t) == dist.end()){
		cout << -1 << endl;
	}
	else{
		cout << dist[t] << endl;
	}

    return EXIT_SUCCESS;
}