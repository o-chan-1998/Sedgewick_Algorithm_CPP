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

ll my_gcd(ll a, ll b){
	ll m, n, k;
	m = a;
	n = b;
	do{
		k = m % n;
		m = n;
		n = k;
	}while(k != 0);

	return m;
}

struct frac{
	ll a, b;
	frac(ll _a=0, ll _b=1): a(_a), b(_b){
		if(b==0){	// 0除算の場合
			a = 1;
			return;
		}else if(b<0){
			a = -a;
			b = -b;
		}
		ll g = my_gcd(abs(a), b);
		a /= g;
		b /= g;
	}
	bool operator<(const frac& x) const{
		return a*x.b < x.b*b;
	}
};

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 3;
	vi x = {1,3,7};
	vi y = {2,6,4};

	set<frac> st;
	rep(i,n){
		rep(j,i){
			st.insert(frac(x[i]-x[j],y[i]-y[j]));
		}
	}

	cout << st.size()*2 << endl;

    return EXIT_SUCCESS;
}