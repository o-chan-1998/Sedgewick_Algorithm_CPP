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

	// 	あるオンラインゲームがあり、N人のプレイヤーが登録しています。
	// サービス開始日から10^100日を迎えた今日、開発者である高橋君がログイン履歴を調べたところ、
	// i番目のプレイヤーはサービス開始日を1日目として、Ai​日目からBi​日間連続でログインし、
	// それ以外の日はログインしていなかったことが判明しました。
	// すなわち、i番目のプレイヤーはサービス開始日から、Ai​,Ai​+1,…,Ai​+Bi​−1日目に、かつそれらの日にのみログインしていたことが分かりました。
	// 1≤k≤Nをみたす各整数kについて、サービス開始日から今日までの間で、ちょうどk人がログインしていた日数を答えてください。

	int n=3;
	map<int,int> mp;
	int aa[]={1,2,3};
	int bb[]={2,3,1};
	
	rep(i,n) {
		int a=aa[i], b=bb[i];
		mp[a]++;
		mp[a+b]--;
	}
	int pre = -1, now = 0;
	vector<int> ans(n+1);
	for (auto x : mp) {
		ans[now] += x.first-pre;
		now += x.second;
		pre = x.first;
	}
	for (int i = 1; i <= n; ++i) 
		cout << ans[i] << endl;

    return EXIT_SUCCESS;
}

