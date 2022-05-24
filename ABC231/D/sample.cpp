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

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); 
    v = root(v);
		if (u == v) 
      return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

UnionFind UF;

int main(void){
    int N,M;
    cin >> N >> M;
    vector<int> E[N];
    
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    
    rep(i,N){
        if(E[i].size()>=3){
            cout << "No" << endl;
            return 0;
        }
    }
    
    UF.init(N);
    rep(i,N){
        for(int a:E[i]){
            if(a>i && UF.same(a,i)){
                cout << "No" << endl;
                return 0;
            }
            UF.unite(i,a);
        }
    }
    cout << "Yes" << endl;
}