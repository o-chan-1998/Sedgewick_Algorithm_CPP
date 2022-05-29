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

#define INF 1e18

int main()
{
    int H, W;
    ll C;
    cin >> H >> W >> C;

    vvi A(H, vi(W));

    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }

    ll ans=INF;

    rep(_,2){
        vvll d(H, vll(W, INF));

        rep(i,H){
            rep(j,W){
                if(i>0){
                    d[i][j]=min(d[i][j], d[i-1][j]);
                }
                if(j>0){
                    d[i][j]=min(d[i][j], d[i][j-1]);
                }
                ans = min(ans, A[i][j]+(i+j)*C+d[i][j]);
                d[i][j] = min(d[i][j], A[i][j]-(i+j)*C);
            }
        }

        reverse(A.begin(), A.end());
    }

    cout << ans << endl;

   return EXIT_SUCCESS;
}