#include<stdio.h>
#include<stdlib.h>
struct node{
    int y;
    struct node *next;
};

typedef struct{
    int x;
    struct node *head;
    //struct node *tail;
}tateline;

// int rectable(tatehen a,tatehen b){
//     if(a.down==b.down&&a.up==b.up){
//         return 1;
//     }
//     return 0;
// }
int main(){
    int N;
    scanf("%d",&N);
    tateline xs[N];
    for(int i=0;i<N;i++){
        xs[i].head=(struct node*)malloc(sizeof(struct node));
        xs[i].head->y=-1;
        //xs[i].tail=xs[i].head;
    }
    int tateLen=0;
    int xx,yy;
    int contf=0;
    for(int i=0;i<N;i++){
        scanf("%d %d",&xx,&yy);
        contf=0;
        for(int j=0;j<tateLen;j++){
            if(xs[j].x==xx){
                struct node *cur=xs[j].head,*buf;
                while(cur->next!=NULL){
                    if(cur->next->y <=yy){
                        cur=cur->next;
                    }else{
                        break;
                    }
                }
                buf=(struct node*)malloc(sizeof(struct node));
                buf->y=yy;
                buf->next=cur->next;
                cur->next=buf;
                contf=1;
                break;
            }
        }
        if(contf==0){
            xs[tateLen].x=xx;
            xs[tateLen].head->next=(struct node*)malloc(sizeof(struct node));
            xs[tateLen].head->next->y=yy;
            //xs[tateLen].tail=xs[tateLen].tail->next;
            tateLen++;
        }
    }
    struct node *icur,*jcur;
    int henCount=0;
    long long int ans=0;
    for(int i=0;i<tateLen;i++){
        for(int j=i+1;j<tateLen;j++){
            icur=xs[i].head->next;
            jcur=xs[j].head->next;
            henCount=0;
            while(jcur!=NULL&&icur!=NULL){
                if(icur->y==jcur->y){
                    henCount++;
                    icur=icur->next;
                    jcur=jcur->next;
                    //printf("f x=%d %d\n",i,j);
                }else if(icur->y > jcur->y){
                    jcur=jcur->next;
                }else{
                    icur=icur->next;
                }
            }
             if(henCount>=2){
                ans+=henCount*(henCount-1)/2;
            }
        }
       
    }

        printf("%lld\n",ans);
    
    return 0;

}