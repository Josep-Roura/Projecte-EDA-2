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


  /*
  Publication new_publication;
  getchar();
  printf("Álbum:  ");
  fgets(&new_publication.album[MAX_LENGTH], 258, stdin);
  if((strlen(new_publication.album) > 0) && (new_publication.album[strlen(new_publication.album) - 1] == '\n')) {
    (new_publication.album[strlen(new_publication.album) - 1]) = '\0';
  }
  printf("Artista:  ");
  fgets(&new_publication.artist[MAX_LENGTH], 258, stdin);
  if((strlen(new_publication.artist) > 0) && (new_publication.artist[strlen(new_publication.artist) - 1] == '\n')) {
    (new_publication.artist[strlen(new_publication.artist) - 1]) = '\0';
  }
  printf("Sello discográfico:  ");
  fgets(&new_publication.label[MAX_LENGTH], 258, stdin);
  if((strlen(new_publication.label) > 0) && (new_publication.label[strlen(new_publication.label) - 1] == '\n')) {
    (new_publication.label[strlen(new_publication.label) - 1]) = '\0';
  }
  printf("Año:  ");
  fgets(&new_publication.year[MAX_LENGTH], 258, stdin);
  if((strlen(new_publication.year) > 0) && (new_publication.year[strlen(new_publication.year) - 1] == '\n')) {
    (new_publication.year[strlen(new_publication.year) - 1]) = '\0';
  }
  printf("Descripción:  ");
  fgets(&new_publication.description[MAX_LENGTH], 258, stdin);
  if((strlen(new_publication.description) > 0) && (new_publication.description[strlen(new_publication.description) - 1] == '\n')) {
    (new_publication.description[strlen(new_publication.description) - 1]) = '\0';
  }
  printf("Foto:  ");
  fgets(&new_publication.photo[MAX_LENGTH], 258, stdin);
  if((strlen(new_publication.photo) > 0) && (new_publication.photo[strlen(new_publication.photo) - 1] == '\n')) {
    (new_publication.photo[strlen(new_publication.photo) - 1]) = '\0';
  }
  */
  
  // Añadir los datos al archivo. Contamos las publicaciones previas para darle el numero de publicación a la nueva publicación.

   // Abrir el archivo en modo lectura y escritura
  FILE *file2 = fopen("./Data/Publications.txt", "r");

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

  fclose(file2);
  fopen("./Data/Publications.txt", "a");

  // Escribir los datos en el archivo.
  fprintf(file2, "%d, %s, %s, %s, %s, %s, %s, %s\n",
lineas_p,new_publication.album,new_publication.artist,new_publication.label,new_publication.year,new_publication.description,new_publication.photo,dateActual);

  // Cerrar el archivo.
  fclose(file2);

  // Añadimos la publiación al stack.
  publication_stack stack;
  stack.top++;
  stack.publications[stack.top] = new_publication;
}


void list_publications() {
  // Estructura archivo de texto : id, album, artist, label, year, description, photo, user id, publication date.
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
    Publication publication;
    
    sscanf(line, "%d, %s, %s, %s, %d, %s, %s, %d, %s",
    &publication.id_publication, publication.album, publication.artist,       
    publication.label, &publication.year, publication.description, 
    publication.photo, &publication.UserData->id, publication.release_date);
    
    *all_publications[num_publications] = publication;
    num_publications++;
  }

// Pedimos el nombre del usuario del que se quieren listar las publicaciones

  char user_name[50];
  printf("Introduzca el nombre del usuario ");
  scanf("%s\n", user_name);

// Después de esto, buscamos que publicaciones tienen como id de usuario la que se está buscando y las imprimimos

  int i = 0;
  while (i < num_publications){
    if (strcmp(all_publications[i]->UserData->username, user_name) == 0){
      printf("%d,%s,%s,%s,%d,%s,%s,%d,%s\n", all_publications[i]->id_publication,     
      all_publications[i]->album, all_publications[i]->artist, all_publications[i]->label, 
      all_publications[i]->year, all_publications[i]->description, all_publications[i]->photo, 
      all_publications[i]->UserData->id, all_publications[i]->release_date);
    }
    i++;
  }  
  fclose(file1);
}



  
