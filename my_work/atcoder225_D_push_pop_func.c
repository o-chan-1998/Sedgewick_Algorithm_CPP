#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define NUM_MAX 100

typedef struct{
    int* pData;
    int tail;
    int thisNum;
}Stack_t;

//スタックの中身をprint出力
void printStack(Stack_t* pStack){
    int i;
    for(i = 0; i < SIZE * pStack->thisNum; i++){
        printf("%d ", pStack->pData[i]);
    }
    printf("\n");
}

//初期化関数
int initStack(Stack_t* pStack){
    int i;    
    
    pStack->pData = (int*)malloc(sizeof(int) * SIZE);
    if(pStack->pData == NULL){
        printf("malloc error\n");
        return -1;
    }
    //スタックの中身を0埋め
    for(i = 0; i < SIZE; i++){
        pStack->pData[i] = 0;
    }
    //初期化時は空なのでtailは-1とする
    pStack->tail = -1;
    //初期化時はスタック1個分なので1とする
    pStack->thisNum = 1;
    
    printStack(pStack);
    
    return 0;
}

//push関数
int push(Stack_t* pStack, int value){
    int* pTmp;
    int i;

    //スタックがFullの処理    
    if(pStack->tail >= SIZE * NUM_MAX - 1){
        printf("Full\n");
        printStack(pStack);
        return 0;
    }
    
    //スタックの拡張
    if(pStack->tail >= SIZE * pStack->thisNum - 1){
        printf("Upsize stack\n");
        pStack->thisNum++;
        pTmp = (int*)realloc(pStack->pData, sizeof(int) * SIZE * pStack->thisNum);
        if(pTmp == NULL){
            printf("realloc error\n");
            return -1;
        }else{
            pStack->pData = pTmp;
            for(i = pStack->tail + 1; i < SIZE * pStack->thisNum; i++){
                pStack->pData[i] = 0;
            }
        }
    }
    
    //Push操作
    pStack->tail++;
    pStack->pData[pStack->tail] = value;
    
    printStack(pStack);
    
    return 0;
}

//pop関数
int pop(Stack_t* pStack){
    int* pTmp;
    
    //スタックがEmptyの処理
    if(pStack->tail <= -1){
        printf("Empty\n");
        return 0;
    }
    
    //スタックの縮小
    if(pStack->thisNum > 1 && pStack->tail <= SIZE * (pStack->thisNum - 1)){
        printf("Downsize stack\n");
        pStack->thisNum--;
        pTmp = (int*)realloc(pStack->pData, sizeof(int) * SIZE * pStack->thisNum);
        if(pTmp == NULL){
            printf("realloc error\n");
            return -1;
        }else{
            pStack->pData = pTmp;
        }
    }        

    //Pop操作
    pStack->pData[pStack->tail] = 0;
    pStack->tail--;

    printStack(pStack);
    
    return 0;
}

//終了関数
int deleteStack(Stack_t* pStack){
    free(pStack->pData);
    
    return 0;
}

int main(){
    Stack_t Stack;
    Stack_t* pStack = &Stack;
    
    initStack(pStack);

    pop(pStack);
    push(pStack, 1);
    push(pStack, 2);
    push(pStack, 3);
    push(pStack, 4);
    push(pStack, 5);
    push(pStack, 6);
    push(pStack, 7);
    push(pStack, 8);
    pop(pStack);
    pop(pStack);
    pop(pStack);
    pop(pStack);
    push(pStack, 3);
    push(pStack, 4);
    push(pStack, 5);
    push(pStack, 6);
    push(pStack, 7);
    pop(pStack);
    pop(pStack);
    pop(pStack);
    pop(pStack);
    pop(pStack);
    pop(pStack);
    pop(pStack);
    pop(pStack);    
    push(pStack, 1);
    push(pStack, 2);
    push(pStack, 3);
    push(pStack, 4);
    push(pStack, 5);
    push(pStack, 6);
    push(pStack, 7);
    push(pStack, 8);

    deleteStack(pStack);
    
    return 0;
}