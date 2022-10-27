#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
     int i;
     int count = 0;
     char str[] = "David Lai, 91234567, Dav, value1, value2, value3, value4, value5";
     const char delims[] = ",";
     char *result = NULL;
     char **store = NULL;
     char **tmp = NULL;
     char *name = NULL;
     char *telephone = NULL;
     char *nickname = NULL;
     result = strtok(str, delims);
     if (result != NULL) {
          store = malloc((count + 1) * sizeof(char *));
          store[count] = result;
          count++;
          tmp = malloc(count * sizeof(char *));
          printf("%s\n", result);
          for (i=0; i<count; i++) {
               printf("array is %s\n", store[i]);
          }
          result = strtok(NULL, delims);
     }
     while (result != NULL) {
          free(tmp);
          tmp = malloc(count * sizeof(char *));
          for (i=0; i<count; i++) {
               tmp[i] = store[i];
          }
          free(store);
          store = malloc((count + 1) * sizeof(char *));
          for (i=0; i<count; i++) {
               store[i] = tmp[i];
          }
          store[count] = result;
          count++;
          printf("%s\n", result);
          for (i=0; i<count; i++) {
               printf("array is %s\n", store[i]);
          }
          result = strtok(NULL, delims);
     }
     free(tmp);
     free(store);
     return 0;
}