#include <stdio.h>  
#include <conio.h>  
#include <stdlib.h>     
#include <time.h>
int main()  
{  
    time_t t1;
    srand ( (unsigned) time (&t1));
    
    for(int i = 0; i < 10; i ++){
        int num = (rand() % 26 )+65;
        printf("%c\n",num);
    }
    
}