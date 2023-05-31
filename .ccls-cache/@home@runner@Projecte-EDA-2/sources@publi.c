#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "../headers/publi.h"
#define MAX_LENGTH 256
#define MAX_LINE_LENGTH 1024


void add_publication(){
  
  Publication new_publication;
  getchar();
  printf("Álbum:  ");
  scanf("%256[^\n]s", new_publication.album);
  getchar();
  printf("Artista:  ");
  scanf("%256[^\n]s", new_publication.artist);
  getchar();
  printf("Sello discográfico:  ");
  scanf("%256[^\n]s", new_publication.label);
  getchar();
  printf("Año de publicación:  ");
  scanf("%256[^\n]s", new_publication.year);
  getchar();
  printf("Descripción:  ");
  scanf("%256[^\n]s", new_publication.description);
  getchar();
  printf("Foto:  ");
  scanf("%256[^\n]s", new_publication.photo);
  
  
// Añadir los datos al archivo. Contamos las publicaciones previas para darle el numero de publicación a la nueva publicación.

   // Abrir el archivo en modo lectura y escritura
  FILE *file2 = fopen("./Data/Publications.txt", "a+");

  if (file2 == NULL) {
     printf("No se pudo abrir el archivo.\n");
  }

  // Contar las líneas en el archivo.
  int lineas_p = 1; 
  char caracter;

  while ((caracter = fgetc(file2)) != EOF) {
    if (caracter == '\n') {
      lineas_p++;
    }
  }
  
  // Asignamos el el valor del id de la publicación al siguiente valor del contador de líneas.
  new_publication.id_publication = (lineas_p + 1);
  
  // Obtener data local.
  char dateActual[50];
  time_t horaActual;
  struct tm *fecha1;
  horaActual = time(NULL);
  fecha1 = localtime(&horaActual);
  strftime(dateActual, sizeof(dateActual), "%Y-%m-%d", fecha1);

  
  // Escribir los datos en el archivo.
  fprintf(file2, "\n%d · %s · %s · %s · %s · %s · %s · %s",
new_publication.id_publication,new_publication.album,new_publication.artist,new_publication.label,new_publication.year,new_publication.description,new_publication.photo,dateActual);

  // Cerrar el archivo.
  fclose(file2);

  // Añadimos la publiación al stack.
  //stack.top++;
  //stack.publications[stack.top] = new_publication;

  //int i;
  //for (i = 0; i <= stack.top; i++) {
  //printf("Publicación %d: %s - %s\n", stack.publications[i].id_publication, stack.publications[i].album,
         //stack.publications[i].artist);
//}
  
}

/*
void list_publications() {
  // Estructura linea de archivo de texto : id · album · artist · label · year · description · photo · userid · username · publication date.
  // Creamos una función para que aparezcan todas las publicaciones de un usuario

  // Abrimos el archivo de las publicaciones y asignamos a cada uno de los elementos de la linea a su valor correspondiente en la estructura de la publicación 
  
  Publication *all_publications[MAX_PUBLICATIONS]; 
  FILE *file1 = fopen("./Data/Publications.txt", "r");
  
  if (file1 == NULL) {
    printf("Error. No se pudo abrir el archivo.\n");
    return;
  }

  // Creamos dos variables, una (num_publications) para contabilizar el número de publicaciones y la otra para diferenciar las distintas lineas de la publicación.
  
  int num_publications = 0;
  char line[MAX_LINE_LENGTH];

  // Con una estructura while leemos la linea del archivo y se lo asignamos a la publicación.
  while (fgets(line, MAX_LINE_LENGTH, file1) != NULL) {
    Publication *publication = malloc(sizeof(Publication));
    publication->UserData = malloc(sizeof(User)); 
    
    sscanf(line, "%d · %[^·]s · %[^·]s · %[^·]s · %[^·]s · %[^·]s %[^·]s · %d · %[^·]s · %[^\n]s",
    &publication->id_publication, publication->album, publication->artist,       
    publication->label, publication->year, publication->description, 
    publication->photo, &publication->UserData->id, publication->UserData->username, publication->release_date);
    
    all_publications[num_publications] = publication;
    num_publications++;
  }

// Pedimos el nombre del usuario del que se quieren listar las publicaciones

  char user_name[50];
  printf("Introduzca el nombre del usuario: ");
  scanf("%s", user_name);

// Después de esto, buscamos que publicaciones tienen como id de usuario la que se está buscando y las imprimimos

  int i = 0;
  while (i < num_publications){
    if (strcmp(all_publications[i]->UserData->username, user_name) == 0){
      printf("%d · %s · %s · %s · %s · %s · %s · %d · %s\n", all_publications[i]->id_publication,     
      all_publications[i]->album, all_publications[i]->artist, all_publications[i]->label, 
      all_publications[i]->year, all_publications[i]->description, all_publications[i]->photo, 
      all_publications[i]->UserData->id, all_publications[i]->release_date);
    }
    i++;
  }  
  fclose(file1);
}
*/


  
