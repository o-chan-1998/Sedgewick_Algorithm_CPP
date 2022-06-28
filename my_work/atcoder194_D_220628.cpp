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

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 頂点 1 から頂点 N までの N 頂点からなるグラフの頂点 1 に高橋君がいます。
	// 今このグラフに辺は 1 つも張られていません。
	// 高橋君は以下の操作を繰り返します。
	// 操作 :
	// (今高橋君がいる頂点も含めた) N 個の頂点の中から 1 つランダムに選ぶ。各頂点が選ばれる確率は全て(1/N)であり、選択は操作毎に独立である。
	// 今高橋君がいる頂点と選ばれた頂点の間に無向辺を張り、選ばれた頂点に移動する。
	// グラフが連結になるまでに行われる操作の回数の期待値を求めてください。
	int n = 10;

	double ans = 0;
	for (int i = 1; i < n; ++i) {
		// 重複するのがi
		// 新しいものが出るのがn-i
		ans += (double)n / (n-i);
	}
	printf("%.10f\n", ans);

    return EXIT_SUCCESS;
}

