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

	int T; 
	cin >> T;

	while(T--){
		ll s, a; 
		cin >> s >> a;

		ll sum=0, carry=0;
		rep(i, 60){	// 下位から順に2進数変換
			ll X=(ll(1)<<i)&a;	// aを2進数に変換(X)
			ll Y=(ll(1)<<i)&s;	// sを2進数に変換(Y)
			X = !!X;	// Xを10進数から0/1に変換(二重否定(!!)で0/1変換できる)
			Y = !!Y;	// Xを10進数から0/1に変換(二重否定(!!)で0/1変換できる)
			
			if(X && (Y^carry)){		// Y^carryはYとcarryの排他的論理和
									// Y^carryが1となるのは(x,y)=(1,0),(0,1)
									// この状態とX(x and y)=1は両立しない
				cout << "No";
				return EXIT_SUCCESS;
			}else if(X){
				carry = 1;	// X=trueは(x,y)=(1,1)なので繰り上がりが起きる
			}else{
				carry = (!Y) && carry;	// Yが0((x,y)=(0,0))のとき、繰り上がりが続く
			}
		}

		if(carry){	// 最終的に繰り上がりが残る時
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}

	return EXIT_SUCCESS;
}