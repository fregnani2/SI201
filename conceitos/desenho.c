
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 Estrutura coordenada com x e y.
 */
typedef struct Coordenada {
    int x,y;
}Coordenada;

/**
 Construtor da estrutura coordenada.
 int x,y: valores da coordenada.
 */
Coordenada * newCoordenada(int x,int y){
    Coordenada * aux = (Coordenada *)malloc(sizeof(Coordenada));
    aux->x=x;
    aux->y=y;
    return aux;
}
/**
 Imprime a coordenada.
 */
void printCoordenada(Coordenada *c){
    printf("(%d,%d)",c->x,c->y);
}
/**
 Distância Euclidiana entre duas coordenadas
 a e b.
 */
double eucliDist(Coordenada *a, Coordenada *b){
    double dx = (a->x)-(b->x);
    double dy = (a->y)-(b->y);
    return sqrt(dx*dx+dy*dy);
}

/**
 Estrutura que guarda um segumento. Possui
 duas coordenadas.
 */
typedef struct Segmento{
    Coordenada *ini,*fim;
}Segmento;

/**
 Construtor da estrutura segmento.
 Recebe como parâmetros duas coordenadas.
 */
Segmento * newSegmento(Coordenada *ini, Coordenada *fim){
    Segmento * aux = (Segmento *)malloc(sizeof(Segmento));
    aux->ini=newCoordenada(ini->x,ini->y);
    aux->fim=newCoordenada(fim->x,fim->y);
    return aux;
}
/**
 Imprime o semgmento no no console no formato
 texto.
 */
void printSegmento(Segmento *s){
    printf("[");
    printCoordenada(s->ini);
    printCoordenada(s->fim);
    printf("]\n");
}
/**
 Comprimento de um segmento.
 */
double comprimento(Segmento *s){
    return eucliDist(s->ini, s->fim);
}

/**
 Dados dois segmento a e b, calcular a intersecção dos
 segmentos. Se não houver intersecção, deve retornar NULL;
 Deixado como exercício.
 */
Coordenada * interseccao(Segmento *a, Segmento *b){
    Coordenada * inter = NULL;
    return inter;
}


/**
 Poligono composto por várias coordenadas.
 */
typedef struct Poligono {
    Coordenada * v[100];
    int top;
}Poligono;

/**
 Construtor da estrutura poligono.
 */
Poligono * newPoligono(){
    Poligono * aux = (Poligono *)malloc(sizeof(Poligono));
    aux->top=0;
    return aux;
}
/** adiciona uma nova coordenada ao poligono*/
void addCoord(Poligono *p, Coordenada *c){
    p->v[p->top++]=c;
}
/**
 imprime o poligono no console formato texto.
 */
void printPoligono(Poligono *p){
    printf("[");
    for(int i=0;i<p->top;i++){
        printCoordenada(p->v[i]);
    }
    printf("]\n");
}

/**
 Perimetro do poligono.
 */
double perimetro(Poligono *p){
    double per=0;
    for(int i=0;i<p->top-1;i++){
        per+= eucliDist(p->v[i],p->v[i+1]);
    }
    return per;
}

#define preto 1
#define branco 0

/**
 Estrutura que representa uma imagem.
 */
typedef struct Imagem{
    int **m;
    int larg,alt;
}Imagem;

/**
 Construtor da estrutura imagem. Recebe
 como parametro a largura e a altura da imagem.
 */
Imagem * newImage(int larg,int alt){
    Imagem * aux=(Imagem *)malloc(sizeof(Imagem));
    aux->m = (int **)malloc(sizeof(int *)*alt);
    for(int li=0;li<alt;li++){
        aux->m[li] = (int *)malloc(sizeof(int)*larg);
        for(int co=0;co<larg;co++){
            aux->m[li][co]=branco;
        }
    }
    aux->alt=alt;
    aux->larg=larg;
    return aux;
}
/**
 imprime a imagem no formato texto.
 */
void printImg(Imagem * img){
    printf("%d %d\n",img->larg,img->alt);
    for(int linha=img->alt-1;linha>=0;linha--){
        for(int col=0;col<img->larg;col++){
            printf("%d ",img->m[linha][col]);
        }
        printf("\n");
    }
}
/**
 Atribui o valor cor a uma determinado pixel da imagem.
 Se posição for fora da imagem, nada é feito.
 */
void set(Imagem *img,int li,int col,int cor){
    if(li>=0&&col>=0&&li<img->alt&&col<img->larg){
        img->m[li][col]=cor;
    }
}

/**
 Escreve a imagem em um arquivo.
 */
void writeFile(Imagem *img,char * fname){
    FILE * fp;
    fp = fopen(fname,"w+");
    fprintf(fp,"P1\n");
    fprintf(fp,"%d %d\n",img->larg,img->alt);
    for(int linha=img->alt-1;linha>=0;linha--){
        for(int col=0;col<img->larg;col++){
            fprintf(fp,"%d ",img->m[linha][col]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}


/** imprime a coordenada
 dentro de uma imagem com uma determinada espessura.
 */
void printCord(Imagem *img,Coordenada * c,int espessura,int cor){
    for(int li = c->y-espessura+1;li<=c->y+espessura-1;li++){
        for(int col = c->x-espessura+1;col<=c->x+espessura-1;col++){
            set(img, li, col,cor);
        }
    }
}

/**
 Imprime um segmento, fazendo a varredura no eixo x.
 */
void printSegDeltaX(Imagem *img, Segmento *s,int cor){
    Coordenada  * esq, *dir;
    if(s->ini->x<s->fim->x){
        esq = s->ini;
        dir = s->fim;
    }else{
        esq = s->fim;
        dir = s->ini;
    }
    
    double x1 = esq->x;
    double y1 = esq->y;
    double x2 = dir->x;
    double y2 = dir->y;
    double delta = (y2-y1)/(x2-x1);
    
    for(double x=x1;x<x2;x++){
        double y = y1+(x-x1)*delta;
        set(img,(int)y,(int)x,cor);
    }
}
/**
 Imprime um segmento varrendo a imagem no eixo y.
 */
void printSegDeltaY(Imagem *img, Segmento *s,int cor){
    
    Coordenada  * abaixo, *acima;
    if(s->ini->y<s->fim->y){
        abaixo = s->ini;
        acima = s->fim;
    }else{
        abaixo = s->fim;
        acima = s->ini;
    }
    
    double x1 = abaixo->x;
    double y1 = abaixo->y;
    double x2 = acima->x;
    double y2 = acima->y;
    double delta = (x2-x1)/(y2-y1);
    
    for(double y=y1;y<y2;y++){
        double x = x1+(y-y1)*delta;
        set(img,(int)y,(int)x,cor);
    }
}

/**
 imprime um segmento.
 */
void printSeg(Imagem *img, Segmento *s,int cor){
    int espessura = 2;
    printCord(img, s->ini, espessura, cor);
    printCord(img, s->fim, espessura, cor);
    
    if(comprimento(s)<1.0){
        return;
    }
    int dx = s->ini->x-s->fim->x;
    if(dx<0){
        dx=-dx;
    }
    int dy =s->ini->y-s->fim->y;
    if(dy<0){
        dy=-dy;
    }
    if(dx>dy){
        printSegDeltaX(img, s,cor);
    }else{
        printSegDeltaY(img, s,cor);
    }
}

/**
 imprime o polígono.
 */
void printPol(Imagem *img,Poligono *p,int cor){
    for(int i=0;i<p->top;i++){
        int espessura = 3;
        printCord(img,p->v[i], espessura, cor);
        if(i<p->top-1){
            Segmento * s = newSegmento(p->v[i], p->v[i+1]);
            printSeg(img, s, cor);
        }
    }
}

/**
 Crie uma função que faz a translação de uma coordenada.
 Esta função recebe como parâmetro um deltax e um deltay
 Após a translação, a posição x da coordenada é movida
 em deltax unidades e a posição y é movidoa deltay posições.
 Exemplo: Se coordenada for (5,5) e a translação for (3,3),
 Após a translação, a nova posição será (8,8).
 Número de linhas de código esperada:2
 */
void translacaoCoord(Coordenada *c,int deltax, int deltay);

/** faça uma translação de um segmento. Esta função
 deve chamar translacaoCoord()
 Número de linhas de código esperada:2
 */
void translacaoSeg(Segmento *seg,int deltax, int deltay);

/** faça uma translação de um poligono. Esta função
 deve chamar translacaoCoord()*/
void translacaoPol(Poligono *p,int deltax, int deltay);


/**
 Parte 1)
 Crie um polígono que representa uma estrela com 5 pontas.
 Este polígono deve ter altura 50 e deve estar no canto inferior esquerdo da imagem. A imagem deve ser 500x500.
 Escreva o polígono na imagem e escreva a imagem em um
 arquivo chamado estrela.pbm (veja tal arquivo no moodle).
 
 Parte 2)
 Após isso, faça a translação do polígono
 que representa a estrela de um deltax=50,
 deltay=30, sucessivamente por 10 vezes. A cada translação,
 imprima o polígono na imagem.
 Ao fim, imprima a imagem no aquivo estrelas.pbm
 (veja tal arquivo no moodle).
 
 
 */



int main(){
    int largura = 500;
    int altura = 500;
    
    Imagem * img = newImage(largura,altura);
    int li;
    int col;
    //int cor = preto;
    col = 200;
    li = 200;
    Coordenada * c1 = newCoordenada(col,li);
    
    Poligono * p = newPoligono();
   
    col = 400;
    
    for(li=10;li<=400;li+=50){
        Coordenada * c2 = newCoordenada(col,li);
        addCoord(p, c2);
        Segmento * s = newSegmento(c1, c2);
        printSeg(img, s, preto);
    }
    
    li = 400;
    for(col=400;col>=0;col-=50){
        Coordenada * c2 = newCoordenada(col,li);
        addCoord(p, c2);
        Segmento * s = newSegmento(c1, c2);
        printSeg(img, s, preto);

    }
    printPol(img, p, preto);
    //printCord(img, c2,espessura,cor);
    
    
    
    printImg(img);
    writeFile(img, "Teste.txt");
    writeFile(img, "Teste.pbm");
    printf("FIM\n");
  
}


