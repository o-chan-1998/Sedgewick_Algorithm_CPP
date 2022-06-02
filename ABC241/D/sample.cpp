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

	int q;
	cin >> q;

	// setだと重複する要素を持てないので、multisetのデータ構造を用いる
	multiset<ll> s;

	rep(qi, q){
		int type;
		ll x;
		cin >> type >> x;
		// type=1の時はxを追加する
		if(type==1){
			s.insert(x);
		}
		// それ以外のときはkを読み込む
		else{
			int k;
			cin >> k;
			ll ans = -1;
			// type!=1で、type=2の時
			if(type==2){
				// xより大きい
				auto it = s.upper_bound(x);
				bool ok = true;
				// k個戻る
				rep(i,k){
					// s.begine()だったらそれ以上戻れないのでbreak
					if(it==s.begin()){
						ok = false;
						break;
					}
					it--;
				}
				if(ok){
					ans = *it;
				}
			}else{
				// ギリギリの箇所を見つける
				// x以上
				auto it = s.lower_bound(x);
				bool ok = true;
				// k-1個分進める
				rep(i,k-1){
					// s.end()だったらそれ以上進めないのでbreak
					if(it==s.end()){
						ok = false;
						break;
					}
					it++;
				}
				if(ok && it != s.end()){
					ans = *it;
				}
			}
		cout << ans << endl;
		}
	}

    return EXIT_SUCCESS;
}