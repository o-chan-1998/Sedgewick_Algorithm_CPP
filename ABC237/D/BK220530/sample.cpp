// https://atcoder.jp/contests/abc190/tasks/abc190_b

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); i++)

int main(void){

	int N;
	string s;
	cin >> N;
	cin >> s;

	deque<int> ans = {N};	// キューの初期化

	for(int i=N-1; i>=0; i--){
		if(s[i]=='L'){
			ans.push_back(i);	// Lは右に追加
		}else{
			ans.push_front(i);	// Rは左に追加
		}
	}

	rep(i, N+1){
		cout << ans[i] << " ";
	}

	cout << endl;

	return EXIT_SUCCESS;
}
