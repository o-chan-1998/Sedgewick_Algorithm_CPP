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

vi compress(vi &X){
	vi vals = X;
	sort(vals.begin(), vals.end());
	// ベクトルから要素を削除
	vals.erase(unique(vals.begin(),vals.end()), vals.end());
	rep(i,(int)X.size()){
		// lower_boundは、探索したいkey以上のイテレータ(コンテナ内での要素の位置を指すもので、 ポインタのように扱うことができ)を返す
		// upper_boundは、探索したいkeyより大きいイテレータを返す
		X[i] = lower_bound(vals.begin(),vals.end(),X[i])-vals.begin();
	}
	return vals;
}

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int h, w, n;
	cin >> h >> w >> n;
	vi a(n), b(n);
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	vi x = compress(a);
	vi y = compress(b);
	rep(i,n){
		cout << a[i]+1 << b[i]+1 << endl;
	}

    return EXIT_SUCCESS;
}