#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct No {
    int valor;
    struct No *esq, *dir;
}No;

No * newNo(int valor){
    No * no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

typedef struct Tree {
    No * raiz;
}Tree;

Tree * newTree(){
    Tree * t = (Tree *)malloc(sizeof(Tree));
    t->raiz = NULL;
    return t;
}
/**
 Insere o valor ná árvore.
 no não pode ser NULL (por definição).
 */
void addNo(No* no, int valor){
    if(valor<=no->valor){
        //insere na sub-árvore à esquerda
        if(no->esq!=NULL){
            addNo(no->esq,valor);
        }else{
            no->esq = newNo(valor);
        }
    }else{
        //insere na sub-árvore à direita
        if(no->dir!=NULL){
            addNo(no->dir,valor);
        }else{
            no->dir = newNo(valor);
        }
    }
}

void addTree(Tree *t, int valor){
    if(t->raiz==NULL){
        t->raiz = newNo(valor);
    }else{
        addNo(t->raiz,valor);
    }
}

void addTreeIt(Tree *t, int valor){
    if(t->raiz==NULL){
        t->raiz = newNo(valor);
        return;
    }
    No * aux = t->raiz;
    int inseriu = FALSE;
    while(!inseriu){
        if(valor<aux->valor){
            if(aux->esq!=NULL){
                //descer para o ramo esquerdo
                aux=aux->esq;
            }else{
                aux->esq = newNo(valor);
                inseriu=TRUE;
            }
        }else{
            if(aux->dir!=NULL){
                //descer para o ramo direito
                aux=aux->dir;
            }else{
                aux->dir = newNo(valor);
                inseriu=TRUE;
            }
        }
    }
}


void printNo(No * no){
    if(no==NULL){
        return;
    }
    printNo(no->esq);
    printf("%d,",no->valor);
    printNo(no->dir);
}

void printTree(Tree *t){
    printf("[");
    printNo(t->raiz);
    printf("]\n");
}

void printNoXML(No *no,FILE * fp){
    
    fprintf(fp,"%d\n",no->valor);
    
    if(no->esq!=NULL){
        fprintf(fp,"<esq>\n");
        printNoXML(no->esq,fp);
        fprintf(fp,"</esq>\n");
    }
    
    if(no->dir!=NULL){
        fprintf(fp,"<dir>\n");
        printNoXML(no->dir,fp);
        fprintf(fp,"</dir>\n");
    }
    
    
}

void printTreeXML(Tree *t){
    
    FILE * fp = fopen("Tree.xml","w+");
    
    fprintf(fp,"<tree>\n");
    printNoXML(t->raiz,fp);
    fprintf(fp,"</tree>\n");
    fclose(fp);
}

typedef struct Lista{
    int *v;
    int top,max;
}Lista;

Lista * newLista(int max){
    Lista * l = (Lista *)malloc(sizeof(Lista));
    l->top = 0;
    l->max = max;
    l->v = (int *)malloc(sizeof(int)*max);
    return l;
}

void addLista(Lista *l,int valor){
    if(l->top==l->max){
        printf("Cheio\n");
    }
    l->v[l->top++]=valor;
}

void TreeToVector(No * no, Lista *l){
    if(no==NULL){
        return;
    }
    TreeToVector(no->esq,l);
    addLista(l,no->valor);
    TreeToVector(no->dir,l);
}

void freeLista(Lista *l){
    free(l->v);
    free(l);
}


void TreeSort(Lista *l){
    if(l->top<=1){
        return ;
    }
    Tree *t  = newTree();
    for(int i=0;i<l->top;i++){
        addTree(t,l->v[i]);
    }
    //deixar o vetor vazio.
    l->top=0;
    TreeToVector(t->raiz,l);
	// faltou dar free em t.
    
}

void printLista(Lista *l){
    printf("[");
    for(int i=0;i<l->top;i++){
        printf("%d",l->v[i]);
        if(i<l->top-1){
            printf(",");
        }
    }
    printf("]\n");
}

int maximoRecursivo(No * no){
    return 0;
}

int maximoIt(No * no){
    if(no==NULL){
        printf("ERRO 396\n");
        exit(0);
    }
    No * aux = no;
    while(aux->dir!=NULL){
        aux = aux->dir;
    }
    return aux->valor;
}

int main(int argc, const char * argv[]) {
    
    Tree * t = newTree();
    
    addTreeIt(t, 6);
    addTreeIt(t, 8);
    addTreeIt(t, 2);
    addTreeIt(t, 10);
    addTreeIt(t, 7);
    addTreeIt(t, 1);
    addTreeIt(t, 3);
    
    
    
    printTree(t);
    
    printTreeXML(t);
    
    printf("Maximo %d\n",maximoIt(t->raiz));
     
     /*
    
    Lista *l = newLista(100);
    addLista(l, 3);
    addLista(l, 2);
    addLista(l, 1);
    addLista(l, 4);
    addLista(l, 5);
    addLista(l, 10);
    addLista(l, 0);
    
    TreeSort(l);
    printLista(l);
    
    
    */
    
    return 0;
}




/**
 Tarefa 1: Faça uma função de Busca que encontra todos os nós com valores iguais a k. Salve estes valores em uma lista e de return neles.
 
 Tarefa 2: Faça um código para remover um nó da árvore de busca. Após a remoção, a árvore precisa se manter uma árvore binária de busca. Se tiver vários iguais, remover o primeiro.
 
 Tarefa 3) Faça um TreeSort usando lista ligada ao invés de vetor. Se possível, não consulte nenhum código anterior nesta tarefa.
 
 Tarefa 4) Qual a complexidade do algoritmo TreeSort no pior caso? Você tem uma estratégia para não evitar o pior caso e conseguir um Theta(n log n).
 
 
 Tarefa 5) Implementar o maximo recursivo e mínimo iterativo e recursivo.

Tarefa 6) O método TreeSort está com vazamento de memória. Faça o free para liberar a memória utilizada pela árvore.
 */