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

int h, w;
bool used[16][16];

ll dfs(int i, int j, int a, int b) {
	if (a < 0 || b < 0) 
		return 0;
	if (j == w) 
		j = 0, ++i;
	if (i == h) 
		return 1;
	if (used[i][j]) 
		return dfs(i, j+1, a, b);
	ll res = 0;
	used[i][j] = true;
	res += dfs(i, j+1, a, b-1);
	if (j+1 < w && !used[i][j+1]) {
		used[i][j+1] = true;
		res += dfs(i, j+1, a-1, b);
		used[i][j+1] = false;
	}
	if (i+1 < h && !used[i+1][j]) {
		used[i+1][j] = true;
		res += dfs(i, j+1, a-1, b);
		used[i+1][j] = false;
	}
	used[i][j] = false;
	return res;
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 縦 H メートル、横 W メートルの長方形の部屋があります。
	h = 3;
	w = 3;

	// この部屋に 2 メートル × 1 メートルの区別できない畳 (長方形のタイル) A 枚と、1 メートル × 1 メートルの区別できない半畳 (正方形のタイル) B 枚を敷き詰めます。
	// 2 メートル × 1 メートルの畳は縦長にも横長にも使うことができます。
	// 敷き詰める方法は何通りあるでしょうか？
	// なお、2A+B=HW であることが保証されます。 また、回転や反転を行うことで初めて一致するような敷き詰め方は区別します。
	int a = 4, b = 1;

	cout << dfs(0,0,a,b) << endl;

    return EXIT_SUCCESS;
}
