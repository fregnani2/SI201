/* Declare duas variáveis inteiras m e n e dois ponteiros para elas. 
Atribua valores para as variáveis. Descubra qual o maior valor, 
acessando-as somente através dos ponteiros. Imprima esse valor. */

#include <stdio.h>

int main(){
    int m,n,*ptrm, *ptrn;

    ptrm = &m;
    ptrn = &n;
    m = 4;
    n = 5;

    (m > n) ? printf("Max value : %d", *ptrm) : printf("Max value : %d", *ptrn);
}