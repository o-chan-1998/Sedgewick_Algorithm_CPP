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

#define MODDEF 998244353

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<int>; using vvi = vv<int>;
using vl = vc<long>; using vvl = vv<long>;
using ll = long long;

ll S(ll A, ll B){
	return (B-A+1)*(A+B)/2; //	要素数×(初項＋末項)÷2
}

int main(void){

	ll N; cin >> N;
	ll ans=0;
	srep(i, 1, 19){
		if(pow(10,i)<=N){
			ans += S(1,9*pow(10,i-1));
			ans %= MODDEF;
		}else{	// 1～(N-10^i+1)の和
			ans += S(1, N-pow(10,i-1)+1);
			ans %= MODDEF;
			break;
		}
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}