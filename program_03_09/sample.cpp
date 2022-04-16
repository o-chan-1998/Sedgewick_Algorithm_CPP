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
	int item;
	Node *next;
};

int main(void){

	int N, M;
	cin >> N >> M;
	Node *t = new Node();
	Node *x = t;	// 節点xはt節点(先頭)を指す
	
	t->item = 1; 
	t->next = t;	// まずは自分自身を指す
	for (int i = 2; i <= N; i++){
		x->next = new Node();	// 次の要素を新しく作る
		x = x->next;	// 新しい要素をポインタで示す
		x->item = i;
		x->next = t;	// 新しいノードは先頭を指す(循環リスト)
	}

	// 次のポインタが自身を指していたら終了
	while (x != x->next){
		for (int i = 1; i < M; i++)
			x = x->next;	// 次の要素に移動
		x->next = x->next->next;	// リンク要素の削除
		N--;
	}
	cout << x->item << endl;
	return EXIT_SUCCESS;
}
