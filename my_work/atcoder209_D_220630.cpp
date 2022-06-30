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

vi dep;
vvi to;

// 幅優先探索(葉,幅,親)
void dfs(int v, int _dep=0, int p=-1) {
  dep[v] = _dep;
  for (int u : to[v]) {
    if (u == p) 
		continue;
    dfs(u, _dep+1, v);
  }
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 高橋王国はN個の街とN−1本の道路からなり、街には1からNの番号がついています。
	// また、i(1≤i≤N−1)本目の道路は街aiと街biを双方向に結んでおり、どの街からどの街へもいくつかの道路を通ることで移動できます。
	// 道路は全て同じ長さです。
	// Q個のクエリが与えられます。
	// i(1≤i≤Q)番目のクエリでは整数ci,diが与えられるので、以下の問題を解いてください。
	// ・現在高橋君は街ciに、青木君は街diにいる。
	// 二人が同時に街を出発し、それぞれ街di,ciを目指して同じ速さで移動するとき、二人が街で出会うか道路上（両端の街を除く）で出会うかを判定せよ。
	// ただし、二人とも最短経路で移動し、街の中を移動する時間は無視できるものとする。
	int n=5, q=2;
	to.resize(n);
	vi aa={1,2,3,4};
	vi bb={2,3,4,5};
	
	rep(i,n-1) {
		int a=aa[i], b=bb[i];
		a--; 
		b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	dep.resize(n);
	dfs(0);

	vi cc={1,1};
	vi dd={3,5};
	rep(qi,q) {
		int c=cc[qi], d=dd[qi];
		c--; 
		d--;
		int ans = (dep[c]+dep[d])%2;
		if (ans == 0) 
			cout << "Town" << endl;
		else 
			cout << "Road" << endl;
	}

    return EXIT_SUCCESS;
}

