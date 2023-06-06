#include "../headers/user.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LINE_LENGTH 1024

void add_new_user() {
    int Age;
    char Username[MAX_LENGTH], Password[MAX_LENGTH], Email[MAX_LENGTH],
        Location[MAX_LENGTH], Genre1[MAX_LENGTH], Genre2[MAX_LENGTH],
        Genre3[MAX_LENGTH];
  
    int num_users = 0;
    User users[MAX_USERS];
    read_user(users, &num_users);
    
    while (1) {
        printf("\nIntroducir nuevo nombre de usuario:");
        scanf("%s", Username);
      
        int usuario_duplicado = 0;
        for (int i = 0; i < num_users; i++) {
            if (strcmp(users[i].username, Username) == 0) { // Usuario con este nombre encontrado.
            usuario_duplicado = 1; 
            break;
            }
        }
      
        if (usuario_duplicado) {
            printf("\nUsuario %s ya registrado. Elige un nombre de usuario distinto.\n", Username);
        } else {
            break;  // Nombre de usuario válido, salir del bucle.
        }
    }
  
    while (1) {
        printf("\nIntroducir contraseña (6-20 caracteres):");
        scanf("%s", Password);
    
        if (strlen(Password) >= 6 && strlen(Password) <= 20) {
          break; // La longitud de la contraseña es válida, salir del bucle.
        }
        printf("La contraseña debe tener entre 6 y 20 caracteres. Inténtalo de nuevo.\n");
    }
  
    printf("\nIntroducir edad:");
    scanf("%d", &Age);
  
    printf("\nIntroducir email:");
    scanf("%s", Email);
  
    printf("\nIntroducir ubicación (ciudad):");
    scanf("%s", Location);
  
    printf("\nIntroducir el primer género de música favorito:");
    scanf("%s", Genre1);
  
    printf("\nIntroducir el segundo género de música favorito:");
    scanf("%s", Genre2);
  
    printf("\nIntroducir el tercer género de música favorito:");
    scanf("%s", Genre3);
  
    // Añadir los datos al archivo.
  
    // Abrir el archivo en modo lectura.
    FILE *archivo = fopen("./Data/Users.txt", "r");
  
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }
  
    int lineas = 2; // Teniendo en cuenta que la última línea no tiene un \n y que
                    // el queremeos hacer es escribir en una nueva línea.
    char caracter;
  
    // Contar las líneas en el archivo.
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') {
            lineas++;
        }
    }
  
    // Cerrar el archivo en forma lectura.
    fclose(archivo);
  
    // Abrir el archivo en modo escritura.
    archivo = fopen("./Data/Users.txt", "a");
  
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
  
    // Obtener data local.
    char fechaActual[50];
    time_t tiempoActual;
    struct tm *fecha;
    tiempoActual = time(NULL);
    fecha = localtime(&tiempoActual);
    strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", fecha);
  
    // Escribir los datos en el archivo.
    fprintf(archivo, "\n%d,%s,%s,%d,%s,%s,%s,%s,%s,%s", lineas, Username, Password, Age, Email, Location, fechaActual, Genre1, Genre2, Genre3);
  
    // Cerrar el archivo.
    fclose(archivo);
  }
  
void read_user(User *users, int *num_users) {
    // Structure .txt : id, username, password, age, email, location, date,
    // genres, genres, genres.
    FILE *file = fopen("./Data/Users.txt", "r");
    if (file == NULL) {
      printf("Error. No se pudo abrir el archivo.\n");
      return;
    }
  
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
      User user;
      sscanf(line,
             "%d,%255[^,],%255[^,],%d,%255[^,],%255[^,],%11[^,],%15[^,],%15[^,],%"
             "15s",
             &user.id, user.username, user.password, &user.age, user.email,
             user.location, user.date, user.genres[0], user.genres[1],
             user.genres[2]);
      users[*num_users] = user;
      (*num_users)++;
    }
  
    fclose(file);
  }
  
void insertion_sort_users(User users[], int num_users) {
  int i, j;
  for (i = 1; i < num_users;
       i++) { // Recorremos el array de usuarios a partir del segundo usuario.
    User key =
        users[i]; // Creanos una variable key tipo User para almacenar el índice
                  // del usuario actual. Este usuario lo utilizaremos para hacer
                  // comparaciones e ir realizando el proceso de inserción
    j = i - 1; // Inicializamos j con el índice anterior de i y lo utilizaremos
               // para comparar el usuario actual con los usuarios anteriores en
               // el array y y realizar el desplazamiento hacia la derecha.
    while (j >= 0 & strcmp(users[j].username, key.username) >
                        0) {   // Verificamos si el usuario j debe desplazarse
                               // hacia la derecha del array.
      users[j + 1] = users[j]; // Lo desplazamos hacia la derecha.
      j = j -
          1; // Decrementamos j para seguir comparando los usuarios anteriores.
    }
    users[j + 1] = key; // El usuario key se coloca en la posición correcta
                        // dentro de los usuarios anteriores ya ordenados.
  }
}

// Imprimir ID y nombre de usuario de cada usuario ordenado.
void print_users() {
  int num_users = 0;
  User users[MAX_USERS];
  read_user(users, &num_users);
  insertion_sort_users(users, num_users);
  for (int i = 0; i < num_users; i++) {
    printf("%d Username : %s\n", i + 1, users[i].username);
  }
}

User user_log_in() {
  char *list_usernames[MAX_USERS];
  User users[MAX_USERS];
  int num_users = 0;
  read_user(users, &num_users);
  for (int i = 0; i < num_users; i++) {
    list_usernames[i] = users[i].username;
    // Convertimos los datos de nombres de usuario en una lista para que sea más fácil trabajar con ellos.
  }
  
  int proof_username = 0;
  char username[MAX_USERS];
  int key = 0;
  printf("\nOperar como usuario:");
  scanf("%s", username);
  
  while (key < num_users) {
    if (strcmp(list_usernames[key], username) == 0) {
      printf("\nUsuario %s encontrado.\n", username);
      proof_username = 1;
      break;
    }
    key++;
  }
  key++; // Esta key nos indicará qué usuario listado está haciendo el login.
  
  if (proof_username == 0) {
    printf("\nUsuario %s no encontrado.\n", username);
    User emptyUser;
    strcpy(emptyUser.username, "");
    strcpy(emptyUser.password, "");
    return emptyUser;
  }
  
  char *list_passwords[MAX_USERS];
  for (int i = 0; i < num_users; i++) {
    list_passwords[i] = users[i].password; // Convertimos los datos de contraseñas en una lista para que sea más fácil trabajar con ellos.
  }
  
  int proof_password = 0;
  char password[MAX_LENGTH];
  
  int tries = 0;
  while (tries < 3) { 
    printf("Introducir contraseña:");
    scanf("%s", password);
  
    for (int j = 0; j < num_users; j++) {
      if ((strcmp(list_passwords[j], password) == 0) && (key - 1 == j)) {
        printf("\nBienvenid@ %s.\n", username);
        proof_password = 1;
        return users[j];
      }
    }
    if (proof_password == 0) { // Si la contraseña es incorrecta le dejara probar otra vez. Hasta 3 veces.
      printf("\nLa contraseña es incorrecta.\n");
      tries ++;
      }
  }
  printf("\nHas fallado la contraseña 3 veces. Se te he redireccionado al menú principal.\n");
}




void dynamic_array_users() {
  Node *head = NULL;
  User new_user;
  Node *new_node = (Node *)malloc(
      sizeof(Node)); // Asignamos espacio en la memoria para almacenar la
                     // información de un nuevo usuario.
  new_node->user = new_user;
  new_node->next = NULL;
  if (head ==
      NULL) { // Si la lista está vacía establece head como el primer nodo.
    head = new_node;
  } else {
    Node *current = head;
    while (current->next !=
           NULL) { //  Si la lista no está vacía, recorre la lista hasta el
                   //  último nodo y establece su puntero next en el nuevo nodo.
      current = current->next;
    }
    current->next = new_node;
  }
}


