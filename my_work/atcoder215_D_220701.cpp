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

	// 長さ N の正整数列 A=(A 1​ ,A 2​ ,…,A N​ ) が与えられるので、以下の条件を満たす 1 以上 M 以下の整数 k を全て求めてください。
	// 全ての 1≤i≤N を満たす整数 i について、 gcd(A i​ ,k)=1 である。
	int n=3, m=12;

	const int L = 100001;
	vector<bool> x(L);

	int aa[]={6,1,5};
	rep(i,n) {
		int a=aa[i];
		x[a] = true;
	}

	vector<int> d;
	// 素数表作成
	for (int i = 2; i < L; i++) {
		bool flag = false;
		for (int j = i; j < L; j += i) {
			if (x[j]) 
				flag = true;
		}
		// 正整数列に含まれる素数
		if (flag) 
			d.push_back(i);
	}

	vector<bool> ok(m+1, true);
	for (int i : d) {
		for (int j = i; j <= m; j += i) {
			ok[j] = false;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= m; ++i) 
		if (ok[i]) 
			cnt++;

	cout << cnt << endl;

	for (int i = 1; i <= m; ++i) 
		if (ok[i]) 
			cout << i << endl;

    return EXIT_SUCCESS;
}