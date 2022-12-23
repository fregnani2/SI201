#include <stdio.h>

void print(int v[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d",v[i]);
        if(i<n-1){
            printf(",");
        }
    }
    printf("](%d)\n",n);
}

int max(int v[],int n){
    int m=0;
    for(int i=1;i<n;i++){
        if(v[i]>v[m]){
            m=i;
        }
    }
    return m;
}

void selecaoRecursivo(int v[],int n){
    int m,aux;
    if(n<2){
        return;
    }
    m = max(v,n);
    aux = v[m];
    v[m] = v[n-1];
    v[n-1]=aux;
    print(v,n);
    selecaoRecursivo(v,n-1);
}

void selecaoIterativo(int v[],int n){
    int m,aux;
    while(n>1){
        m = max(v,n);
        aux = v[m];
        v[m] = v[n-1];
        v[n-1]=aux;
        print(v,n);
        n--;
    }
}

void bolhaRecursiva(int v[],int n){
    if(n<2){
        return;
    }
    int aux;
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
        }
        print(v,n);
    }
    bolhaRecursiva(v,n-1);
    
}

void bolhaIterativa(int v[],int n){
    int aux;
    while(n>2){
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
            print(v,n);
        }
        n--;
    }
    
}

void insercaoRec(int v[],int n){
    int lixo=-1;
    if(n<2){
        return ;
    }
    
    insercaoRec(v,n-1);
    
    int aux = v[n-1];
    v[n-1]=lixo;
    int i = n-2;
    print(v,n);
    while(i>=0&&v[i]>aux){
        v[i+1]=v[i];
        v[i] = lixo;
        i--;
        print(v,n);
    }
    v[i+1]=aux;
    print(v,n);
}


void insercaoIterativo(int v[],int N){
    int lixo=-1;

    int n=2;
    
    while(n<=N){
        int aux = v[n-1];
        v[n-1]=lixo;
        int i = n-2;
        print(v,n);
        while(i>=0&&v[i]>aux){
            v[i+1]=v[i];
            v[i] = lixo;
            i--;
            print(v,n);
        }
        v[i+1]=aux;
        print(v,n);
        n++;
    }
    
}

void quest2(int v[],int n){
    int i = 0;
    while(i < n){
        int primeiraPos = i;
        int posMenor = i;
        for(int j = posMenor; j < n; j++){
            if (v[posMenor] > v[j]){
                posMenor = j;
            }
        }
        int aux = v[primeiraPos];
        v[primeiraPos] = v[posMenor];
        v[posMenor] = aux;
        i++;
    } 
}

void algoritmoSelecao(int v[], int n){
    int i = 0;
    while (i < n){
        int valor = i;
        int j = i+1;
        while(j < n){
            if(v[j] < v[valor]){
                valor = j;
            }
            j++;
        }
        int aux = v[valor];
        v[valor] = v[i];
        v[i] = aux;
        i++;
    }
}

int main() {
    int n=8;
    int v[] = {0,9,1,2,5,3,7,12};
    //print(v,n);
    algoritmoSelecao(v,n);
    print(v,n);
    //selecaoRecursivo(v, n);
    
}