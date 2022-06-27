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

//min(x,y)が0以下の場合はmax(x,y)が返される
//ユークリッドの互除法を元に実装
ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

//オーバフローしないようにかける順番を気を付ける
ll lcm(ll x,ll y){
    return ll(x/gcd(x,y))*y;
}

ll f(ll n) {
  return (1+n)*n/2;
}

ll f2(ll n, ll a) {
  return f(n/a)*a;
}

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n=10, a=3, b=5;
	ll ans = f(n);	// 1～nまでの総和
	ans -= f2(n,a);	// 3の倍数の総和
	ans -= f2(n,b);
	ans += f2(n,lcm(a,b));
	cout << ans << endl;

    return EXIT_SUCCESS;
}
