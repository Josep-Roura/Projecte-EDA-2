#include "../headers/user.h"
#define MAX_LENGTH 256
#define MAX_PUBLICATIONS 100
#define MAX_LINE_LENGTH 1024


// Estructura de las publicaciones

typedef struct {
  User *UserData;
  char artist[MAX_LENGTH];
  char label[MAX_LENGTH];
  char album[MAX_LENGTH];
  char release_date[MAX_LENGTH];
  char description[MAX_LENGTH];
  char photo[MAX_LENGTH];
  int year;
  int id_publication;
} Publication;  

//Estructura del stack.

typedef struct {
  Publication publications[MAX_PUBLICATIONS];
  int top;
} publication_stack;

void add_publication(); // Función utilizada para añadir una nueva publicación al archivo txt.
void list_publications(); // Función utilizada para imprimir todas las publicaciones de un usuario.

