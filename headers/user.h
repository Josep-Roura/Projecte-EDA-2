#define MAX_LENGTH 256
#define MAX_USERS 100
#define MAX_LINE_LENGTH 1024

typedef struct { // Estructura con los datos de cada usuario.
  int id;
  char username[MAX_LENGTH];
  char password[MAX_LENGTH];
  int age;
  char email[MAX_LENGTH];
  char location[MAX_LENGTH]; 
  char date[11];
  char genres[3][15];
} User;

struct UserLogged{
  char User;
  char password;
};

// Lista dinámica de usuarios.
typedef struct node {
  User user;
  struct node *next;
} Node;

void dynamic_array_users(); 
void add_new_user(); // Función para añadir nuevos usuarios en el archivo .txt.
void print_users(); // Función para imprimir todos los usuarios y sus respectivos datos por pantalla.

void read_user(User* users, int *num_users); // Función utilizada en la opción 2 y 3 del menú que consiste en leer del archivo el username de cada usuario.
int user_log_in(); // Función utilizada en la opción 3 del menú que sirve para iniciar sesión y empezar a operar como un usuario en concreto. Dentro de esta función se encuentra la implementación del algoritmo de búsqueda Linear Search.

void insertion_sort_users(User users[], int num_users); // Función utilizada para ordenar de forma alfabética los usernames de los users existentes.

void new_friend();
