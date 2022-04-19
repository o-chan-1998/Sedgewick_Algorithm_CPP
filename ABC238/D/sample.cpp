#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>

using namespace std;

#define rep(i,N) for (int i = 0; i < N; i++)
#define rep1(i,N) for(int i = 1; i <= N; i++)
#define drep(i,N) for(int i = N-1; i >= 0; i--)
#define srep(i,S,T) for (int i = S; i < T; i++)

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<int>; using vvi = vv<int>;
using vl = vc<long>; using vvl = vv<long>;
using ll = long long;

int main(void){

	int T; cin >> T;

	while(T--){
		ll s, a;
		cin >> a >> s;

		ll sum=0, carry=0;
		// sとaで桁数の長い方を格納
		int bit_len = max(to_string(s).length(), to_string(a).length());
		bool judge=true;
		rep(i, 60){	// 下位から順に2進数変換
			ll x=(ll(1)<<i)&a; 	// xの値はaの値に固定
			ll y=(ll(1)<<i)&s;
			x = !!x;
			y = !!y;

			// 採りうる組み合わせ条件で場合分け
			if(x==0 && carry==0 && y==0){
				carry = 0;
			}else if(x==0 && carry==0 && y==1){
				carry = 0;
			}else if(x==0 && carry==1 && y==0){
				carry = 1;
			}else if(x==0 && carry==1 && y==1){
				carry = 0;
			}else if(x==1 && carry==0 && y==0){
				carry = 1;
			}else if(x==1 && carry==0 && y==1){
				judge=false;
				break;
			}else if(x==1 && carry==1 && y==0){
				judge=false;
				break;
			}else if(x==1 && carry==1 && y==1){
				carry = 1;
			}
		}

		if(carry==0 && judge==true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}

	return EXIT_SUCCESS;
}