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

	// 1 以上 N 以下の整数からなる長さ N の数列 A=(A_1,A_2 ,…,A_N),B=(B_1,B_2,…,B_N),C=(C_1 ,C_2 ,…,C_N ) が与えられます。
	// 1 以上 N 以下の整数 i,j の組 (i,j) であって、A i =B C j   となるものの総数を求めてください。
	int n=3;
	vector<int> a{1,2,2}, b{3,1,2}, c{2,3,2};

	vector<int> cnt(n+1);
	rep(i,n) 
		cnt[a[i]]++;
	ll ans = 0;
	rep(j,n) 
		ans += cnt[b[c[j]-1]];

	cout << ans << endl;

    return EXIT_SUCCESS;
}

