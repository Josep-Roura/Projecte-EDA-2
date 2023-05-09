#define MAX_LENGTH 256
#define MAX_USERS 100
#define MAX_LINE_LENGTH 1024

typedef struct {
  int id;
  char username[MAX_LENGTH];
  char password[MAX_LENGTH];
  int age;
  char email[MAX_LENGTH];
  char location[MAX_LENGTH]; 
  char date[11];
  char genres[3][15];
} User;


void add_new_user(User* users, int *num_users); //Función para añadir nuevos usuarios mediante una estructura Usuario.
void print_users(); //Función para imprimir todos los usuarios y sus respectivos datos por pantalla.

void read_user_(User* users[MAX_USERS], int *num_users); //Función utilizada en la opción 3 del menú que consiste en leer del archivo el username de cada usuario.