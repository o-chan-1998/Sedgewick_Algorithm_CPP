//bfs
#include <stdio.h>

int max=0,max1=0,max2=0,cnt1=0,cnt2=0;


int main(){
    int h=3,w=4;

	int c[5][5],d[5][5]={0};
    int max=0,i,j;
    char *ch[101]={".#..","..#.","..##"};

	d[0][0]=1;

    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(ch[i][j]=='.') 
				c[i][j]=0;	// .を0に置き換える
            else 
				c[i][j]=1;	// #を1に置き換える
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){

            if(c[i][j]==1 || d[i][j]==0)
				continue;

            if(max<d[i][j])
				max=d[i][j];

			// d[i][1]=d[i][0]+1
			// d[i][2]=d[i][1]+1
			// d[i][3]=d[i][2]+1
			// d[i][4]=d[i][3]+1
			d[i][j+1]=d[i][j]+1;
			// d[i+1][0]=d[i][1]+1
			// d[i+1][1]=d[i][2]+1
			// d[i+1][2]=d[i][3]+1
			// d[i+1][3]=d[i][4]+1
            d[i+1][j]=d[i][j+1];

        }
    }


    printf("%d\n",max);

    return 0;
    
}