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

typedef long long ll;
typedef struct Node{
    int x;
    struct Node *l, *r;
}Node;
Node *Head = NULL;
 
void solve_abc237();

int main(){

    int N;
    string s;
    cin >> N;
    cin >> s;
    
	// Headノード作成
	Head = new Node;	
    Head->l = Head->r = NULL;	// リストの接続先なし
    Head->x = 0;	// 初期値:0

    Node *pre = Head;	// 前接続ノード初期化
    Node *tail = Head;	// 後接続ノード初期化

	// 連結リスト作成処理
    rep(i, N){
		// 新規ノード作成
        Node *pp = new Node;
		pp->x = i + 1;

		// Lが与えられた場合
        if(s[i] == 'L'){
            if(pre->l)
                pre->l->r = pp;
            pp->l = pre->l;
            pp->r = pre;	// 新規ノードの右が前ノード
            pre->l = pp;	// 前ノードの左が新規ノード
        }else{	// Rが与えられた場合
            if(pre->r)
                pre->r->l = pp;
            pp->r = pre->r;
            pp->l = pre;	// 新規ノードの左が前ノード
            pre->r = pp;	// 前ノードの右が新規ノード
        }

		pre = pp;
    }

    while(Head->l) Head = Head->l;	// リストのHeadを先頭に移動
    while(tail->r) tail = tail->r;	// リストのtailを末尾に移動
    
	// リスト表示
	for(Node *p = Head; ; p = p->r){
        cout << p->x << " ";
		
		//　tailに到達したらループ脱出
        if(p == tail) 
			break;
    }

	cout << endl;
    
	return EXIT_SUCCESS;
}
