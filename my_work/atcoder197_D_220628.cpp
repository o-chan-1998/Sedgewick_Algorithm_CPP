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

C inC(double x, double y) {
  return C(x,y);
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// x 軸の正の向きを右、y 軸の正の向きを上とする 2 次元座標平面上に、p_0, p_1,p_2,…,pN−1 の N 個の頂点からなる正 N 角形があります。
	// ここで N は偶数であることが保証され、頂点 p0,p1,p2,...,pN-1はこの順に反時計回りに並んでいます。
	// pi の座標を (x_i,y_i) とします。
	// x0,y0 ,x_N/2,y_N/2が与えられるので、x1 ,y1を求めてください。
	int n=6;
	C s = inC(5,3);
	C t = inC(7,4);

	C o = (s+t)/2.0;	// 中心点
	double PI = acos(-1);
	double rad = 2*PI/n;
	C r(cos(rad), sin(rad));
	C ans = o + (s-o)*r;
	printf("%.10f %.10f\n", ans.real(), ans.imag());

    return EXIT_SUCCESS;
}


