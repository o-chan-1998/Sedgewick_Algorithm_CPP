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

void chmin(int& x, int y) { x = min(x,y);}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  const int INF = 1001001001;
  vvi dp(x+1, vi(y+1, INF));
  dp[0][0] = 0;
  rep(i,n) {
    int a, b;
    cin >> a >> b;

    vvi p(x+1, vi(y+1, INF));
    swap(dp,p);
    rep(j,x+1)rep(k,y+1) {
      chmin(dp[j][k], p[j][k]);
      chmin(dp[min(j+a,x)][min(k+b,y)], p[j][k]+1);
    }
  }

  int ans = dp[x][y];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}