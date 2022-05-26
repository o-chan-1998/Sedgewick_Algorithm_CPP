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

struct UnionFind{
 
  vector<int>par;
  vector<int>rank;
 
  UnionFind(int size){
    rank.resize(size,1);
    par.resize(size);
    for(int i=0;i<size;i++)par[i]=i;
  }
 
  void unite(int node1,int node2){
    if(is_connected(node1,node2))return;
    node1=find(node1);
    node2=find(node2);
    if(rank[node1]>rank[node2])swap(node1,node2);
    par[node1]=node2,rank[node2]+=rank[node1];
  }
  int find(int node){
    if(par[node]==node)return node;
    return par[node]=find(par[node]);
  }
  bool is_connected(int node1,int node2){
    return find(node1)==find(node2);
  }
  int size(int node){
    return rank[find(node)];
  }
 
};
 
int main() {
    int n; ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n){
      cin >> a[i];
    }
    vector<ll> s(n+1);
    rep(i,n){
      s[i+1] = s[i]+a[i];
    } 
    map<ll,int> mp;
    ll ans = 0;
    rep(i,n+1) {
      ans += mp[s[i]];
      mp[s[i]+k]++;
    }
    cout << ans << endl;

    return 0;
}