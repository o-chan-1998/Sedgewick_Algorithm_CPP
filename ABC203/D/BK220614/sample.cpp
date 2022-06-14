#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>
#include <climits>

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

int main()
{
    int N, K;
    cin >> N >> K;
    vvi A(N, vi(N));

    // 標準入力
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> A[i][j];
        }
    }

    int L = K * K / 2 + 1; // 中央値

    // 二分探索
    int wa = -1, ac = INT_MAX;
    while (wa + 1 < ac)
    {
        int wj = (wa + ac) / 2;
        bool ok = false;

        // 累積和の計算
        {
            vvi S(N + 1, vi(N + 1));
            // 標準入力の値がwjより大きいか小さいか0,1に変換してコピー
            rep(i, N)
            {
                rep(j, N)
                {
                    S[i + 1][j + 1] = A[i][j] > wj ? 1 : 0;
                }
            }
            // 横方向
            rep(i, N + 1)
            {
                rep(j, N)
                {
                    S[i][j + 1] += S[i][j];
                }
            }
            // 縦方向
            rep(i, N)
            {
                rep(j, N + 1)
                {
                    S[i + 1][j] += S[i][j];
                }
            }
            // 左上
            rep(i, N - K + 1)
            {
                rep(j, N - K + 1)
                {
                    int now = S[i + K][j + K];
                    now -= S[i][j + K];
                    now -= S[i + K][j];
                    now += S[i][j];
                    if (now < L)
                    {
                        ok = true;
                    }
                }
            }
        }

        if (ok)
        {
            ac = wj; // wjより小さい値を二分探索
        }
        else
        {
            wa = wj; // wjより大きい値を二分探索
        }
    }

    cout << ac << endl;

    return EXIT_SUCCESS;
}
