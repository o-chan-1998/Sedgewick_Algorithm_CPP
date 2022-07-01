#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* UF(int N){
	int* res = (int*)malloc(sizeof(int) * N);
	for(int i=0; i<N; i++) res[i] = -1;
	return res;
}
int find(int *ary, int x){
	if(ary[x] < 0) return x;
	return ary[x] = find(ary, ary[x]);
}
bool unite(int *ary, int x, int y){
	x = find(ary, x); y = find(ary, y);
	if(x == y) return false;
	if(ary[x] > ary[y]){
		int tmp = x;
		x = y;
		y = tmp;
	}
	ary[x] += ary[y];
	ary[y] = x;
	return true;
}
bool same(int *ary, int x, int y){return find(ary, x) == find(ary, y);}
int size(int *ary, int x){return -ary[find(ary, x)];}

int w[5]={1,2,5,14};

int cmp(const void *a, const void *b) { 
	return *(const int *)a - *(const int*)b; 
}

long ans;

int main(){
	int N=5;

	int u[5]={1,2,4,3};
	int v[5]={2,3,2,5};
	int idx[5]={};
	for(int i=0;i<N-1;i++){
		idx[i]=10-i;
	}

	qsort(idx,N-1,sizeof(idx[0]),cmp);
	
	int*uf=UF(N+1);
	for(int i=0;i<N-1;i++){
		int j=idx[i];
		ans+=(long)w[j]*size(uf,u[j])*size(uf,v[j]);
		unite(uf,u[j],v[j]);
	}
	printf("%ld\n",ans);
}
