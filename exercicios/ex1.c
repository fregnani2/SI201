#include <stdio.h>
/* Declare uma variável inteira n e um ponteiro ptrn para essa variável. Atribua um valor para n.
A seguir, imprima o valor de n a partir de ptrn. Imprima também o endereço de n e de ptrn. */

int main(){
    int n, *ptrn;

    ptrn = &n;
    n = 2;

    printf("Valor de N: %d\n",*ptrn);
    printf("Endereço de N: %d\n", &n);
    printf("Endereço de ptrn: %d\n",ptrn);



}