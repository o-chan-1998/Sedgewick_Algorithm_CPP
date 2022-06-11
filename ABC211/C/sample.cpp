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

struct frac{
	ll a, b;
	frac(ll _a = 0, ll _b = 1) : a(_a), b(_b){
		// 0除算のときはa=1, b=0を返す
		if (b == 0){
			a = 1;
			return;
		}
		// 分母が1以上になるように正規化する
		if (b < 0){	
			a = -a;
			b = -b;
		}
		ll g = gcd(abs(a), b);  // g++ -std=c++17 sample.cpp
		a /= g;
		b /= g;
	}
	bool operator<(const frac &x) const{
		return a * x.b < x.a * b;
	}
};

int main(){
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n){
		cin >> x[i] >> y[i];
	}

	set<frac> st;
	rep(i, n){
		rep(j, i){
			st.insert(frac(x[i] - x[j], y[i] - y[j]));
		}
	}
	cout << st.size() * 2 << endl;
	return 0;
}