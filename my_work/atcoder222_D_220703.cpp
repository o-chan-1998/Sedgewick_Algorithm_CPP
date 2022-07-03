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

const int mod = 998244353;
struct mint
{
	ll x; // typedef long long ll;
	mint(ll x = 0) : x((x % mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint &operator+=(const mint a)
	{
		if ((x += a.x) >= mod)
			x -= mod;
		return *this;
	}
	mint &operator-=(const mint a)
	{
		if ((x += mod - a.x) >= mod)
			x -= mod;
		return *this;
	}
	mint &operator*=(const mint a)
	{
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const
	{
		if (!t)
			return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1)
			a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint &operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};

int main()
{
	// IO高速化のおまじない
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 長さ n の数列 S=(s 1​ ,s 2​ ,…,s n​ ) がすべての i (1≤i≤n−1) に対して s i​ ≤s i+1​  を満たすとき、
	// かつそのときに限り「数列 S は広義単調増加である」と呼びます。
	// 広義単調増加な長さ N の整数列 A=(a 1​ ,a 2​ ,…,a N​ ),B=(b 1​ ,b 2​ ,…,b N​ ) が与えられます。
	// このとき、次の条件を満たす広義単調増加な長さ N の整数列 C=(c 1​ ,c 2​ ,…,c N​ ) を考えます。
	// すべての i (1≤i≤N) に対して a i​ ≤c i​ ≤b i​  が成り立つ。整数列 C としてあり得る数列の個数を
	// 998244353 で割ったあまりを求めてください

	int n=10;
	vector<int> a={1,2,3,4,5,6,7,8,9,10};
	vector<int> b={1,4,9,16,25,36,49,64,81,100};
	const int M = 3001;	// Nの最大値
	// DPテーブル
	// C_iまで決めて、C_i=jの場合の数
	vector<mint> dp(M);
	dp[0] = 1;
	rep(i, n){
		// 作業用DPテーブル
		vector<mint> p(M);
		swap(dp, p);
		// 高速化のための累積和
		rep(j, M - 1) 
			p[j + 1] += p[j];
		rep(j, M){
			// 数列A以上数列B以下の範囲の情報更新
			if (a[i] <= j && j <= b[i]){
				dp[j] += p[j];
			}
		}
	}
	mint ans;
	rep(i, M) 
		ans += dp[i];
	cout << ans.x << endl;

	return EXIT_SUCCESS;
}
