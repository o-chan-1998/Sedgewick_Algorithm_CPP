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

const int mod = 998244353;
class mint
{
  long long x;

public:
  mint(long long x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const
  {
    return mint(-x);
  }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint &a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint &a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint &a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint &a) const
  {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const
  {
    return pow(mod - 2);
  }
  mint &operator/=(const mint &a)
  {
    return (*this) *= a.inv();
  }
  mint operator/(const mint &a) const
  {
    mint res(*this);
    return res /= a;
  }

  friend ostream &operator<<(ostream &os, const mint &m)
  {
    os << m.x;
    return os;
  }
};

int main()
{
  // https://programming.pc-note.net/cpp/filestream.html
  // ファイル出力
  const char *fileName = "trace.txt";
  ofstream ofs(fileName);
  if (!ofs)
  {
      cout << "ファイルが開けませんでした。" << endl;
      cin.get();
      return 0;
  }

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    ofs << a[i] << " "; // ★デバッグ★
  }
  ofs << endl;  // ★デバッグ★

  vector<mint> dp(10);
  dp[a[0]] = 1;
  ofs << "a[0] : " << a[0] << endl; // ★デバッグ★
  ofs << "dp[" << a[0] << "] : " << dp[a[0]] << endl; // ★デバッグ★

  rep1(i,n-1)
  {
    int na = a[i];
    ofs << "(" << i << ")" << endl; // ★デバッグ★
    ofs << "na : " << na << "(na=a[i])" << endl;

    // デバッグ中
    ofs << "【dp】" << endl;
    rep(i,10){
      ofs << i << "\t";
    }
    ofs << endl;
    rep(i,10){
      ofs << dp[i] << "\t";
    }
    ofs << endl;

    vector<mint> p(10);
    ofs << "【p】" << endl;
    rep(i,10){
      ofs << i << "\t";
    }
    ofs << endl;
    rep(i,10){
      ofs << p[i] << "\t";
    }
    ofs << endl;

    swap(p, dp);

    ofs << " ----- swap(p,dp)後 ----- " << endl;
    ofs << "【dp】" << endl;
    rep(i,10){
      ofs << i << "\t";
    }
    ofs << endl;
    rep(i,10){
      ofs << dp[i] << "\t";
    }
    ofs << endl;

    ofs << "【p】" << endl;
    rep(i,10){
      ofs << i << "\t";
    }
    ofs << endl;
    rep(i,10){
      ofs << p[i] << "\t";
    }
    ofs << endl;

    rep(j, 10)
    {
      dp[(j + na) % 10] += p[j];
      ofs << "(j : " << j << ")" << endl;
      ofs << "dp[(j + na) % 10] += p[j]" << endl;
      ofs << "dp[(" << j << " + " << na << ") % 10] += " << "p[" << j << "]" << endl;
      ofs << "dp[" << (j + na) << " % 10] += " << "dp[" << j << "]" << endl;
      ofs << "【dp】" << endl;
      rep(i,10){
        ofs << i << "\t";
      }
      ofs << endl;
      rep(i,10){
        ofs << dp[i] << "\t";
      }
      ofs << endl;
      ofs << "【p】" << endl;
      rep(i,10){
        ofs << i << "\t";
      }
      ofs << endl;
      rep(i,10){
        ofs << p[i] << "\t";
      }
      ofs << endl;
      ofs << "---" << endl;

      dp[(j * na) % 10] += p[j];
      ofs << "dp[(j * na) % 10] += p[j]" << endl;
      ofs << "dp[(" << j << " * " << na << ") % 10] += " << "p[" << j << "]" << endl;
      ofs << "dp[" << (j * na) << " % 10] += " << "dp[" << j << "]" << endl;
      ofs << "【dp】" << endl;
      rep(i,10){
        ofs << i << "\t";
      }
      ofs << endl;
      rep(i,10){
        ofs << dp[i] << "\t";
      }
      ofs << endl;
      ofs << "【p】" << endl;
      rep(i,10){
        ofs << i << "\t";
      }
      ofs << endl;
      rep(i,10){
        ofs << p[i] << "\t";
      }
      ofs << endl;
      ofs << "===" << endl;
    }
  }
  rep(i, 10) cout << dp[i] << endl;

  ofs.close();

  return EXIT_SUCCESS;
}