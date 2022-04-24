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
#define MAX 210

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<int>; using vvi = vv<int>;
using vl = vc<long>; using vvl = vv<long>;
using ll = long long;

int main(){

	ll N;
	int K; 
	cin >> N >> K;

	rep(i, K){
		if(N%200==0){
			N /= 200;
		}else{
			N = 1000*N+200;
		}
	}

	cout << N << endl;

	return EXIT_SUCCESS;
}
