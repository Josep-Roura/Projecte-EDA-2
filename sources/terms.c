#include <stdio.h>
#include "../headers/menu.h"
#include "../headers/terms.h"
void terms_of_use() {
  FILE *file_terms;

  file_terms = fopen("Data/terms_of_use.txt","r");

  if (file_terms == NULL){
    printf("Error. El archivo no se pudo abrir.\n");
  }
  char buf[100];
  while((fgets(buf, 100,file_terms)) != NULL){
    printf("%s",buf);
  }
  fclose(file_terms);
  
}