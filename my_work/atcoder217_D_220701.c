#include<stdio.h>
#include<stdlib.h>

static int max(const int a, const int b){return a>b?a:b;}
typedef struct node{
	int key;
	int rank;
	int size;
	struct node *left, *right;
} node;

// 平衡二分探索木の実装
int get_rank(node *x){
	return x == NULL ? -1 : (*x).rank;
}

int get_size(node *x){
		return x == NULL ?  0 : (*x).size;
}

static void update(node *x){
	if(x == NULL)
		return;
	(*x).rank = max(get_rank((*x).left),get_rank((*x).right)) + 1;
	(*x).size = get_size((*x).left) + get_size((*x).right) + 1;
}

static node* new_node(int k){
	node* res = (node*)malloc(sizeof(node));
	(*res).key = k;
	(*res).left = NULL;
	(*res).right = NULL;
	(*res).rank = 0;
	(*res).size = 1;
	return res;
}

static node* left_rotate(node* x){
	if(x == NULL) 
		return NULL;
	node *y = (*x).right;
	if(y == NULL) 
		return x;
	(*x).right = (*y).left;
	(*y).left = x;
	update(x);
	update(y);
	return y;
}

static node* right_rotate(node *y){
	if(y == NULL) 
		return NULL;
	node *x = (*y).left;
	if(x == NULL) 
		return y;
	(*y).left = (*x).right;
	(*x).right = y;
	update(y);
	update(x);
	return x;
}

static node* fixup(node *x){
	if(x == NULL) 
		return NULL;
	update(x);
	int l = get_rank((*x).left), r = get_rank((*x).right);
	if(abs(l - r) <= 1) 
		return x;
	if(l - r == 2){
		if(get_rank((*(*x).left).left) < get_rank((*(*x).left).right)){
			(*x).left = left_rotate((*x).left);
		}
		return right_rotate(x);
	}
	if(l - r == -2){
		if(get_rank((*(*x).right).left) > get_rank((*(*x).right).right)){
			(*x).right = right_rotate((*x).right);
		}
		return left_rotate(x);
	}
	return NULL;
}

node* insert(node *x, int t){
	if(x == NULL){
		return new_node(t);
	}
	if(t < (*x).key){
		(*x).left = insert((*x).left, t);
	}else{
		(*x).right = insert((*x).right, t);
	}
	return fixup(x);
}

node*lt(node*x,int k){
	if(x==NULL)return NULL;
	if((*x).key>=k)return lt((*x).left,k);
	return lt((*x).right,k)?:x;
}

node*gt(node*x,int k){
	if(x==NULL)return NULL;
	if((*x).key<=k)return gt((*x).right,k);
	return gt((*x).left,k)?:x;
}

node*T;

int main(){
	int L=100, Q=10;

	T=insert(T,0);
	T=insert(T,L);
	
	int cc[10]={1,2,1,2,1,2,1,2,1,2};
	int xx[10]={31,41,59,26,53,58,97,93,23,84};

	for(int i=0; i<Q; i++){
		int c=cc[i],x=xx[i];

		if(c==1)
			T=insert(T,x);
		else 
			printf("%d\n",(*gt(T,x)).key-(*lt(T,x)).key);
	}
}
