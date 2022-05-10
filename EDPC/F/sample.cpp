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

string s, t;
int dp[3300][3300];
int main(){
    cin >> s >> t;
    int n = s.size(), m = t.size();
 
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
        }
    }
 
    string rewsna = "";
 
    while(n > 0 && m > 0){
        if(dp[n][m] == dp[n-1][m])n--;
        else if(dp[n][m] == dp[n][m-1])m--;
        else {
            rewsna += s[n-1];
            n--;
            m--;
        }
    }
    int l = rewsna.size();
    for(int i = 0;i < l;i++){
        cout << rewsna[l-i-1];
    }cout << endl;
    
    return EXIT_SUCCESS;
}