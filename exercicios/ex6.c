/* TAD de um ponto com função que calcula distância */
#include <stdio.h>
#include <math.h>
typedef struct Ponto{
    int x,y;
}Ponto;

Ponto* pto_cria(int x, int y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL){
        p->x = x;
        p->y = y;
    }
}

void libera_pto(Ponto* p){
    free(p);
}
//Acessar valores de x e y de um ponto
void pto_acessa(Ponto* p, int* x, int* y){
    *x = p->x;
    *y = p->y;
}

//Atribui ponto as coordenadas x e y

void pto_atribui(Ponto *p, int*x, int*y){
    p->x = x;
    p->y = y;
}

int pto_distancia(Ponto *p1, Ponto *p2){
    int dx = p1->x - p2->x;
    int dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    Ponto *q, *p;
    int d;
    p = pto_cria(5, 4);
    q = pto_cria(7, 9);

    d = pto_distancia(p,q);
    printf("Distancia : %d", d);

    libera_pto(p);
    libera_pto(q);
}