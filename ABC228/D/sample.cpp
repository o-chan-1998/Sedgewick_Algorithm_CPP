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

  int n = 1<<20;
  int q;
  cin >> q;
  
ofs << "  int n(" << n << ") = 1<<20;" << endl;
ofs << "  cin >> q(" << q << ");" << endl;

  set<int> s;
  rep(i,n) s.insert(i);

// for(auto itr = s.begin(); itr != s.end(); ++itr) {
//     ofs << *itr << " ";      // イテレータの指す先のデータを表示
// }
// ofs << endl;

  map<int,ll> a;
ofs << "  rep(qi,q(" << q << ")) {" << endl;
  rep(qi,q) {
    int type; ll x;
    cin >> type >> x;
ofs << "    if (type(" << type << ") == 1) {" << endl;
ofs << "    cin >> type(" << type << ") >> x(" << x << ");" << endl;
    if (type == 1) {
      int i = x%n;
ofs << "      int i(" << i << ") = x(" << x << ")%n;" << endl;
      auto it = s.lower_bound(i);
ofs << "      auto it(" << *it << ") = s.lower_bound(i(" << i << "));" << endl;
ofs << "      if (it == s.end()(" << *s.end() << ")) it = s.begin()(" << *s.begin() << ");" << endl;
      if (it == s.end()) it = s.begin();
      a[*it] = x;
ofs << "      a[*it(" << *it << ")] = x(" << x << ");" << endl;
      s.erase(it);
    } 
    else {
ofs << "    else {" << endl;
      auto it = a.find(x%n);
ofs << "      auto it(" << it->first << ", " << it->second << ") = a.find(x%n(" << x%n << "));" << endl;
ofs << "      if (it == a.end()(" << a.end()->first << ", " << a.end()->second << ")) cout << -1 << endl;" << endl;
      if (it == a.end()) cout << -1 << endl;
      else cout << it->second << endl;
    }
  }
 
   ofs.close();

  return 0;
}