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

// N=2^20項からなる数列A=(A0,A1,…,AN−1)があります。
// はじめ、全ての要素は−1です。
// Q個のクエリを順番に処理してください。
// i(1≤i≤Q)個目のクエリはti=1またはti=2を満たす整数tiおよび整数xiで表され、内容は以下の通りです。
// ・ti=1のとき、以下の処理を順番に行う。
//   整数hをh=xiで定める。
//   AhmodN=−1である間、hの値を1増やすことを繰り返す。
//   この問題の制約下でこの操作が有限回で終了することは証明できる。
//   AhmodNの値をxiで書き換える。
// ・ti=2のとき、その時点でのAximodNの値を出力する。
// なお、整数a,bに対し、aをbで割った余りをamodbと表します。

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 1<<20;
	int q = 4;
	set<int> s;
	rep(i,n){
		s.insert(i);
	}
	vll a(n,-1);
	vector<pair<int, ll>> query={{1,1048577},{1,1},{2,2097153},{2,3}};

	rep(qi,q){
		int type = query[qi].first;
		ll x = query[qi].second;
		if(type==1){
			int i = x % n;
			auto it = s.lower_bound(i);
			if(it==s.end()){
				it = s.begin();
			}
			a[*it] = x;
			s.erase(it);
		}else{
			cout << a[x%n] << endl;
		}
	}

    return EXIT_SUCCESS;
}