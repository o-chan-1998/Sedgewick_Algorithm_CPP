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

  int n, k;
  cin >> n >> k;
  vector<ll> a(n);

  rep(i,n){
    cin >> a[i];
  } 

  ll ac = 0, wa = 999;
  
  while (wa-ac > 1) {
    ofs << "◆ whileループ" << endl;
    ofs << "while (wa(=" << wa << ")-ac(=" << ac << ") > 1) {" << endl;
    ll wj = (ac+wa)/2;
    ofs << "ll wj(=" << wj << ") = (ac(=" << ac << ")+wa(=" << wa << "))/2;" << endl;

    ll s = 0;
    ofs << "rep(i,n(=" << n<< ")){" << endl;
    rep(i,n){
      ofs << "  s(=" << s << ") += min(a[i](=" << a[i] << "),wj(=" << wj << "));" << endl;
      s += min(a[i],wj);
    }
    ofs << "}" << endl;
      ofs << "   if (s(=" << s << ") >= k(=" << k << ")*wj(=" << wj << ")) {" << endl;
    if (s >= k*wj) {
      ac = wj;
      ofs << "      ac(=" << ac << ") = wj(=" << wj << ");" << endl;
    }else{
ofs << "    }else{" << endl;
      wa = wj;
ofs << "      wa(=" << wa << ") = wj(=" << wj << ");" << endl;
    } 
    ofs << endl;
  }
  cout << ac << endl;


  return 0;
}