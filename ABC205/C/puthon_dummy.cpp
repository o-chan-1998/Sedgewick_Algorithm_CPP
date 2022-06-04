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
	A, B, C = map(int, input().split());
	ans_list = ['>', '<', '='];
	ans = 2;
	if(0<=A and 0<=B){
		if(A < B){
			ans = 1;
		}else if(B < A){
			ans = 0;
		}else{
			ans = 2;
		}
	}else{
		if(C % 2 != 0){
			if (A < 0 and B < 0){
				if(A < B){
					ans = 1;
				}else if(B < A){
					ans = 0;
				}else{
					ans = 2;
				}
			}else{
				if(A < 0){
					ans = 1;
				}else if(B < 0){
					ans = 0;
				}
			}
		}else{
			if(abs(A) < abs(B)){
				ans = 1;
			}else if(abs(B) < abs(A)){
				ans = 0;
			}else{
				ans = 2;
			}
		}
	}
	print(ans_list[ans]);
}