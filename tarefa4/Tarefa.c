//Fazer em grupo de 3 alunos. Apenas um 
//deve submeter o arquivo. O nome dos integrantes
//deve estar junto no código fonte.
#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define debug 1

typedef struct Carro{
    char placa[8];
    int ano;
    char marca[100];
    char modelo[100];
} Carro;

Carro * newCarro(char *placa, int ano, char * marca,
                 char * modelo){
    Carro * carro = (Carro *)malloc(sizeof(Carro));
    strcpy(carro->placa,placa);
    strcpy(carro->marca,marca);
    strcpy(carro->modelo,modelo);
    carro->ano = ano;
    return carro;
}

void printCarro(Carro * carro){
    printf("[%s,%d,%s,%s]\n",carro->placa,carro->ano,
           carro->marca,carro->modelo);
}

#define MAX 100

typedef struct Lista{
    Carro * v[MAX];
    int top,max;
}Lista;

Lista * newLista(){
    Lista * li =(Lista *)malloc(sizeof(Lista));
    li->max = MAX;
    li->top = 0;
    return li;
}

void addLista(Lista *li, Carro * carro){
    li->v[li->top++] = carro;
}

void printLista(Lista *li){
    for(int i=0;i<li->top;i++){
        printCarro(li->v[i]);
    }
}

/** assinatura das funções a serem implementadas.*/
char caracterAleatorio(void);
void testaCaracterAleatorio(void);
char * geraPlacaAleatoria(void);
Carro * geraCarroAleatorio(void);
void ordena(Lista *li,int tipo);


int main(int argc, const char * argv[]) {
    /**
     Esta função devolve o número de segundos a partir
     de uma data específica (1/1/1970).
     */
    //printf("%d\n",(int)time(NULL));
    /**
     Esta função cria uma semente aleatória distinta.
     A cada execução, a função rand gerará números
     aleatórios distintos. Para que o rand gere a mesma
     sequencia de números pseudo-aleatórios, é preciso 
     usar uma semente fixa, como, por exemplo, srand(100)
     */
    srand((int)time(NULL));

    if(debug)
        testaCaracterAleatorio();

    /**
     geração de placa aleatória
     */
    char * placa = geraPlacaAleatoria();
    printf("%s\n",placa);
    free(placa);


    /**
     Criação de um carro.
     */
    // Carro * carro = newCarro("ARA1B11", 2018, "Fiat",
    //                          "Uno");
    // printCarro(carro);


    /**
     impressão de carro aleatório
     */
    // printCarro(geraCarroAleatorio());

    /** criação de uma lista */
    // Lista * li = newLista();
    // for(int i=0;i<15;i++){
    //     addLista(li, geraCarroAleatorio());
    // }
    // printLista(li);


    // printf("Ordenar por:\n");
    // printf("Placa: 0 \n");
    // printf("Ano: 1 \n");
    // printf("Marca: 2 \n");
    // printf("Modelo: 3  \n");
    // printf("Digite um valor entre 0 e 3:   ");
    
    // int tipo;
    // scanf("%d",&tipo);
    // ordena(li,tipo);
    // printLista(li);

 
    
    
}

/** Gera um caracter aleatório entre 'A' e 'Z'
 Número de linhas esperado: 2
 */
char caracterAleatorio(){
    char num = (rand() % 26 )+65;
    return num;
}
/**
 Esta função testa se o gerador de caracteres aleatórios
 está funcionando. O primeiro while gera caracteres
 aleatórios até que seja gerado um 'A' (que é o minimo).
 O while seguinte gera caracteres aleatórios até que seja
 gerado um 'Z' (que é o máximo). Depois são repetidas mil
 iterações onde verifica-se se o valor gerado é menor que
 'A' ou maior que 'Z'. Se tudo ocorrer corretamente, o 
 programa termina sua execução.
 */
void testaCaracterAleatorio(){
    //verifica a geração do 'A'
    while(caracterAleatorio()!='A'){
        
    }
    printf("ok 1\n");
    //verifica a geração do 'Z'
    while(caracterAleatorio()!='Z'){
        
    }
    printf("ok 2\n");
    for(int i=0;i<1000;i++){
        if(caracterAleatorio()<'A'){
            printf("Erro");
        }
        if(caracterAleatorio()>'Z'){
            printf("Erro");
        }
    }
    printf("ok 3\n");

}
/**
 Esta função gera uma placa aleatória. A placa deve ser no
 formato LLLNLNN onde L é uma letra aleatória e N é um
 dígito aleatório. Atenção, para que esta função funcione,
 a string precisa ser criada por alocação dinâmcia, para que
 ela exista fora da função. Lembrar que no padrão string, 
 é necessário um caracter '\0' que fecha a string.
 Número de linhas esperado: 10
 */
char * geraPlacaAleatoria(void){
    char * placa = (char *)malloc(sizeof(char)*8);
    for(int i = 0; i < 7; i++){
        if(i == 3 || i == 5 || i == 6){
            *(placa+i) = (rand() % 10) + '0';
        }
        else *(placa+i) = caracterAleatorio(); 
    }
    *(placa+8) = "\0";
    return placa;
}

/**
 Esta função gera um carro aleatório. O ano é um valor
 aleatório entre 2002 e 2022. A placa deve ser gerada pela
 função gera placa aleatória. A marca é um valor aleatório
 entre entre 'fiat', 'chevrolet' e 'volkswagem'. O modelo
 segue o seguinte padrão. Se a marca for 'fiat', o modelo é
 um valor aleatório entre ['pulse','argo','moby']. Se a
 marca for volkswagem, o modelo é um valor aleatório entre
 ['polo','jetta','gol']. Se a marca for 'chevrolet', o
 modelo é um valor aleatório entre
 ['onix','cruze','camaro'].
 Número esperado de linhas: 21
 */

Carro * geraCarroAleatorio(void){
    int ano = 2002+rand()%21;
    //seu código vem aqui.        
}


/**
 Esta função ordena a lista de acordo com o tipo passado.
 Se o tipo for 0, ordena por placa. Se o tipo for 1, ordena
 por ano. Se o tipo for 2, ordena por marca, se o tipo for 3
 ordena por modelo.
 Numero de linhas esperado: 26 linhas divididas em três
 funções.
 */
void ordena(Lista *li,int tipo){
    //seu código vem aqui
}




