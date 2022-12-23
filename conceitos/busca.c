#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int v[],int n){
    int max = 30;
    printf("[");
    for(int i=0;i<n&&i<max;i++){
        printf("%d",v[i]);
        if(i<n-1){
            printf(",");
        }
    }
    printf("](%d)\n",n);
}

void merge(int *v1,int n1,int *v2,int n2,int *v){
    int top1=0,top2=0,top=0;
    while(top1<n1&&top2<n2){
        if(v1[top1]<v2[top2]){
            v[top++]=v1[top1++];
        }else{
            v[top++]=v2[top2++];
        }
    }
    while(top1<n1){
        v[top++]=v1[top1++];
    }
    while(top2<n2){
        v[top++]=v2[top2++];
    }
}


void mergeSort(int v[],int n){
    if(n>1){
        int n1,n2;
        n1 = n/2;
        n2 = n-n1;
        int *v1,*v2;
        v1 = (int *)malloc(sizeof(int)*n1);
        v2 = (int *)malloc(sizeof(int)*n2);

        for(int i=0;i<n1;i++){
            v1[i]=v[i];
        }
        for(int i=0;i<n2;i++){
            v2[i]=v[n1+i];
        }

        mergeSort(v1,n1);
        mergeSort(v2,n2);
        merge(v1,n1,v2,n2,v);
        free(v1);
        free(v2);
    }
}



/*int buscaSeq(int *v,int n,int key){
   
}
*/


void embaralha(int *v, int n){
    int aux,pos;
    for(int i=0;i<n;i++){
        pos = rand()%n;
        aux = v[pos];
        v[pos] = v[i];
        v[i]  = aux;
    }
}
/**
 *int v[] - vetor de inteiros
 *int n - número de elementos do vetor
 *int k - chave de busca
 *Se a chave k ocorrer dentro do vetor v, devolve
 *a posição pos tal que v[pos]==k (primeira ocorrencia).
 *Devolve -1 se k não pertence a v.
 */
int buscaSequencial(int v[], int n, int k){
    for(int i=0;i<n;i++){
        if(v[i]==k){
            return i;
        }
    }
    return -1;
}


/**
 Complexidade Pior Caso Theta(log n)
 Melhor Caso O(1)
 Caso médio: Theta(log n)
 */
int buscaBinariaRecursiva(int v[],int ini, int fim,int key){
    if(fim<ini){
        //não encontrei
        return -1;
    }
    int meio = (ini+fim)/2;
    if(v[meio]==key){
        return meio;
    }
    if(key<v[meio]){
        return buscaBinariaRecursiva(v,ini,meio-1,key);
    }else{
        return buscaBinariaRecursiva(v,meio+1,fim,key);
    }
}

int buscaBinaria(int v[],int n,int key){
    int ini,fim,meio;
    ini = 0;
    fim = n;
    while(ini<=fim){
        //printf("[%d,%d] size=%d\n",ini,fim,fim-ini);
        meio = (ini+fim)/2;
        if(v[meio]==key){
            return meio;
        }
        if(key<v[meio]){
            fim = meio-1;
        }else{
            ini = meio+1;
        }
        
    }
    
    return -1;
}





int repetidos1(int v1[],int n1, int v2[], int n2){
    int size = 0,valor1;
    for(int i=0;i<n1;i++){
        valor1 = v1[i];
        //buscar valor1 dentro do vetor v2
        if(buscaSequencial(v2,n2,valor1)>=0){
                size++;
        }
    }
    return size;
}

//cte * n2*lg(n2)+cte*n1*log n2 = cte*(n1+n2)lg n2
int repetidos2(int v1[],int n1, int v2[], int n2){
    int size = 0,valor1;
    mergeSort(v2, n2);// Theta(n2 lg n2)
    for(int i=0;i<n1;i++){ //Theta (n1 log n2)
        valor1 = v1[i];
        //buscar valor1 dentro do vetor v2 =  Theta(lg n2)
        if(buscaBinaria(v2,n2, valor1)>=0){
                size++;
        }
    }
    return size;
}

int Busca(int v[],int ini, int fim, int key){
    if(fim < ini){
        return -1;
    }
    int n = fim - ini;
    int p1 = ini + (n/3);
    int p2 = ini + ((2*n)/3);
    if(key == v[p1] || key == v[p2]){
       int result = (key == v[p1]) ?  p1 :  p2;
       return result;
    }
    else if(key < v[p1]){
          return Busca(v,ini,p1 - 1,key);
          }
          else if(v[p1] < key && key < v[p2]){
            return Busca(v,p1+1,p2 - 1,key);
          }
          else if(key > v[p2]){
           return Busca(v,p2+1,fim,key);
          }
}

void RGS(){
    int n1 = 40*1000*1000;
    int * SP;
    SP = (int *)malloc(sizeof(int)*n1);
    int n2 = 11*1000*1000;
    int * PR;
    PR = (int *)malloc(sizeof(int)*n2);
    for(int i=0;i<n1;i++){
        SP[i] = i*73;
    }
    embaralha(SP, n1);
    for(int i=0;i<n2;i++){
        PR[i] = i*79;
    }
    embaralha(PR, n2);
    print(SP,n1);
    print(PR,n2);
    
    //Tempo(n1,n2) = n1*n2*cte s
    //15   = 70.000*70.000*cte
    //cte = 15/70.000^2 = 3.06e-9
    //Tempo(n1,n2) = n1*n2*3.06e-9 s
    printf("Tempo_formula (n1*n2) = %.1lf s",(1.0*n1*n2*2.24e-9));
    printf(" %.1lf dias\n",(1.0*n1*n2*2.24e-9)/(3600.0*24.0));
    
    time_t start,end;
    time (&start);
    int x = repetidos2(SP,n1, PR, n2);
    time (&end);
    double dif = difftime (end,start);
    printf("size = %d Tempo Real= %.1lfs\n",x,dif);
    
            
}

void busca(){
    srand(5);
    int n = 1000*1000;
    int *v = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        v[i] = rand()%n;
    }
    print(v,n);
    mergeSort(v,n);
    print(v,n);
    int size = 100;
    while(1){
        
        time_t start,end;
        time (&start);
        
        
        
        for(int i=0;i<size;i++){
            int key = rand()%n;
            buscaBinaria(v, n, key);
            //printf("Busca %d na pos %d\n",key,pos);
        }
        size = size*10;
        time (&end);
        double dif = difftime (end,start);
        printf("size %d Tempo = %.1lfs\n",size,dif);
    }
}

int main() {
    //busca();
   // RGS();
    //int n = 4;
    int v[] = {1,2,3,5,6};
    int result = Quest4(v,0,4,6);
    printf("%d",result);
    //print(v,n);
    //
}
   
