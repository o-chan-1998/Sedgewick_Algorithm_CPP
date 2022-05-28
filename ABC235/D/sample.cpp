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
  // IO高速化のおまじない
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a, n;
  cin >> a >> n;

  const int MX=1000000;
  const int INF=1001001001;
  vi dist(MX, INF);
  queue<int> q;

  auto push=[&](int v, int d){
    if(dist[v]!=INF){
      return;
    }
    dist[v]=d;
    q.push(v);
  };

  push(1,0);

  while(!q.empty()){
    int v=q.front(); q.pop();
    int d=dist[v];
    if(ll(v)*a < MX){
      push(v*a, d+1);
    }
    if(v>=10 && v%10!=0){
      string s=to_string(v);
      int len=s.size();
      rotate(s.begin(),s.begin()+(len-1),s.end());
      int u=stoi(s);
      push(u, d+1);
    }
  }

  if(dist[n]==INF){
    cout << -1 <<endl;
  }else{
    cout << dist[n] << endl;
  }

  return EXIT_SUCCESS;
}