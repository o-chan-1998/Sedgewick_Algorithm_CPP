#include <stdio.h>

void swap(long *x,long *y){
	long t = *x;
	*x = *y;
	*y = t;
}

void push(long *arr,long k){
	arr[++*arr]=k;
	for(long i=*arr; i>1 && arr[i]<arr[i/2]; i/=2){
		swap(arr+i,arr+i/2);
	}
}

long pop(long *arr){
	long res=arr[1];
	arr[1]=arr[(*arr)--];
	for(long i=1;;){
		if(i*2 <= *arr && arr[i] > arr[i*2] && (i*2==*arr || arr[i*2] <= arr[i*2+1])){
			swap(arr+i,arr+i*2);
			i=i*2;
		}else if(i*2+1 <= *arr && arr[i] > arr[i*2+1] && arr[i*2+1] < arr[i*2]){
			swap(arr+i,arr+i*2+1);
			i=i*2+1;
		}else break;
	}
	return res;
}


int main(){
	int Q=5;
	int target_que[10][2]={{1,3},{1,5},{3,-1},{2,2},{3,-1}};
	
	long heap[10]={0},S;

	for(int i=0; i<Q; i++){
		int t = target_que[i][0];
		if(t==3)
			printf("%ld\n",pop(heap)+S);
		else{
			long X = target_que[i][1];
			if(t==1)
				push(heap,X-S);
			else 
				S+=X;
		}
	}
}
