#include <stdio.h>
/* A partir do exercício anterior, incremente o valor de n usando apenas o ponteiro ptrn. 
Imprima o novo valor de n para confirmar se está correto. */

int main(){
    int n, *ptrn;

    ptrn = &n;
    n = 200;

    *ptrn += 1;

    printf("N value incremented by ptrn : %d", n);
}