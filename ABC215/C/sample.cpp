#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <bitset>
#include <numeric> // iota関数
#include <fstream>

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

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vvi a(n, vi(n));
	rep(i,n){
		rep(j,n){
			cin >> a[i][j];
		}
	}
	int L=k*k/2+1;
	int wa=-1, ac=1001001001;
	while(wa+1<ac){
		int wj=(wa+ac)/2;
		bool ok=false;
		{
			vvi s(n+1, vi(n+1));	// 累積和の計算
			rep(i,n){
				rep(j,n){
					if(a[i][j]>wj){
						s[i+1][j+1]=1;
					}else{
						s[i+1][j+1]=0;
					}
				}
			}
			rep(i,n+1){	// 横方向の累積和
				rep(j,n){
					s[i][j+1]+=s[i][j];
				}
			}
			rep(i,n){	// 縦方向の累積和
				rep(j,n+1){
					s[i+1][j]+=s[i][j];
				}
			}
			rep(i,n-k+1){
				rep(j,n-k+1){
					int now = s[i+k][j+k];	// 右下
					now -= s[i][j+k];
					now -= s[i+k][j];
					now += s[i][j];
					if(now<L){
						ok=true;
					}
				}
			}
		}
		if(ok){
			ac = wj;
		}else{
			wa = wj;
		}
	}
	cout << ac << endl;

    return EXIT_SUCCESS;
}