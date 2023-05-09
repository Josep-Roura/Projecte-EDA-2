#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/terms.h"
#include "../headers/menu.h"
#include "../headers/user.h"
#include "../headers/publi.h"


void add_publication(){
  Publication *new_publication;
  printf("Canción:\n");
  scanf("%s", &new_publication->song[MAX_LENGTH]);
  printf("Artista:\n");
  scanf("%s\n", &new_publication->artist[MAX_LENGTH]);
  printf("Álbum:\n");
  scanf("%s", &new_publication->album[MAX_LENGTH]);
  printf("Año de publicación:\n");
  scanf("%d", &new_publication->year);
  printf("Link de escucha:\n");
  scanf("%s", &new_publication->link[MAX_LENGTH]);
} 

void list_publications(){
}