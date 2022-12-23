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



int removeTodos(Lista *li, int k){
    No * temp = li->ini;
    while(temp != NULL){
        if(temp->valor == k){
            if(temp == li->ini){
                li->ini = temp->prox;
                free(temp);
                temp = li->ini;
            }else{
                No * prev = li->ini;
                while(prev->prox != temp){
                    prev = prev->prox;
                }
                No * aux = temp;        
                prev->prox = temp->prox;
                free(aux);
                temp = li->ini;}
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

//Faca uma funcão que encontra a posi ̧c ̃ao da primeira apari ̧c ̃ao de uma chave k 
int findFirstPosition(Lista *li, int value){
     if(isEmpty(li)){
         return -1;
    }
    else{
        No * aux = li->ini;
        int pos = 0;
        while(aux->valor != value && aux->prox != NULL){
            pos += 1;
            aux = aux->prox;
        }
        if(aux->valor != value){
            return -1;
        }
        else return pos;
    }
}

//Numa lista ligada, fa ̧ca uma fun ̧c ̃ao que, dada uma chave k, devolve o n ́o que precede a primeira
//apari ̧c ̃ao da chave k 
No * findPreviousNode(Lista *li, int k){
    if(isEmpty(li) || li->ini->valor == k){
        return NULL;
    }
    else{
        No * aux = li->ini;
        while(aux->prox->valor != k && aux->prox != NULL){
            aux = aux->prox;
        }
        if(aux->prox->valor == k){
            return aux;
        }
        else return NULL;
    }
}

//Remove primeira aparição de K da lista
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

//Fa ̧ca uma fun ̧c ̃ao add que recebe uma posi ̧c ̃ao pos e uma chave k
//e insere k na posi ̧c ̃ao pos.
void addPos(Lista *li, int pos, int k){
    No * no = newNo(k);
    if(pos == 0){
        no->prox = li->ini->prox;
        li->ini = no; 
    }
    else{
        No * aux = li->ini;
        for(int i = 1; i < pos; i++){
            aux = aux->prox;
        }
        no->prox = aux->prox;
        aux->prox = no;
    }
}

//Adicionar chave k ordenadamente na lista
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

Lista * multiplica(Lista * l1, Lista * l2){
    int sizel1= 0;
    int sizel2 = 0;
    No * aux1 = l1->ini;
    No * aux2 = l2->ini;
    while(aux1->prox != NULL){
        sizel1++;
        aux1 = aux1->prox;
    }
    while(aux2->prox != NULL){
        sizel2++;
        aux2 = aux2->prox;
    }
    if(sizel1 != sizel2){
        printf("Listas de tamanho diferentes");
        return -1;
    }
    else{
        Lista * l3 = newLista();
        No * temp1 = l1->ini;
        No * temp2 = l2->ini;
        while (temp1 != NULL){
            if(l3->ini == NULL){
                l3->ini = newNo(temp1->valor * temp2->valor);
                temp1 = temp1->prox;
                temp2 = temp2->prox;
            }else{
                No * aux = l3->ini;
                while(aux->prox!= NULL){
                    aux = aux->prox;
                }
                aux->prox = newNo(temp1->valor * temp2->valor);
                temp1 = temp1->prox;
                temp2 = temp2->prox;
            }
        }
        return l3;
    }
    
}

No * Quest1(No* l1, No * l2){
    int sizeL1 = 0;
    int sizeL2 = 0;
    No * calcSize1 = l1;
    No * calcSize2 = l2;
    while (calcSize1->prox != NULL){
        sizeL1++;
        calcSize1 = calcSize1->prox;
    }
    while (calcSize2->prox != NULL){
        sizeL2++;
        calcSize2 = calcSize2->prox;
    }    
    if (sizeL1 != sizeL2){
        printf("Listas de tamanhos diferentes");
        exit(0);
    }
    else{
    No * aux1 = l1;
    No * aux2 = l2;
    No * l3 = (No *)malloc(sizeof(No));
    l3->valor = (l1->valor * l2->valor);
    l3->prox = NULL;
    aux1 = aux1->prox;
    aux2 = aux2->prox;
    while(aux1 != NULL){
        No * temp = l3;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        No * ultimo = (No *)malloc(sizeof(No));
        ultimo->valor = (aux1->valor * aux2->valor);
        ultimo->prox = NULL;
        temp->prox = ultimo;
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return l3;
    }
}

int main(){
    
    Lista * li = newLista();
    addOrdenado(li,1);
    addOrdenado(li,2);
    addOrdenado(li,3);
    addOrdenado(li,4);

    Lista * l2 = newLista();
    addOrdenado(l2,1);
    addOrdenado(l2,1);
    addOrdenado(l2,3);
    addOrdenado(l2,4);
   


    Lista * l3 = multiplica(li,l2);
    print(l3);

    // No * no1 = newNo(1);
    // No * no2 = newNo(2);
    // No * no3 = newNo(3);
    // no1->prox = no2;
    // no2->prox = no3;

    // No * no4 = newNo(1);
    
    // No * no5 = newNo(2);
    // No * no6 = newNo(3);
    // No * no7 = newNo(9);
    // no4->prox = no5;
    // no5->prox = no6;
    // no6->prox = no7;

    // No * result = Quest1(no1,no4);
    // printf("%d",result->prox->prox->valor);
    // print(li);
    // int pos = findFirstPosition(li,1);
    // printf("Posicao da primeira aparicao de K: %d\n",pos);

    // No * a = findPreviousNode(li,2);
    // printf("No anterior : %d\n",a->valor);
    
    // printf("Remover chave k da lista : \n");
    // removeLista(li,3);
    // print(li);
    
    // printf("Adicionar chave k em uma posicao n da lista: \n");
    // addPos(li,2,8);
    // print(li);


}