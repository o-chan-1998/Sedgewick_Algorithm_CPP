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

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> front(n, -1);
  vector<int> back(n, -1);
  rep(qi,q) {
    int type;
    cin >> type;
    if (type == 3) {
      int x;
      cin >> x;
      --x;
      while (front[x] != -1) x = front[x];
      vector<int> ans = {x+1};
      while (back[x] != -1) {
        x = back[x];
        ans.push_back(x+1);
      }
      cout << ans.size() << endl;
      rep(i,ans.size()) cout << ans[i] << ' ';
      cout << endl;
    } else {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (type == 1) {
        back[x] = y;
        front[y] = x;
      } else {
        back[x] = -1;
        front[y] = -1;
      }
    }
  }
  return 0;
}