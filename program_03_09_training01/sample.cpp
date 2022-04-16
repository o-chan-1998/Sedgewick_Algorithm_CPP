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

struct Node{
	int X;
	int Y;
	Node *next;
};

int main(void){

	int N, S, D;
	cin >> N >> S >> D;
	
	Node *t = new Node();
	cin >> t->X >> t->Y; 
	t->next = t;	// まずは自分自身を指す
	Node *lp = t;	// 節点xはt節点(先頭)を指す
	for (int i = 1; i < N; i++){
		lp->next = new Node();	// 次の要素を新しく作る
		lp = lp->next;	// 新しい要素をポインタで示す
		cin >> lp->X >> lp->Y;
		lp->next = t;	// 新しいノードは先頭を指す(循環リスト)
	}

	// 次のポインタが自身を指していたら終了
	while (lp != lp->next){
		if(lp->X<S && D<lp->Y){
			cout << "YES" << endl;
			return EXIT_SUCCESS;
		}
		lp = lp->next;
		lp->next = lp->next->next;	// 調査済み要素削除
	}
	cout << "No" << endl;
	return EXIT_SUCCESS;
}
