#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <climits>
#include <bitset>
#include <numeric> // iota関数

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

#define LINF (1LL<<60)

int n, W;
ll dp[110][110000];
ll w[110], v[110];
 
int main(){
    cin >> n >> W;
    for(int i = 1;i <= n;i++)cin >> w[i] >> v[i];
    for(int j = 1;j < 110000;j++){
        dp[0][j] = LINF;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 110000;j++){
            dp[i][j] = dp[i-1][j];
            if(j-v[i] >= 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for(int v = 0;v < 110000;v++){
        if(dp[n][v] <= W){
            ans = max(ans, v);
        }
    }
    cout << ans << endl;
    
    return 0;
}