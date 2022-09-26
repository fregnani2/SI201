/* Write a program in C to store n elements in an array and print the elements using pointer */

#include <stdio.h>
int main(){

int n = 0;
scanf("%d", &n);

int* ptr = malloc(n * sizeof(int));

for(int i = 0; i < n; i++){
    scanf("%d",&ptr[i]);
}
for(int i = 0; i < n; i++){
 printf("%d element is %d \n",i,ptr[i]);
}
 free(ptr);
}
