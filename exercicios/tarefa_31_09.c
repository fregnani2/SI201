#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No{
    int valor;
    struct No * prox;
}No;

typedef struct Lista{
    No * ini;
}Lista;

No * newNo(int valor){
    No * aux = (No *)malloc(sizeof(No));
    aux->valor = valor;
    aux->prox = NULL;
    return aux;
}
Lista * newLista(){
    Lista * aux  = (Lista *)malloc(sizeof(Lista));
    aux->ini = NULL;
    return aux;
}

int isEmpty(Lista *f){
    return f->ini==NULL;
}


void addFim(Lista *f,int valor){
    No * no = newNo(valor);
    if(isEmpty(f)){
        f->ini = no;
    }else{
        No * aux = f->ini;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    
}


int size(Lista *li){
    int size=0;
    No * aux = li->ini;
    while(aux!=NULL){
        aux=aux->prox;
        size++;
    }
    return size;
}

void print(Lista *li){
    No * aux = li->ini;
    printf("[");
    while(aux!=NULL){
        printf("%d",aux->valor);
        aux = aux->prox;
        if(aux!=NULL){
            printf(",");
        }
    }
    printf("] (%d)\n",size(li));
}

No * get(Lista *li,int pos){
    if(isEmpty(li)){
        printf("Fora dos limites da lista\n");
        exit(0);
    }
    No * aux = li->ini;
    for(int i=0;i<pos;i++){
        aux = aux->prox;
        if(aux==NULL){
            printf("Fora dos limites da lista\n");
            exit(0);
        }
    }
    return aux;
}

int removeProximo(No *aux){
    No * x = aux->prox;
    if(x==NULL){
        printf("Fora dos limites da lista\n");
        exit(0);
    }
    int v = x->valor;
    aux->prox = aux->prox->prox;
    free(x);
    return v;
}

int pop(Lista *li,int pos){
    if(pos>0){
        No * aux = get(li, pos-1);
        return removeProximo(aux);
    }
    No * x = li->ini;
    if(x==NULL){
        printf("Fora dos limites da lista\n");
        exit(0);
    }
    int v = x->valor;
    li->ini = li->ini->prox;
    free(x);
    return v;
}

int removeLista(Lista *li, int k){
    No * temp = li->ini;
    while(temp->valor != k){
        temp = temp->prox;
    }
    if(temp == li->ini){
        free(temp);
        li->ini = NULL;
    }else{
        No * aux = li->ini;
        while(aux->prox != temp){
            aux = aux->prox;
        }
        aux->prox = temp->prox;
        free(temp);
    }
}

int removeTodos(Lista *li, int k){
    No * temp = li->ini;
    while(temp != NULL){
        if(temp->valor == k){
            No * prev = li->ini;
            while(prev->prox != temp){
                prev = prev->prox;
            }
            No * aux = temp;        
            prev->prox = temp->prox;
            free(aux);
            temp = li->ini;
        }
        else{
            temp = temp->prox;
    }
    
}
}

void add(Lista *li, int valor,int pos){
    No * x = newNo(valor);
    if(pos==0){
        x->prox = li->ini;
        li->ini = x;
        
    }else{
        No * p = get(li,pos-1);
        x->prox = p->prox;
        p->prox = x;
    }
}

void push2(Lista *li, int valor){
No * no = newNo(valor);
No * aux = li->ini;
while(aux->prox!=NULL){
aux = aux->prox;
}
aux->prox = no;
}

void addOrdenado(Lista *li, int valor){
    No * x = newNo(valor);
    if(li->ini==NULL || valor<li->ini->valor){
        x->prox = li->ini;
        li->ini = x;
        
    }else{
        No * p = li->ini;
        while(p->prox!=NULL && p->prox->valor<valor){
            p=p->prox;
        }
        x->prox = p->prox;
        p->prox = x;
    }
}




void set(Lista *li, int valor,int pos){
    No * aux = get(li,pos);
    aux->valor=valor;
}

void concat(Lista *l1, Lista *l2){
    if(isEmpty(l1)){
        l1->ini=l2->ini;
    }else{
        No * aux = l1->ini;
        while(aux->prox!=NULL){
            aux=aux->prox;
        }
        aux->prox=l2->ini;
    }
}


int main(){
    
    Lista * li = newLista();
    addOrdenado(li,1);
    addOrdenado(li,2);
    addOrdenado(li,3);

    print(li);
    removeLista(li,3);
    print(li);

}