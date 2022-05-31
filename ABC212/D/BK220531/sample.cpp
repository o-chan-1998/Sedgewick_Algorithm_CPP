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

constexpr int mod = 1000000007;
class mint
{
public:
    long long x;
    constexpr mint(long long x = 0) : x((x % mod + mod) % mod) {}
    constexpr mint &operator+=(const mint &a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
};

int main()
{
    int Q;
    cin >> Q;

    // ヒープキューの用意
    priority_queue<ll, vll, greater<ll>> que;
    // 加算要素用意
    ll S=0;

    rep1(i,Q){
        int P;
        cin >> P;
        if(P==3){
            cout << que.top()+S << endl;
            que.pop();  // 取り出したものは捨てる
        }else{
            int X;
            cin >> X;
            if(P==1){
                que.push(X-S);
            }else{
                S += X;
            }
        }
    }

    return EXIT_SUCCESS;
}