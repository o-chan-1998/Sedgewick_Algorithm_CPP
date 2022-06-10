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

#define MOD 1000000007

ll dp[110000][2];
vector<int> edge[110000];
int n, u, v;
 
void dfs(int x, int last = -1){
    dp[x][0] = dp[x][1] = 1;
    for(auto to: edge[x]){
        if(to == last)continue;
        dfs(to, x);
        dp[x][0] = dp[x][0] * ((dp[to][0] + dp[to][1]) % MOD) % MOD;
        dp[x][1] = dp[x][1] * dp[to][0] % MOD;
    }
}

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    for(int i = 0;i < n-1;i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
 
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    
    return EXIT_SUCCESS;
}