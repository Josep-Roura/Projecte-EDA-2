#include "../headers/user.h"
#define MAX_LENGTH 256 
#define MAX_LINE_LENGTH 1024


// Estructura de las publicaciones
typedef struct Publication{
    User *UserData;
    char artist[MAX_LENGTH];
    char label[MAX_LENGTH];
    char album[MAX_LENGTH];
    char release_date[MAX_LENGTH];
    char description[MAX_LENGTH];
    char year[MAX_LENGTH];
    char track[MAX_LENGTH];
    int id_publication;
    struct Publication *next;
} Publication;  

// Estructura del stack.
typedef struct {
    Publication publications[MAX_PUBLICATIONS];
    int top;
} publication_stack;

// Estructura para el diccionario y el conteo de palabras
typedef struct{
    char word[MAX_LENGTH];
    int count;
} w_count;


Publication add_publication(User user); // Función utilizada para añadir una                     nueva publicación al archivo txt.
void list_publications(User user); // Función utilizada para imprimir todas las publicaciones del usuario registrado.

void list_publications_any_user(); // Función utilizada para imprimir toda las publicaciones de un usuario específico (a través de su nombre de usuario).

Publication* create_node(); // Función utilizada para crear el nodo de la lista dinámica.
void insert_publication(Publication **head, Publication *node); // Función utilizada para añadir el nodo en la lista dinámica
void free_list(Publication *head); // Función utilizada para liberar la memoria utilizada por los nodos y el usuario.

void add_word (const char *word); // Función utilizada para añadir palabra al diccionario o sumar repetición.
void ranking_words(); // Función utlizada para imprimir las 10 palabras más usadas por los usuarios.
