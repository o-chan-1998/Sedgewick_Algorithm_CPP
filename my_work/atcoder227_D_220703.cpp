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

ll my_min(ll a, ll b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// キーエンスには N 個の部署があり、i(1≤i≤N) 番目の部署には A_i人の社員が所属しています。異なる部署に同じ社員が所属していることはありません。

	// キーエンスは、部署をまたいだ全社横断プロジェクトを計画しています。
	// 1 つのプロジェクトは K 個の相異なる部署から 1 人ずつ選出して作り、ちょうど K 人から構成されるようにします。

	// プロジェクトは最大でいくつ作れますか？
	// ただし、1 人が複数のプロジェクトに参加することはできません。

	int n=3, k=3;
	vi a={2,3,4};

	// 二分探索
	ll ac=0, wa=100;
	while(ac+1<wa){
		ll wj = (ac+wa)/2;
		ll s = 0;
		rep(i,n){
			s += my_min(a[i],wj);
		}
		// k人で構成されるプロジェクトが、wj組
		if(s >= k*wj){
			ac = wj;
		}else{
			wa = wj;
		}
	}

	cout << ac << endl;

    return EXIT_SUCCESS;
}