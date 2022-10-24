#include <stdio.h>
#include <stdlib.h>

char *getString()
{
  int size = 4;
  char * placa = (char *)malloc(sizeof(char)*8); /*Stored in heap segment*/
  *(placa+0) = 'G'; 
  *(placa+1) = 'f';  
  *(placa+2) = 'G';
  *(placa+3) = '\0';  
    
  /* No problem: string remains at str after getstring() returns */    
  return placa;  
}     
int main()
{
  printf("%s", getString());  
  return 0;
}