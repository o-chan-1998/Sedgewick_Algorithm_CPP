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

int main(void){

	// https://atcoder.jp/contests/abc238/submissions/29075048

	ll N; cin >> N;
	ll d=1;
	ll ans=0;

	while(d*10<=N){
		d *= 10;
	}

	while(d>0){
		ll c=N-d+1;

		if(c&1){	// 奇数(1の位が2進数で1)
			ans = (ans+(((c+1)/2)%MODDEF)*(c%MODDEF))%MODDEF;

		}else{		//偶数
			ans = (ans+((c+1)%MODDEF)*((c/2)%MODDEF))%MODDEF;
		}

		N -= c;
		d /= 10;
	}
	cout << ans << endl;

	return EXIT_SUCCESS;
}