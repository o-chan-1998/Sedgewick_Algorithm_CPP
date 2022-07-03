#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int d[10][10];
char C[111][111];

int rec(int i,int j){
	d[i][j]=d[i][j];
	if(C[i][j]=='.'){
		return max(rec(i+1,j),rec(i,j+1))+1;
	}else{
		return 0;
	}
}

int main(){
	int W=3;
	int H=4;
	char *str_temp[3]={".#..","..#.","..##"};

	for(int i=0;i<W;i++){
		for(int j=0;j<H;j++)
			C[i][j] = str_temp[i][j];
	}

	printf("%d\n",rec(0,0));
}