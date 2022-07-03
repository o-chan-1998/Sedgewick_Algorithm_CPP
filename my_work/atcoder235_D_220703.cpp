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

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 正の整数 a があります。
	// また、黒板に 1 個の数が 10 進表記で書かれています。

	// 黒板に現在書かれている数を x としたとき、高橋君は次のいずれかの操作を行い、黒板に書かれている数を変化させることができます。
	// ・x を消し、 x を a 倍した数を 10 進表記で新たに書きこむ。
	// ・x を文字列とみなして、列の末尾の数字を文字列の先頭に移動させる。
	//   ただし、この操作は x≥10 かつ x が 10 で割り切れないときにしか行えない。
	// たとえば a=2,x=123 であるとき、高橋君は次のいずれかの操作を行うことができます。

	// ・x を消して、 x✕a=123✕2=246 を新たに書きこむ。
	// ・x を文字列とみなして、123 の末尾の数字である 3 を先頭に移動させる。
	//   黒板に書かれている数は 123 から 312 に変化する。

	// はじめ、黒板には 1 が書かれています。
	// 書かれている数を N に変化させるには最小で何回の操作が必要ですか？ただし、どのように操作しても書かれている数を N に変化させられない場合は −1 を出力してください。

	int a=3, n=72;

	const int MX = 1000000;
	const int INF = 1001001001;
	vector<int> dist(MX, INF);
	
	queue<int> q;
	auto push = [&](int v, int d) {
		if (dist[v] != INF) 
			return;
		dist[v] = d;
		q.push(v);
	};
	push(1,0);
	
	while (!q.empty()) {
		int v = q.front(); q.pop();
		int d = dist[v];
		if (ll(v)*a < MX) 
			push(v*a, d+1);
		if (v >= 10 && v%10 != 0) {
			string s = to_string(v);
			int len = s.size();
			rotate(s.begin(), s.begin()+(len-1), s.end());
			int u = stoi(s);
			push(u, d+1);
		}
	}

	if (dist[n] == INF) 
		cout << -1 << endl;
	else 
		cout << dist[n] << endl;

    return EXIT_SUCCESS;
}

