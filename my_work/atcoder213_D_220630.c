#include<stdio.h>
#include<stdlib.h>

// ※要デバッグ！！


int cmp(const void *a, const void *b){
	return *(long*)a>*(long*)b ? 1:-1;
}

int fst[1<<18];
long es[1<<19];

void dfs(int v,int p){
	printf("%d ",v);
	for(int i=fst[v];(es[i]>>20)==v;i++){
		int u=es[i]&(1<<20)-1;
		if(u!=p){
			dfs(u,v);
			printf("%d ",v);
		}
	}
}

int main(){
	int N = 4;
	long aa[5]={1,4,3}, bb[5]={2,2,1};

	int sz=0;
	for(int i=1;i<N;i++){
		long A=aa[i],B=bb[i];
		es[sz++]=A<<20|B;
		es[sz++]=B<<20|A;
	}
	qsort(es,sz,8,cmp);
	for(;sz--;)fst[es[sz]>>20]=sz;
	dfs(1,1);
	puts("");
}
