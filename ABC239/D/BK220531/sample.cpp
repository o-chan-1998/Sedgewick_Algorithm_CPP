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

bool judge(int X);

int main(){

	// 総当り
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	// 素数表(エラトステネスのふるい)
	static bool prime[MAX]={false,false};	// 0,1は素数ではない
	srep(i,2,MAX){
		prime[i]=true;	// 初期化
	}
	srep(i,2,MAX){
		if(prime[i]){
			srep(j,2*i,MAX){
				if(j%i==0)
					prime[j]=false;
			}
		}
	}

	bool judge=true;
	// 高橋くんの選ぶ数
	srep(i,A,B+1){
		judge=true;
		// 青木くんの選ぶ数
		srep(j,C,D+1){
			// i+jが素数なら青木くんの勝ち
			if(prime[i+j])
				judge=false;
		}
		// 青木くんの勝ち筋がない場合
		if(judge)
			break;
	}

	if(judge)
		cout << "Takahashi" << endl;
	else
		cout << "Aoki" << endl;

	return EXIT_SUCCESS;
}

