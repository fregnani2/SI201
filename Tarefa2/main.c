/* GRUPO:
Bruno Fregnani 254179
Felipe Costa 254214
João Rodrigo 254267
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct PilhaSeq{
    int *v;
    int max,top;
}PilhaSeq;

PilhaSeq * newPilhaSeq(int max){
    PilhaSeq * aux = (PilhaSeq *)malloc(sizeof(PilhaSeq));
    aux->v = (int *)malloc(sizeof(int)*max);
    aux->max=max;
    aux->top=0;
    return aux;
}

void pushSeq(PilhaSeq *p,int x){
    if(p->top==p->max){
        printf("Pilha Cheia\n");
        exit(1);
    }
    
    p->v[p->top++]=x;
}

int popSeq(PilhaSeq *p){
    if(p->top==0){
        printf("Pilha Vazia\n");
        exit(1);
    }
    return p->v[--p->top];
}

int isEmptySeq(PilhaSeq * p){
    return p->top==0;
}

int sizeSeq(PilhaSeq *p){
    return p->top;
}

void printSeq(PilhaSeq *p){
    printf("(");
    for(int i=p->top-1;i>=0;i--){
        printf("%d",p->v[i]);
        if(i>0){
            printf("->");
        }
    }
    printf(")\n");
}

typedef struct No{
    int valor;
    struct No * prox;
}No;

typedef struct Pilha{
    No * raiz;
}Pilha;

Pilha * newPilha(){
    Pilha * aux = (Pilha *)malloc(sizeof(Pilha));
    aux->raiz = NULL;
    return aux;
}

int isEmpty(Pilha * p){
    return p->raiz==NULL;
}

No * newNo(int valor){
    No * aux = (No*)malloc(sizeof(No));
    aux->valor=valor;
    aux->prox=NULL;
    return aux;
}

void push(Pilha *p, int valor){
    No * no = newNo(valor);
    no->prox = p->raiz;
    p->raiz = no;
}

int pop(Pilha *p){
    
    if(isEmpty(p)){
        printf("Pilha Vazia\n");
        exit(6);
    }
    
    No * aux = p->raiz;
    p->raiz = p->raiz->prox;
    int valor = aux->valor;
    free(aux);
    return valor;
}



int size(Pilha *p){
    int size=0;
    No * aux = p->raiz;
    while(aux!=NULL){
        size++;
        aux=aux->prox;
    }
    return size;
}

void print(Pilha *p){
    No * aux = p->raiz;
    while(aux!=NULL){
        printf("%d",aux->valor);
        aux=aux->prox;
        if(aux!=NULL){
            printf("->");
        }
    }
    printf(" [%d]\n",size(p));
}

int isBalanced(char * texto){
    Pilha * p = newPilha();
    for(int i=0;texto[i]!='\0';i++){
        switch (texto[i]) {
            case '(':
                push(p,texto[i]);
                break;
            
            case ')':
                if(isEmpty(p)) {return 0;}
                if(pop(p) != '('){
                    return 0;
                }
                break;

            case '[':
                push(p,texto[i]);
                break;
            
            case ']':
                if(isEmpty(p)) {return 0;}
                 if(pop(p) != '['){
                    return 0;
                } 
                break;

            case '{':
                push(p,texto[i]);
                break;
            
            case '}':
                if(isEmpty(p)) {return 0;}
                if(pop(p) != '{'){
                    return 0;
                } 
                break;  

            default:
                break;
        }
       
    }
    return isEmpty(p);
}

int main() {
    Pilha * p = newPilha();
    char texto[100];
    strcpy(texto,"((((((((((((((((((((((((((((((((((((([[[[[[[[[[[[[[]]]]]]]]]]]]]])))))))))))))))))))))))))))))))))))))");
    if(isBalanced(texto)){
        printf("Balanceados\n");
    }else{
        printf("Nao Balanceados\n");
    }

}
