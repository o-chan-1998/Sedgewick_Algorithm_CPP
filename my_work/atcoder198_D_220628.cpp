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

	// 英小文字からなる文字列S1​,S2​,S3​が与えられます。
	// 覆面算S1​+S2​=S3​を解いてください。
	vector<string> s(3);
	s[0]="abcd";
	s[1]="efgh";
	s[2]="ijkl";

	// 正確には、次の3つの条件をすべて満たすような正の整数の組N1​,N2​,N3​が存在するか判定し、存在するならばそのうち1つを求めてください。
	// ここで、N1​,N2​,N3​を(先頭に余分な0をつけないで)十進表記した文字列をそれぞれN1'​,N2'​,N3'​とします。
	// ・Ni'​の文字数は、Si​の文字数に等しい
	// ・N1​+N2​=N3​を満たす
	// ・Si​のx文字目とSj​のy文字目が等しいとき、またその時に限り、Ni'​のx文字目とNj'​のy文字目が等しい
	map<char, ll> mp;
	set<char> heads;
	rep(i,3) {
		reverse(s[i].begin(), s[i].end());
		ll co = 1;
		if (i == 2) 
			co = -1;
		// 各桁を1,10,100,1000,...と変換
		for (char c : s[i]) {
			mp[c] += co;
			co *= 10;
		}
		reverse(s[i].begin(), s[i].end());
		heads.insert(s[i][0]);
	}

	if (mp.size() > 10) {
		cout << "UNSOLVABLE" << endl;
		return 0;
	}

	vector<int> p(10);
	iota(p.begin(), p.end(), 0);
	do {
		int i = 0;
		ll tot = 0;
		for (auto x : mp) {
			char c = x.first;
			ll co = x.second;
			if (p[i] == 0 && heads.count(c)) 
				tot = 1e18;
			tot += co*p[i];
			++i;
		}
		if (tot == 0) {
			i = 0;
			for (auto& x : mp) {
				x.second = p[i];
				++i;
			}
			rep(i,3) {
				ll x = 0;
				for (char c : s[i]) {
					x = x*10 + mp[c];
				}
				cout << x << endl;
			}
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));

	cout << "UNSOLVABLE" << endl;

    return EXIT_SUCCESS;
}

