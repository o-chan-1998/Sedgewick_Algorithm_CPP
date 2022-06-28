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
#include <complex>

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
using C = complex<double>;

int n;
vvi to;

vi used, col;
vi vs;
void dfs(int v) {
  if (used[v]) 
  	return;
  used[v] = 1;
  vs.push_back(v);
  for (int u : to[v]) 
  	dfs(u);
}

ll now;
void dfs2(int i) {
	if (i == vs.size()) { 
		now++; 
		return;
	}
	int v = vs[i];
	rep(c,3) {
		col[v] = c;
		bool ok = true;
		for (int u : to[v]) {
			if (col[u] == c) 
				ok = false;
		}
		if (!ok) 
			continue;
		dfs2(i+1);
	}
	col[v] = -1;
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// N 頂点 M 辺の単純無向グラフがあります。
	// 頂点には 1 から N までの、辺には 1 から M までの番号がついています。
	n = 3;
	int m = 3;

	// 辺 i は頂点 Aiと頂点 Bi を結んでいます。
	// このグラフの各頂点を赤、緑、青の 3 色のいずれかで塗る方法であって、以下の条件を満たすものの数を求めてください。
	// ・辺で直接結ばれている 2 頂点は必ず異なる色で塗られている
	// なお、使われない色があっても構いません。
	to = vvi(n);
	vi aa = {1,2,3};
	vi bb = {2,3,1};
	// 連結グラフ作成のいつもの構文
	rep(i,m) {
		int a=aa[i], b=bb[i];
		a--;
		b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	ll ans = 1;
	used = vi(n);
	col = vi(n,-1);	// 色情報
	rep(i,n) {
		if (used[i]) 
			continue;
		ans *= 3;
		vs = vi();
		dfs(i);	// 幅優先探索
		int s = vs.size();
		col[vs[0]] = 0;
		now = 0;
		dfs2(1);
		ans *= now;
	}
	cout << ans << endl;

    return EXIT_SUCCESS;
}
