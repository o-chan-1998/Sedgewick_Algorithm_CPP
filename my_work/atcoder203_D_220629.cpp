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

	// AtCoder公園の敷地は東西南北に広がるN×Nのマス目からなっており、北からi番目かつ西からj番目のマスの高さはAi,jで与えられます。
	// 公園の管理者である高橋君はここにK×Kの区画の池を作る事にしました。
	// 池を作るにあたって、高橋君はAtCoder公園の敷地内に完全に含まれるK×Kの区画であって
	// その区画に含まれるマスの高さの中央値が最も低いようなものを選ぼうと考えました。
	// そのような区画のマスの高さの中央値を求めてください。
	// ここで、K×Kの区画に含まれるマスの高さの中央値とはその区画に含まれるK^2個のマスのうち
	// [K^2]+1番目に高いマスの高さを指します。
	// また、[x]はx以下の最大の整数を表します。
	int n=3, k=2;
	vvi a{{1,7,0},{5,8,11},{10,4,2}};

	int L = k*k/2+1;

	int wa = -1, ac = 1001001001;
	while (wa+1 < ac) {
		int wj = (wa+ac)/2;
		bool ok = false;
		{
			vvi s(n+1, vi(n+1));
			rep(i,n)
				rep(j,n) 
					s[i+1][j+1] = a[i][j]>wj?1:0;
			rep(i,n+1)
				rep(j,n) 
					s[i][j+1] += s[i][j];
			rep(i,n)
				rep(j,n+1) 
					s[i+1][j] += s[i][j];
			rep(i,n-k+1)
				rep(j,n-k+1) {
					int now = s[i+k][j+k];
					now -= s[i][j+k];
					now -= s[i+k][j];
					now += s[i][j];
					if (now < L) 
						ok = true;
			}
		}
		if (ok) 
			ac = wj; 
		else 
			wa = wj;
	}
	cout << ac << endl;

    return EXIT_SUCCESS;
}

