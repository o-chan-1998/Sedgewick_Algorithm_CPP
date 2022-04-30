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

#define EPS 10e-2

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> S, T;

    // 集合Sの座標を変数に格納
    rep(i, N)
    {
        int A, B;
        cin >> A >> B;
        S.push_back(make_pair(A, B));
    }
    // 集合Tの座標を変数に格納
    rep(i, N)
    {
        int C, D;
        cin >> C >> D;
        T.push_back(make_pair(C, D));
    }

    // 集合Sの座標を昇順に整列
    sort(S.begin(), S.end());

    static const double PI = 3.141592653589793;

    for (long double theta = 0; theta < 360; theta += EPS)
    {
        // 集合Tを回転した座標を計算
        vector<pair<long double, long double>> p;

        rep(i, N)
        {
            long double tmp_x = cos(PI * theta / 180) * T[i].first - sin(PI * theta / 180) * T[i].second;
            long double tmp_y = sin(PI * theta / 180) * T[i].first + cos(PI * theta / 180) * T[i].second;
            p.push_back(make_pair(tmp_x, tmp_y));
        }

        // 回転後の座標を昇順に整列(集合Sとの移動分をリセットさせる)
        sort(p.begin(), p.end());

        // 誤差計算
        vector<long double> X_diff, Y_diff;
        rep(i, N)
        {
            X_diff.push_back(p[i].first - S[i].first);
            Y_diff.push_back(p[i].second - S[i].second);
        }

        // X方向の最大誤差、最小誤差
        long double X_diff_Max = *max_element(X_diff.begin(), X_diff.end());
        long double X_diff_Min = *min_element(X_diff.begin(), X_diff.end());
        // Y方向の最大誤差、最小誤差
        long double Y_diff_Max = *max_element(Y_diff.begin(), Y_diff.end());
        long double Y_diff_Min = *min_element(Y_diff.begin(), Y_diff.end());

        if ( (X_diff_Max- X_diff_Min) <= EPS && (Y_diff_Max -Y_diff_Min) <= EPS)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return EXIT_SUCCESS;
}
