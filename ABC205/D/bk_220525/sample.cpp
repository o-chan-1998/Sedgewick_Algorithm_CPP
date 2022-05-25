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

using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (int i = 1; i <= N; i++)
#define drep(i, N) for (int i = N - 1; i >= 0; i--)
#define srep(i, S, T) for (int i = S; i < T; i++)
#define rng(a) a.begin(), a.end()
#define MAX 210

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
    int N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vll C(N);
    rep(i, N)
    {
        C[i] = A[i] - i - 1;
    }

    rep(qi, Q)
    {
        ll K;
        cin >> K;

        // 探索したいK以上のイテレータを返す
        int r = lower_bound(C.begin(), C.end(), K) - C.begin();

        ll ans;
        if (r == 0)
        {
            ans = K;
        }
        else
        {
            // A_r-1から(K-C[r - 1])個後ろの数値
            ans = A[r - 1] + (K - C[r - 1]);
        }
        cout << ans << endl;
    }

    return EXIT_SUCCESS;
}