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

int n,n2;
vvi a;
int ans;

void dfs(vector<bool> s, int x){
  // 残っている中の先頭を求める
  int si = -1;

  rep(i,n2){
    // まだ使われていない場合
    if(!s[i]){
      si = i;
      break;
    }
  }

  if(si==-1){
    ans = max(ans, x);
    return;
  }

  s[si] = true;

  // siの相方を探す
  rep(i,n2){
    if(!s[i] && si != i){
      s[i] = true;
      dfs(s, x^a[si][i]);
      s[i] = false;
    }
  }
}

int main()
{
  // IO高速化のおまじない
  ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  cin >> n;
  n2 = n*2;

  // 相性表を作成
  a = vvi(n2, vi(n2));

  rep(i,n2){
    for(int j=i+1;j<n2;j++){
      cin >> a[i][j];
      // 相性表の対象表を作成する
      a[j][i] = a[i][j];
    }
  }

  vector<bool> s(n2);
  dfs(s, 0);

  cout << ans << endl;

  return EXIT_SUCCESS;
}