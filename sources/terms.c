#include <stdio.h>
#include "../headers/menu.h"
void terms_of_use() {
  FILE *file_terms;

  file_terms = fopen("sources/terms_of_use.txt","r");

  if (file_terms == NULL){
    printf("Error. The file could not be opened.\n");
  }
  char buf[100];
  while((fgets(buf, 100,file_terms)) != NULL){
    printf("%s",buf);
  }
  fclose(file_terms);
  
}