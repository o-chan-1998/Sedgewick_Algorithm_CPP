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

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 記憶情報
	string s;
	cin >> s;
	
	int ans = 0;

	// 暗証番号4桁を総当り確認
	rep(num, 10000){
		vi a(10);
		int x = num;
		rep(i,4){
			int d = x%10;
			a[d] = 1;
			x /= 10;
		}
		bool ok = true;
		
		rep(i,10){
			// 記憶で正しいと判断しているのに1のフラグが入っていない
			if(s[i]=='o' && a[i]!=1){
				ok = false;
			}
			// 記憶で異なると判断しているのに0のフラグが入っていない
			if(s[i]=='x' && a[i]!=0){
				ok = false;
			}
		}
		if(ok){
			ans += 1;
		}
	}

	cout << ans << endl;

    return EXIT_SUCCESS;
}