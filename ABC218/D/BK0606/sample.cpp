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

using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  set<P> s;
  rep(i,n) s.emplace(x[i],y[i]);
  int ans = 0;
  rep(i,n)rep(j,n) {
    int xi = x[i], xj = x[j];	// 対角点１を設定
    int yi = y[i], yj = y[j];	// 対角点２を設定
    if (xi < xj && yi < yj) {
      if (s.find(P(xi,yj)) == s.end()) continue;	// 対角点１のY座標が異なる位置情報があるか否か
      if (s.find(P(xj,yi)) == s.end()) continue;	// 対角点２のY座標が異なる位置情報があるか否か
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}