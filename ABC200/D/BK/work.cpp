#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-5;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<vector<vector<int>>>dp(200);
    for (int i = 0; i < N; i++) {
        cin >> K;
        K %= 200;
        dp[K].push_back({ i });
        if (dp[K].size() == 2) {
            cout << "YES\n";
            cout << dp[K][0].size() << " ";
            for (auto j : dp[K][0])cout << j + 1 << " ";
            cout << endl;
            cout << dp[K][1].size() << " ";
            for (auto j : dp[K][1])cout << j + 1 << " ";
            cout << endl;
            return 0;
        }
        for (int j = 0; j < 200; j++) {
            if (dp[j].empty())continue;
            if (dp[j].front().back() == i)continue;
            dp[(j + K) % 200].push_back(dp[j].front());
            dp[(j + K) % 200].back().push_back(i);
            if (dp[(j + K) % 200].size() == 2) {
                cout << "YES\n";
                cout << dp[(j + K) % 200][0].size() << " ";
                for (auto j : dp[(j + K) % 200][0])cout << j + 1 << " ";
                cout << endl;
                cout << dp[(j + K) % 200][1].size() << " ";
                for (auto j : dp[(j + K) % 200][1])cout << j + 1 << " ";
                cout << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";
}