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

  int n = 9;
  int m;
  cin >> m;
  vector<vector<int>> to(n);
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> s(n, -1);
  rep(i, n - 1)
  {
    int p;
    cin >> p;
    --p;
    s[p] = i;
  }

  rep(i, n)
    ofs << s[i] << " ";
  ofs << endl << endl;

  vector<int> t(n, -1);
  rep(i, n - 1) t[i] = i;

  rep(i, n)
    ofs << t[i] << " ";
  ofs << endl << endl;

  map<vector<int>, int> dist;
  queue<vector<int>> q;

  dist[s] = 0;

  ofs << dist[s] << " ";
  ofs << endl << endl;

  q.push(s);
  while (q.size())
  {
    s = q.front();
    q.pop();
    int d = dist[s];
    rep(v, n) if (s[v] == -1)
    {
      for (int u : to[v])
      {
        swap(s[u], s[v]);
        if (dist.find(s) == dist.end())
        {
          dist[s] = d + 1;
          q.push(s);
        }
        swap(s[u], s[v]);
      }
    }
  }
  if (dist.find(t) == dist.end())
    cout << -1 << endl;
  else
    cout << dist[t] << endl;
 
  ofs.close();

  return 0;
}