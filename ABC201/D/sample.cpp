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

vector<string> s;

int H, W;
bool visited[2005][2005];
int memo[2005][2005];
const int INF = 99999;
int a[2005][2005];

int f(int, int);

int main()
{
    cin >> H >> W;
    s.resize(H); // vector配列の大きさ再定義
    rep(i, H)
    {
        cin >> s[i];
    }
    // sの値を数値変換(+なら1, -なら-1)
    rep(i, H)
    {
        rep(j, W)
        {
            if (s[i][j] == '+')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = -1;
            }
        }
    }

    int score = f(0, 0); // 初期状態(自分－相手)

    if (score == 0)
    {
        cout << "Draw" << endl;
    }
    else if (score > 0)
    {
        cout << "Takahashi" << endl;
    }
    else if (score < 0)
    {
        cout << "Aoki" << endl;
    }

    return EXIT_SUCCESS;
}

int f(int i, int j)
{
    // 終了状態(左下の位置)
    if (i == H - 1 && j == W - 1)
    {
        return 0;
    }

    // 訪問済みの場合
    if (visited[i][j])
    {
        return memo[i][j];
    }

    visited[i][j] = true;

    int res = -INF;

    // 右へ訪問した場合の遷移
    if (j + 1 < W)
    {
        res = max(res, a[i][j + 1] - f(i, j + 1));
    }
    // 下へ訪問した場合の遷移
    if (i + 1 < H)
    {
        res = max(res, a[i + 1][j] - f(i + 1, j));
    }

    memo[i][j] = res;

    return memo[i][j];
}
