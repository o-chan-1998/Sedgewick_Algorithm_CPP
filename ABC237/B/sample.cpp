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
using vl = vc<long>; using vvl = vv<long>;

int main(void){

	int H, W;
	cin >> H >> W;

	vvl A(H, vl(W));
	vvl B(W, vl(H));

	rep(i, H){
		rep(j, W){
			cin >> A.at(i).at(j);
			B.at(j).at(i) = A.at(i).at(j);	// 転置行列を格納
		}
	}

	rep(i, W){
		rep(j, H){
			cout << B.at(i).at(j) << " ";
		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}