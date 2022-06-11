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

	// 双方向リストの問題
	// 電車は N 個あり、電車 1 、電車 2 、… 、電車 N と名前がついています
	// クエリが Q 個与えられるので、与えられた順番に処理してください。
	int n, q;
	cin >> n >> q;

	vi front(n, -1);
	vi back(n, -1);

	rep(qi, q){
		int type;
		cin >> type;
		// type = 3の場合
		// 電車 x が含まれる連結成分に属する電車の番号を、先頭から順番に全て出力する。
		if (type == 3){
			int x;
			cin >> x;
			x--;
			// 双方向リストの最前ポインタまで移動
			while (front[x] != -1){
				x = front[x];
			}
			vi ans = {x + 1};
			// 双方向リストの最後ポインタまで移動
			while (back[x] != -1){
				x = back[x];
				ans.push_back(x + 1);
			}
			cout << ans.size() << endl;
			rep(i, ans.size()) cout << ans[i] << ' ';
			cout << endl;
		}else{	// type = 3以外
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			// type = 1の場合
			// 電車 x の後部と、電車 y の前部を連結させる。
			if (type == 1){
				back[x] = y;	// Xの後ろがy
				front[y] = x;	// yの後ろがx
			}else{ // 電車 x の後部と、電車 y の前部を分離させる。
				back[x] = -1;	// 分断のため切り離す
				front[y] = -1;	// 分断のため切り離す
			}
		}
	}

    return EXIT_SUCCESS;
}