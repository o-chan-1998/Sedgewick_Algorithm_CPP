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

int n;
int happy[110000][3];
int dp[110000][3];
// 0: umi
// 1: yama
// 2: HW

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
    }

    for(int i = 1;i <= n;i++){
        for(int place = 0;place < 3;place++){
            for(int placeY = 0; placeY < 3;placeY++){
                if(place == placeY)continue;
                dp[i][place] = max(dp[i][place],
                                   dp[i-1][placeY] + happy[i][place]);
            }
        }
    }
    
    int ans = 0;
    for(int place = 0;place < 3;place++){
        ans = max(ans, dp[n][place]);
    }
    cout << ans << endl;
    return 0;
}