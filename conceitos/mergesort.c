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

/**
 Encontra a posição do maior elemento do vetor.
 Gasta Theta(n).
 Vetor inicia em v[0] e termina em v[n-1].
 */
int maximo(int v[],int n){
    int pos_max = 0;
    for(int i=1;i<n;i++){
        if(v[i]>v[pos_max]){
            pos_max=i;
        }
    }
    return pos_max;
}

void selectionSort1(int v[],int n){
    while(n>1){
        print(v,n);
        int pos_max = maximo(v,n);
        int aux = v[pos_max];
        v[pos_max] = v[n-1];
        v[n-1]=aux;
        print(v,n);
        n--;
    }
}

void selectionSort2(int v[],int n){
    if(n>1){
        print(v,n);
        int pos_max = maximo(v,n);
        int aux = v[pos_max];
        v[pos_max] = v[n-1];
        v[n-1]=aux;
        print(v,n);
        selectionSort2(v,n-1);
    }
}

void insertionSort1(int v[],int noriginal){
    int n=2;
    while(n<=noriginal){
        int aux = v[n-1];
        int i = n-2;
        int lixo = -1;
        //print(v,n);
        while(i>=0&&v[i]>aux){
            v[i+1]=v[i];
            v[i]=lixo;
            i--;
            //print(v,n);
        }
        i++;
        v[i] = aux;
        //print(v,n);
        n++;
        if(n%1000==0){
            printf("%d\n",n);
        }
    }
}


void insertionSort2(int v[],int n){
    if(n>1){
        insertionSort2(v,n-1);
    
        int aux = v[n-1];
        int i = n-2;
        int lixo = -1;
        print(v,n);
        while(i>=0&&v[i]>aux){
            v[i+1]=v[i];
            v[i]=lixo;
            i--;
            print(v,n);
        }
        i++;
        v[i] = aux;
        print(v,n);
    }
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



int main() {
    srand(2);
    int n=5*1000*1000;
    //int n=160*1000;
    int *v;
    v = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        v[i] = rand()%n;
    }
    print(v,n);
    time_t start,end;
    time (&start);
    insertionSort1(v,n);
    //mergeSort(v,n);
    time (&end);
    double dif = difftime (end,start);
    printf("%lf segundos  \n",dif);
    print(v,n);
       
    /*time_t start,end;
    time (&start);
    time (&end);
    double dif = difftime (end,start);
    printf("%lf  \n",dif);*/
    
}
   