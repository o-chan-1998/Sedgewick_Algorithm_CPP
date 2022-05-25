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

bool dp[110000];

int main()
{
    int n, k;
    cin >> n >> k;

    vi a(k);

    rep(i,k+1){
        dp[i] = 1;
    }

    rep(i,n){
        cin >> a[i];
    }

    rep1(i,k){
        rep(j,n){
            if(i-a[j]<0){
                continue;
            }
            if(dp[i-a[j]]==1){
                dp[i] = 0;
            }
        }
    }

    if(dp[k]){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }


    return EXIT_SUCCESS;
}
