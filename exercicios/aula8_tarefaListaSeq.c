#include <stdio.h>
#include <stdlib.h>


typedef struct ListaSeq{
    int *v;
    int MAX;
    int top;
}ListaSeq;

ListaSeq * newListaSeq(int max){
    ListaSeq * f = (ListaSeq*)malloc(sizeof(ListaSeq));
    f->top = 0;
    f->MAX = max;
    f->v = (int *)malloc(sizeof(int)*max);
    for(int i=0;i<max;i++){
        f->v[i]=-1;
    }
    return f;
}



void printSeq(ListaSeq *li){
    printf("[");
    for(int i = 0;i<li->top;i++){
        printf("%d",li->v[i]);
        if(i<li->top-1){
            printf(",");
        }
    }
    printf("]\n");
}

//• Faça uma função que encontra a posição da primeira aparição de uma chave k em uma lista sequencial:

int findKeyPosition(ListaSeq *li, int key){
    if(li->v[0] == key){
        return -1;
    }
    else{
        for(int i = 0; i<li->top;i++){
            if(li->v[i] == key){
                return i;
            }
        }
        return -1;
    }
}

int main(){
    ListaSeq * aux = newListaSeq(100);
    aux->v[aux->top++] = 10;
    aux->v[aux->top++] = 20;
    aux->v[aux->top++] = 30;
    aux->v[aux->top++] = 20;
    printSeq(aux);
    int posicao = 0;
    posicao = findKeyPosition(aux,30);
    printf("%d", posicao);

}
