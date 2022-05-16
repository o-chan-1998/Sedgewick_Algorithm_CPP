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
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  const int M = 16;
  vector<mint> dp(M);
  dp[0] = 1;
  rep(i, n)
  {
    vector<mint> p(M);

    ofs << i << "番目" << endl;
    rep(i, M)
            ofs
        << dp[i] << " ";
    ofs << endl;
    rep(i, M)
            ofs
        << p[i] << " ";
    ofs << endl << endl;

    swap(dp, p);

    ofs << "- swap -" << endl;
    rep(i, M)
            ofs
        << dp[i] << " ";
    ofs << endl;
    rep(i, M)
            ofs
        << p[i] << " ";
    ofs << endl << endl;

    rep(j, M - 1)
      p[j + 1] += p[j];
    rep(i, M)
            ofs << p[i] << " ";
    ofs << endl << endl;

    rep(j, M)
    {
      if (a[i] <= j && j <= b[i])
      {
        dp[j] += p[j];
      }
      ofs << dp[j] << " ";
    }
    ofs << endl << endl;
  }
  mint ans;
  rep(i, M) ans += dp[i];
  cout << ans << endl;

  ofs.close();

  return 0;
}