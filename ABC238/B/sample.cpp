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
#define rng(a) a.begin(),a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<int>; using vvi = vv<int>;
using vl = vc<long>; using vvl = vv<long>;
using ll = long long;

int main(void){

	int N; cin >> N;
	vector<int> A(N), Cut(N);

	rep(i,N){
		cin >> A[i];
		if(i==0)
			Cut[i]=A[i];
		else{
			Cut[i]=A[i]+Cut[i-1];
			Cut[i] %= 360;
		}
	}

	sort(rng(Cut));
	Cut.push_back(360);

	int ans=0;
	srep(i,1,N+2){
		ans = max(ans, Cut[i]-Cut[i-1]);
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}