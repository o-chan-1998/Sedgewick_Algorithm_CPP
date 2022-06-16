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
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  vector<int> a(n);
  rep(i,n){
    a[i] = s[i]=='.';
  }

  int ans = 0;
  int r = 0, sum = 0;
  rep(l,n) {
    while (r < n && sum+a[r] <= k) {
      sum += a[r];
      ++r;
    }
    ans = max(ans, r-l);
    sum -= a[l];
  }

  cout << ans << endl;
  return 0;
}