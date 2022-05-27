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

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (int i = 1; i <= N; i++)
#define drep(i, N) for (int i = N - 1; i >= 0; i--)
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

int main()
{
    int N, M;
    cin >> N >> M;

    const int INF=INT_MAX;
    
    vvi f(N,vi(N,INF));
    rep(i,N){
        f[i][i]=0;
    }

    // 標準入力
    rep(i,M){
        int A,B,C;
        cin >> A >> B >> C;
        f[A-1][B-1]=C;
    }

    // ワーシャル・フロイド
    ll ans;
    rep(k,N){
        rep(i,N){
            rep(j,N){
                f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
                if(f[i][j]!=INF){
                    ans+=f[i][j];
                }
            }
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}
