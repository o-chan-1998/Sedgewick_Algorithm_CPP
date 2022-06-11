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
  // ファイル出力
  const char *fileName = "trace.txt";
  ofstream ofs(fileName);
  if (!ofs)
  {
    cout << "ファイルが開けませんでした。" << endl;
    cin.get();
    return 0;
  }

  string s;
  int k;
  cin >> s >> k;
ofs << "  cin >> s(" << s << ") >> k(" << k << ");" << endl;
  int n = s.size();
ofs << "  int n(" << n << ") = s.size();" << endl;
  vector<int> a(n);
  rep(i,n){
    a[i] = s[i]=='.';
  }

ofs << "  rep(i,n){" << endl;
rep(i,n) ofs << "    a[i](" << a[i] << ") = s[i(" << i << ")](" << s[i] << ")=='.';" << endl;
ofs << "  }" << endl;

  int ans = 0;
  int r = 0, sum = 0;
ofs << "  rep(l,n(" << n << ")) {" << endl;
  rep(l,n) {
ofs << "    while (r(" << r << ") < n(" << n << ") && sum+a[r](" << sum+a[r] << ") <= k(" << k << ")) {" << endl;
    while (r < n && sum+a[r] <= k) {
      sum += a[r];
ofs << "      sum(" << sum << ") += a[r(" << r << ")](" << a[r] << ");" << endl;
      ++r;
    }
ofs << "    }" << endl;
    ans = max(ans, r-l);
ofs << "    ans(" << ans << ") = max(ans(" << ans << "), r(" << r << ")-l(" << l << ")(" << r-l << "));" << endl;
    sum -= a[l];
  }

  cout << ans << endl;
ofs << "  cout << ans(" << ans << ") << endl;" << endl;
 
   ofs.close();

  return 0;
}