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

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string x="22";
	ll m=10;
	if (x.size() == 1) {
		if (stoi(x) <= m) 
			cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}

	int d = 0;
	for (char c : x) 
		d = max(d, int(c-'0'));
	ll ac = d, wa = m+1;

	// 二分探索
	while (wa-ac > 1) {
		ll wj = (ac+wa)/2;
		ll v = 0;
		for (char c : x) {
			if (v > m/wj) 
				v = m+1;
			else 
				v = v*wj + (c-'0');
		}
		if (v <= m) 
			ac = wj; 
		else 
		wa = wj;
	}
	cout << ac-d << endl;

    return EXIT_SUCCESS;
}
