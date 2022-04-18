#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>

using namespace std;

#define rep(i,N) for (long i = 0; i < N; i++)
#define rep1(i,N) for(long i = 1; i <= N; i++)
#define drep(i,N) for(long i = N-1; i >= 0; i--)
#define srep(i,S,T) for (long i = S; i < T; i++)

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<int>; using vvi = vv<int>;
using vl = vc<long>; using vvl = vv<long>;
using ll = long long;

int main(void){

	string S;
	cin >> S;

	long l=0, r=S.length(); 

	rep(i,S.length()){
		// 両端の文字が'a'の場合
		if(S[l]=='a' && S[r-1]=='a'){
			l++; r--;
		}else if(S[l]=='a' && S[r-1]!='a'){	// 前がaで後ろがa出ない場合、回文にならない
			cout << "No" << endl;
			return EXIT_SUCCESS;
		}else{
			// 後ろが'a'でなくなるまでポインタを移動する
			if(S[r-1]=='a'){
				r--;
			}else{
				break;
			}
		}
	}

	// 回文チェック
	rep(i, S.length()-1){
		if (S[l]==S[r-1] && l<r){
			l++; r--;
		}else{
			break;
		}
	}
	if(l>=r-1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return EXIT_SUCCESS;
}