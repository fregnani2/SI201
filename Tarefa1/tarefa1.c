#include <stdio.h>
#include <stdlib.h>


int max(int *v, int n){
    int maxValue = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] > maxValue){
            maxValue = v[i];
        }
    }
    return maxValue;
}

//Complexidade Teta(n^2)
void ordena(int v[],int n){
    while(n>2){
        int m = max(v,n);//cte*n
        int aux = v[m];//1
        v[m] = v[n-1];//1
        v[n-1] = aux;//1
        n--;
    }
}

/**Complexidade Teta(n) */
void gera(int v[],int n,int max){
    for(int i=0;i<n;i++){
        v[i] = rand()%max;
    }
}
void imprime(int v[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d",v[i]);
        if(i<n-1){
            printf(",");
        }
    }
    printf("]\n");
}

//
int main()
{
    int v[200000];
    int n=200000;
    gera(v,n,n);
    int tin = time(NULL);
    ordena(v,n);
    printf("Tempo = %ld\n",time(NULL)-tin);
}

/**
Em grupo de três pessoas. Apenas uma pessoa do grupo deve entregar.
O nome dos três integrantes deve estar dentro do arquivo enviado.

Na Minha máquina o tempo de execução do algoritmo de ordenação foi
T(n) = n^2*1.56*10^-9s.
Descubra o tempo de execução na sua máquina. (Descubra a constante).
Após isso, descubra quanto tempo vai demorar, em sua máquina,
para ordenar um vetor com 1 milhão de elementos. E para 10 milhões de elementos?

Crie uma planilha com 3 colunas. Na primeira o n, na segunda o T(n) medido,
e na terceira, o T(n) vindo da função. Faça um gráfico com estas três colunas. 


*/ 






