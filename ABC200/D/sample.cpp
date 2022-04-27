#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>

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
    int N;
    cin >> N;
    vvvi dp(200);

    ll K;

    for (int i = 0; i < N; i++)
    {
        cin >> K;
        K %= 200;

        // 余りがKとなるDP配列に標準入力インデックスを格納
        dp[K].push_back({i});

        // 余りがKとなる組が2つ
        if (dp[K].size() == 2)
        {
            cout << "Yes" << endl;

            // 1組目
            cout << dp[K][0].size() << " ";
            for (auto j : dp[K][0])
                cout << j + 1 << " ";
            cout << endl;

            // 2組目
            cout << dp[K][1].size() << " ";
            for (auto j : dp[K][1])
                cout << j + 1 << " ";
            cout << endl;

            return 0;
        }

        // 200で割った余りの組は0～199
        for (int j = 0; j < 200; j++)
        {
            if (dp[j].empty())
                continue;
            // インデックスが自分自身
            if (dp[j].front().back() == i)
                continue;
            dp[(j + K) % 200].push_back(dp[j].front());
            dp[(j + K) % 200].back().push_back(i);

            // 余りがKとなる組が2つ
            if (dp[(j + K) % 200].size() == 2)
            {
                cout << "Yes" << endl;

                cout << dp[(j + K) % 200][0].size() << " ";
                for (auto j : dp[(j + K) % 200][0])
                    cout << j + 1 << " ";
                cout << endl;

                cout << dp[(j + K) % 200][1].size() << " ";
                for (auto j : dp[(j + K) % 200][1])
                    cout << j + 1 << " ";
                cout << endl;

                return 0;
            }
        }
    }
    cout << "No" << endl;
}