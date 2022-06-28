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

int f(string s) {
  vector<int> a(10);
  for (char c : s) 
  	a[c-'0']++;
  int res = 0;
  for (int i = 1; i <= 9; ++i) {
    int x = 1;
    rep(j,a[i]) 
		x *= 10;
    res += x*i;
  }
  return res;
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 1,2,…,9 が表に書かれたカードがK枚ずつ、計2K枚のカードがあります。
	int k=2;

	// これらのカードをランダムにシャッフルして、高橋くんと青木くんにそれぞれ、4 枚を表向きに、1 枚を裏向きにして配りました。
	// 高橋くんに配られたカードが文字列 S として、青木くんに配られたカードが文字列 T として与えられます。
	// S,T は 5 文字の文字列で、先頭 4 文字は 1, 2, …, 9 からなり、表向きのカードに書かれた数を表します。 末尾 1 文字は # であり、裏向きのカードであることを表します。
	string s="1144#", t="2233#";

	// 5 枚の手札の点数を、c_iをその手札に含まれる i の枚数として、 i=∑(i=1to9)i×10^(c_i)で定義します。
	// 高橋くんが青木くんより点数の高い手札を持っていたら高橋くんの勝ちです。
	// 高橋くんの勝つ確率を求めてください。
	vector<int> c(10,k);	// 各カードの残り枚数を格納する変数。kで初期化
	c[0] = 0;
	rep(i,4) 
		c[s[i]-'0']--;
	rep(i,4) 
		c[t[i]-'0']--;
	ll cnt = 0, tot = 0;

	// 伏せられた#の数字を検証していく(高橋くん)
	for (int a = 1; a <= 9; ++a) {
		s[4] = '0'+a;
		ll ca = c[a];
		c[a]--;
		// 伏せられた#の数字を検証していく(青木くん)
		for (int b = 1; b <= 9; ++b) {
			t[4] = '0'+b;
			ll now = ca*c[b];
			tot += now;
			if (f(s) > f(t)) 
				cnt += now;
		}
		c[a]++;
	}
	double ans = (double)cnt/tot;
	printf("%.10f\n", ans);

    return EXIT_SUCCESS;
}

