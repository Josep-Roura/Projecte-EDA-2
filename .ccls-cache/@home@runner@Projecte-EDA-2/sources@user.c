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
  int key = 0;
  char username[MAX_USERS];
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


void new_friend(User *ActualUser){
    // Pedir al usuario el nombre del destinatario
    char nombreUsuario[MAX_LINE_LENGTH];
    printf("\nIntroduce el nombre del usuario al que quieres enviar la solicitud de amistad: ");
    scanf("%s", nombreUsuario);

    // Abrir el archivo de usuarios
    FILE* archivoUsuarios = fopen("./Data/Users.txt", "r");
    if (archivoUsuarios == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return;
    }

      
    // Abrir el archivo de amigos en modo de añadir al final
    FILE* archivoAmigos = fopen("./Data/Amigos.txt", "a");
    if (archivoAmigos == NULL) {
        printf("Error al abrir el archivo de amigos.\n");
        fclose(archivoUsuarios);
        return;
    }
    
    // Buscar el nombre de usuario en el archivo de usuarios
    char linea[MAX_LINE_LENGTH];
    int idUsuarioDestino = -1;
    char IdUserFinal;
    
    while (fgets(linea, sizeof(linea), archivoUsuarios) != NULL) {
        // Obtener el nombre de usuario de la línea
        char* token = strtok(linea, ",");
        if (token != NULL) {
            // Saltar los tokens hasta llegar al nombre de usuario
            idUsuarioDestino = atoi(token);
            printf("%d", idUsuarioDestino);
            for (int i = 0; i < 1; i++) {
                token = strtok(NULL, ",");
                printf("%s", token);
            }
            // Verificar si el nombre de usuario coincide
            if (strcmp(token, nombreUsuario) == 0) {
                break;
            } else {
              idUsuarioDestino = -1;
            }
        }
    }


    
    // Verificar si se encontró el nombre de usuario
    if (idUsuarioDestino == -1) {
        printf("\nEl usuario '%s' no existe.\n", nombreUsuario);
        fclose(archivoUsuarios);
        fclose(archivoAmigos);
        return;
    }
    
    // Obtener el siguiente ID de amistad
    FILE* archivoUsuariosID = fopen("./Data/Amigos.txt", "r");
    if (archivoUsuariosID == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }
    
    int IdAmistad = 2;
    char caracter;
    
    while ((caracter = fgetc(archivoUsuariosID)) != EOF) {
        if (caracter == '\n') {
            IdAmistad++;
        }
    }
    
    fclose(archivoUsuariosID);
    // Obtener data local.
    char fechaActual[50];
    time_t tiempoActual;
    struct tm *fecha;
    tiempoActual = time(NULL);
    fecha = localtime(&tiempoActual);
    strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", fecha);
  
    // Generar una nueva línea para agregar al archivo de amigos
    char nuevaLinea[MAX_LINE_LENGTH];
    sprintf(nuevaLinea, "\n%d, %d, %d, %s, 0", IdAmistad, ActualUser->id, idUsuarioDestino, fechaActual); // Actualiza "fecha_actual" con la fecha real
    
    // Escribir la nueva línea en el archivo de amigos
    fputs(nuevaLinea, archivoAmigos);
    
    // Cerrar los archivos
    fclose(archivoUsuarios);
    fclose(archivoAmigos);
    
    printf("\nSe ha enviado una solicitud de amistad a '%s'.\n", nombreUsuario);
}

void GestionateFriends(User* actualUser) {
    FILE* archivoUsuarios = fopen("./Data/Users.txt", "r");
    FILE* archivoAmistades = fopen("./Data/Amigos.txt", "r+");
  
    if (archivoUsuarios == NULL || archivoAmistades == NULL) {
        printf("No se pudieron abrir los archivos.\n");
        return;
    }
  
    int actualUserId = actualUser->id;
    char actualUsername[50];
    strcpy(actualUsername, actualUser->username);
    int contadorEnvia = 0;
    int contadorRecibe = 0;

    printf("\nAmistades enviadas por %s:\n", actualUsername);
  
    char lineaAmistad[100];
    long int posicionAntigua = ftell(archivoAmistades);

    while (fgets(lineaAmistad, sizeof(lineaAmistad), archivoAmistades) != NULL) {
        Amistad amistad;
        sscanf(lineaAmistad, "%d, %d, %d, %[^,], %d", &amistad.idAmistad, &amistad.idUsuarioEnvia, &amistad.idUsuarioRecibe, amistad.fecha, &amistad.estado);

        if (amistad.idUsuarioEnvia == actualUserId) {
            // Buscar el nombre de usuario correspondiente al idUsuarioRecibe
            fseek(archivoUsuarios, 0, SEEK_SET);
            char lineaUsuario[200];
            while (fgets(lineaUsuario, sizeof(lineaUsuario), archivoUsuarios) != NULL) {
                User usuario;
                sscanf(lineaUsuario, "%d,%[^,],", &usuario.id, usuario.username);

                if (usuario.id == amistad.idUsuarioRecibe) {
                    printf("\nSolicitud %d: %s --> %s (Estado: %d)\n", amistad.idAmistad, actualUsername, usuario.username, amistad.estado);
                    contadorEnvia++;
                    break;
                }
            }
        } else if (amistad.idUsuarioRecibe == actualUserId) {
            // Buscar el nombre de usuario correspondiente al idUsuarioEnvia
            fseek(archivoUsuarios, 0, SEEK_SET);
            char lineaUsuario[200];
            while (fgets(lineaUsuario, sizeof(lineaUsuario), archivoUsuarios) != NULL) {
                User usuario;
                sscanf(lineaUsuario, "%d,%[^,],", &usuario.id, usuario.username);

                if (usuario.id == amistad.idUsuarioEnvia) {
                    printf("\nSolicitud %d: %s <-- %s (Estado: %d)\n", amistad.idAmistad, usuario.username, actualUsername, amistad.estado);
                    contadorRecibe++;
                    break;
                }
            }
        }
    }

    if (contadorEnvia == 0) {
        printf("\nNo se encontraron más amistades enviadas por %s.\n", actualUsername);
    }

    if (contadorRecibe == 0) {
        printf("\nNo se encontraron más amistades recibidas por %s.\n", actualUsername);
    }

    // Pedir al usuario el número de solicitud para modificar el estado
    int numeroSolicitud;
    printf("Ingrese el número de solicitud recibida para modificar el estado (0 para no realizar cambios): ");
    scanf("%d", &numeroSolicitud);

    // Modificar el estado de la solicitud si se proporcionó un número válido
    if (numeroSolicitud != 0) {
        fseek(archivoAmistades, posicionAntigua, SEEK_SET);

        int encontrado = 0;

        while (fgets(lineaAmistad, sizeof(lineaAmistad), archivoAmistades) != NULL) {
            Amistad amistad;
            sscanf(lineaAmistad, "%d,%d,%d,%[^,],%d", &amistad.idAmistad, &amistad.idUsuarioEnvia, &amistad.idUsuarioRecibe, amistad.fecha, &amistad.estado);

            if (amistad.idAmistad == numeroSolicitud && amistad.idUsuarioRecibe == actualUserId) {
                encontrado = 1;
                // Modificar el estado de la solicitud
                if (amistad.estado == 0) {
                    amistad.estado = 1;
                    printf("\nLa solicitud %d ha sido aceptada.\n", amistad.idAmistad);
                } else if (amistad.estado == 1) {
                    amistad.estado = 0;
                    printf("\nLa solicitud %d ha vuelto a estar pendiente.\n", amistad.idAmistad);
                }

                // Actualizar la línea en el archivo
                fseek(archivoAmistades, -(strlen(lineaAmistad)), SEEK_CUR);
                fprintf(archivoAmistades, "%d, %d, %d, %s, %d\n", amistad.idAmistad, amistad.idUsuarioEnvia, amistad.idUsuarioRecibe, amistad.fecha, amistad.estado);
                break;
            }
        }

        if (!encontrado) {
            printf("\nNo se encontró la solicitud con el número %d. Puede ser que esta solicitud la hayas enviado tu.\n", numeroSolicitud);
        }
    }

    fclose(archivoUsuarios);
    fclose(archivoAmistades);
}



