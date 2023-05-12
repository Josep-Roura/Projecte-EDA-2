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
  printf("\nIntroducir nuevo nombre de usuario:");
  scanf("%s", Username);

  printf("\nIntroducir contraseña:");
  scanf("%s", Password);

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
  fprintf(archivo, "\n%d,%s,%s,%d,%s,%s,%s,%s,%s,%s", lineas, Username,
          Password, Age, Email, Location, fechaActual, Genre1, Genre2, Genre3);

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

// Imprimir ID y nombre de usuario de cada usuario ordenado.
void print_users() {
  int num_users = 0;
  User users[MAX_USERS];
  read_user(users, &num_users);
  for (int i = 0; i < num_users; i++) {
    printf("ID: %d, Username: %s\n", users[i].id, users[i].username);
  }
}

int user_log_in() {
  char *list_usernames[MAX_USERS];
  User users[MAX_USERS];
  int num_users = 0;
  read_user(users, &num_users);
  for (int i = 0; i < num_users; i++) {
    list_usernames[i] = users[i].username;
    // Convertimos los datos de nombres de usuario en una lista para que sea más facil trabajar con ellos.
  }
  int proof_username = 0;
  char username[MAX_USERS];
  int key = 0;
  printf("\nOperar como usuario:");
  scanf("%s", username);
  while (key < num_users) {
    if (strcmp(list_usernames[key], username) == 0) { // Comprobamos si existe el usuario.
      printf("\nUsuario %s encontrado.\n", username);
      proof_username = 1;
      break;
    }
    key++;
  }
  key++; // Esta key nos indicará que usuario listado está haciendo el login.
  if (proof_username == 0) {
    printf("\nUsuario %s no encontrado.\n", username);
  }
  if (proof_username == 1) {
    char *list_passwords[MAX_USERS];
    for (int i = 0; i < num_users; i++) {
      list_passwords[i] = users[i].password; // Convertimos los datos de contraseñas en una lista para que sea más facil trabajar con ellos.
    }
    int proof_password = 0;
    char password[MAX_LENGTH];
    printf("Introducir contraseña:");
    scanf("%s", password);
    for (int j = 0; j < num_users; j++) {
      if ((strcmp(list_passwords[j], password) == 0) && (key-1 == j)) { // Comprobamos si existe el usuario y si se corresponde con su respectiva contraseña. Lo hacemos mediante la key.
        printf("\nBienvenid@ %s.\n", username);
        proof_password = 1; 
        return 1;
      }
    }
    if (proof_password == 0) {
      printf("La contraseña es incorrecta.\n");
    }
  }
  return 0;
}

/*
void log_in_user() {
  FILE *fp;
  char username[MAX_LENGTH];
  User users;
  int num_users = 20;
  fp = fopen("./Data/Users.txt", "r");
  if (fp == NULL) {
    printf("Error. No se pudo abrir el archivo.\n");
    return;
  }
  copy_usernames_to_file(&users, num_users);
  printf("Operar como usuario: ");
  scanf("%s", username);
  int proof = linear_search_by_username(username);
  printf("%d",proof);
  fclose(fp);
}

void copy_usernames_to_file(User *users, int num_users) {
  FILE *outfile =
      fopen("./Data/Usernames.txt",
            "w"); // Creamos un archivo y lo abrimos en modo escritura.
  if (outfile == NULL) {
    printf("Error. No se pudo abrir el archivo.\n");
    return;
  }
  read_user(users, &num_users); // Leemos los usuarios del archivo y guardamos
                                // sus datos en estructuras de datos.
  for (int i = 0; i < num_users; i++) {
    fprintf(
        outfile, "%s\n",
        users[i].username); // Copiamos en el archivo los nombres de usuarios.
  }
  fclose(outfile); // Cerramos el archivo.
}

int linear_search_by_username(char *username) {
  FILE *file =
      fopen("./Data/Usernames.txt", "r"); // Abrimos el archivo con los nombres
                                          // de usuarios creado anteriormente.
  if (file == NULL) {
    printf("Error. No se puede abrir el archivo.\n");
    return 0;
  }

  char line[MAX_LENGTH];
  while (fgets(line, MAX_LENGTH, file) !=
         NULL) { // Analizamos todo el archivo hasta llegar al final.
    line[strcspn(line, "\r\n")] =
        0; // Eliminamos el salto de línea al final de la línea.
    if (strcmp(line, username) ==
        0) { // Si el usuario que buscamos coincide con el texto de la línea lo
             // indicamos por pantalla.
      printf("Usuario %s encontrado.", username);
      fclose(file); // Cerramos el archivo.
      return 1;
    }
  }
  printf("Usuario %s no encontrado.", username);
  fclose(file);
  return 0; // El usuario no fue encontrado.
}
*/