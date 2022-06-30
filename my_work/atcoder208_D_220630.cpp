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

	int n=5, m=20;
	const int INF = 1001001001;
	vvi table(n, vi(n, INF));
	
	rep(i,n) 
		table[i][i] = 0;

	int aa[m]={1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5};
	int bb[m]={2,3,4,5,1,3,4,5,1,2,4,5,1,2,3,5,1,2,3,4};
	int cc[m]={6,10,4,1,5,9,8,6,5,1,7,9,4,6,4,8,2,5,6,5};
	rep(i,m) {
		int a=aa[i], b=bb[i], c=cc[i];
		a--; 
		b--;
		table[a][b] = c;	// a行b列に重みcを代入
	}

	// ワーシャルフロイド法
	ll ans = 0;
	rep(k,n) {
		rep(i,n){
			rep(j,n) {
				table[i][j] = min(table[i][j], table[i][k]+table[k][j]);
				if (table[i][j] != INF)	
					ans += table[i][j];
			}
		}
	}

	cout << ans << endl;

    return EXIT_SUCCESS;
}
