#include<stdio.h>

int first[10],succ[10],V[10],ec;
int que[10],l,r,dist[10],cnt[10]={0,1};

void add_edge(int u,int v){
	succ[++ec]=first[u];
	first[u]=ec;
	V[ec]=v;
}

int main(){

	for(int i=0;i<10;i++)
		dist[i]=1<<30;
	
	int N=4;
	int M=5;

	int aa[]={2,1,2,1,3};
	int bb[]={4,2,3,3,4};

	for(int i=0;i<M;i++){
		int a=aa[i],b=bb[i];
		add_edge(a,b);	// globalな配列変数succ, first, Vに値を代入
		add_edge(b,a);
	}

	que[r++]=1;
	
	dist[1]=0;

	while(l!=r){
		int u=que[l++];
		if(u==N)break;
		for(int id=first[u],v;v=V[id];id=succ[id]){
			if(dist[v]==1<<30){
				dist[v]=dist[u]+1;
				cnt[v]=cnt[u];
				que[r++]=v;
			}else if(dist[v]==dist[u]+1){
				cnt[v]+=cnt[u];
				if(cnt[v]>=1000000007)
					cnt[v]-=1000000007;
			}
		}
	}
	printf("%u\n",cnt[N]);
}
