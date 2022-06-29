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

const int INF = 1001001001;

int h, w;
int a[10][10];

bool visited[10][10];
int memo[10][10];

int f(int i, int j) {
	if (i == h-1 && j == w-1) 
		return 0;
	if (visited[i][j]) 
		return memo[i][j];
	visited[i][j] = true;
	int res = -INF;
	if (j+1 < w) 
		res = max(res, a[i][j+1]-f(i,j+1));
	if (i+1 < h) 
		res = max(res, a[i+1][j]-f(i+1,j));
	memo[i][j] = res;
  	return res;
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// H行W列のマス目があり、各マスは青マスまたは赤マスのどちらかです。
	// 上からi番目、左からj番目のマスは、Ai,jが+なら青マスであり、-なら赤マスです。
	// 最初、このマス目の一番左上のマスに一つ駒が置かれていて、高橋君と青木君はこの駒を使ってゲームをします。
	// 2人の得点は最初0点ずつです。
	// 2人は、高橋君から始めて交互に次の操作をします。
	// ・駒を一つ右または一つ下のマスに動かす。  
	//   ただし、駒がマス目の外に出るような動かし方はできない。
	//   動かした人は、駒の移動後のマスが青マスなら1点を得て、赤マスなら1点を失う。
	// どちらかが操作できなくなった時点でゲームは終了します。
	// ゲームの結果は、終了時の2人の得点が異なるならば得点の大きい方が勝ち、同じならば引き分けとなります。
	// 両者とも自分の勝敗が最適になるように行動したとき、ゲームの結果を求めてください。
	h = 3;
	w = 3;
	vector<string> s{"---","+-+","+--"};

	// +:青なので+1, -:赤なので-1に変換
	rep(i,h)
		rep(j,w) 
			a[i][j] = s[i][j]=='+' ? 1 : -1;

	int score = f(0,0);
	
	if (score == 0) 
		cout << "Draw" << endl;
	if (score < 0) 
		cout << "Aoki" << endl;
	if (score > 0) 
		cout << "Takahashi" << endl;

    return EXIT_SUCCESS;
}

