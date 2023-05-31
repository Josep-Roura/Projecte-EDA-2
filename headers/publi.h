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
  char year[MAX_LENGTH];
  int id_publication;
} Publication;  

//Estructura del stack.

typedef struct {
  Publication publications[MAX_PUBLICATIONS];
  int top;
} publication_stack;

// Estructura del nodo para la linked list

typedef struct PublicationNode {
    User *UserData;
    char album[MAX_LINE_LENGTH];
    char artist[MAX_LINE_LENGTH];
    char label[MAX_LINE_LENGTH];
    char year[MAX_LINE_LENGTH];
    char description[MAX_LINE_LENGTH];
    char photo[MAX_LINE_LENGTH];
    int id_publication;
    char release_date[MAX_LINE_LENGTH];
    struct PublicationNode *next;
} PublicationNode;

void add_publication(); // Función utilizada para añadir una nueva publicación al archivo txt.
void list_publications(); // Función utilizada para imprimir todas las publicaciones de un usuario.

PublicationNode* createPublicationNode();
void insertPublication(PublicationNode **head, PublicationNode *node);
void freePublicationList(PublicationNode *head); 