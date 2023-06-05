#include "../headers/user.h"
#define MAX_LENGTH 256
#define MAX_PUBLICATIONS 100
#define MAX_LINE_LENGTH 1024


// Estructura de las publicaciones

typedef struct Publication{
  User *UserData;
  char artist[MAX_LENGTH];
  char label[MAX_LENGTH];
  char album[MAX_LENGTH];
  char release_date[MAX_LENGTH];
  char description[MAX_LENGTH];
  char photo[MAX_LENGTH];
  char year[MAX_LENGTH];
  int id_publication;
  struct Publication *next;
} Publication;  

//Estructura del stack.

typedef struct {
  Publication publications[MAX_PUBLICATIONS];
  int top;
} publication_stack;

// Estructura para el diccionario y el conteo de palabras

typedef struct{
  char word[MAX_LENGTH];
  int count;
} w_count;


void add_publication(); // Función utilizada para añadir una nueva publicación al archivo txt.
void list_publications(); // Función utilizada para imprimir todas las publicaciones de un usuario.

Publication* createPublicationNode();
void insertPublication(Publication **head, Publication *node);
void freePublicationList(Publication *head); 

void add_word (const char *word);
void ranking_words();
