#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No{
    int valor;
    struct No * prox;
}No;

typedef struct Fila{
    No * ini;
    No * fim;
}Fila;

No * newNo(int valor){
    No * aux = (No *)malloc(sizeof(No));
    aux->valor = valor;
    aux->prox = NULL;
    return aux;
}
Fila * newFila(){
    Fila * aux  = (Fila *)malloc(sizeof(Fila));
    aux->ini = NULL;
    aux->fim = NULL;
    return aux;
}

int isEmpty(Fila *f){
    return f->ini==NULL;
}


void add(Fila *f,int valor){
    No * no = newNo(valor);
    if(isEmpty(f)){
        f->ini = no;
        f->fim = no;
    }else{
        f->fim->prox = no;
        f->fim = no;
    }
    
}

int removeFila(Fila *f){
    if(isEmpty(f)){
        printf("Fila Vazia\n");
        exit(0);
    }
    No * aux = f->ini;
    int valor = aux->valor;
    
    if(f->ini==f->fim){
        f->ini=NULL;
        f->fim=NULL;
    }else{
        f->ini = f->ini->prox;
    }
    free(aux);
    return valor;
}


int size(Fila *f){
    int size=0;
    No * aux = f->ini;
    while(aux!=NULL){
        aux=aux->prox;
        size++;
    }
    return size;
}

void print(Fila *f){
    No * aux = f->ini;
    printf("[");
    while(aux!=NULL){
        printf("%d",aux->valor);
        aux = aux->prox;
        if(aux!=NULL){
            printf(",");
        }
    }
    printf("] (%d)\n",size(f));
}




typedef struct FilaSeq{
    int *v;
    int MAX;
    int ini,fim;
}FilaSeq;

FilaSeq * newFilaSeq(int max){
    FilaSeq * f = (FilaSeq*)malloc(sizeof(FilaSeq));
    f->ini = 0;
    f->fim = 0;
    f->MAX = max;
    f->v = (int *)malloc(sizeof(int)*max);
    for(int i=0;i<max;i++){
        f->v[i]=-1;
    }
    return f;
}




int isEmptySeq(FilaSeq *f){
    return f->ini==f->fim;
}

int isFullSeq(FilaSeq *f){
    int aux = (f->fim+1)%f->MAX;
    return aux==f->ini;
}
void addSeq(FilaSeq *f,int valor){
    if(isFullSeq(f)){
        printf("Fila cheia\n");
        exit(0);
    }
    f->v[f->fim]=valor;
    f->fim = (f->fim+1)%f->MAX;
}
int removeSeq(FilaSeq *f){
    if(isEmptySeq(f)){
        printf("Fila vazia\n");
        exit(0);
    }
    int valor = f->v[f->ini];
    f->v[f->ini] = -2;
    f->ini = (f->ini+1)%f->MAX;
    return valor;
}
void printSeq(FilaSeq *f){
    printf("[");
    for(int i = 0;i<f->MAX;i++){
        printf("%d",f->v[i]);
        if(i<f->MAX-1){
            printf(",");
        }
    }
    printf("]\n");
}
void produtor(FilaSeq *f){
    int tarefa = rand()%100;
    addSeq(f,tarefa);
    printf("Add Tarefa %d\n",tarefa);

}
void consumidor(FilaSeq *f){
    if(!isEmptySeq(f)){
        int tarefa = removeSeq(f);
        printf("Processando Tarefa %d\n",tarefa);
    }else{
        printf("Fila Vazia\n");
    }
}
void espera(int n){
    int aux =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                aux++;
            }
        }
    }
}
void executa(){
    FilaSeq * filaImpressao = newFilaSeq(5);
    for(int i=0;i<1000;i++){
        int r = 1+rand()%100;
        if(r<=40){
            produtor(filaImpressao);
        }else{
            consumidor(filaImpressao);
        }
        printSeq(filaImpressao);
        espera(600);
    }
}
int main(){
    /*FilaSeq * f = newFilaSeq(5);
    printSeq(f);
    addSeq(f,3);
    printSeq(f);
    addSeq(f,7);
    printSeq(f);
    addSeq(f,11);
    printSeq(f);
    addSeq(f,9);
    printSeq(f);
    removeSeq(f);
    printSeq(f);
    removeSeq(f);
    printSeq(f);
    removeSeq(f);
    printSeq(f);
    addSeq(f,8);
    printSeq(f);
    addSeq(f,1);
    printSeq(f);
    removeSeq(f);
    printSeq(f);
    removeSeq(f);
    printSeq(f);
    removeSeq(f);
    printSeq(f);
    removeSeq(f);
    printSeq(f);*/
    executa();

}
