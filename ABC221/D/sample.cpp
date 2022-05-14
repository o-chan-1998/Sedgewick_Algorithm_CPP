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
  ofs << "===" << endl;

  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    mp[a]++;
    mp[a + b]--;
  }
  int pre = -100, now = 0;
  vector<int> ans(n + 1);
  for (auto &item : mp)
  {
    ans[now] += item.first - pre;
    now += item.second;
    pre = item.first;
  }
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << endl;
  ofs.close();

  return EXIT_SUCCESS;
}