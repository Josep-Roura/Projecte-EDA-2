#include "../headers/user.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LINE_LENGTH 1024



void add_new_user(User *users, int *num_users){
  User new_user;
  printf("\nIntroducir nombre de usuario:");
  scanf("%s", &new_user.username[MAX_LENGTH]);
  printf("\nIntroducir edad:");
  scanf("%d", &new_user.age);
  printf("\nIntroducir email:");
  scanf("%s", &new_user.email[MAX_LENGTH]);
  printf("\nIntroducir ubicación (ciudad):");
  scanf("%s", &new_user.location[MAX_LENGTH]);
  printf("\nIntroducir 3 géneros de música favoritos:");
  for (int i = 0; i<3; i++){
    scanf("%s", &new_user.genres[i][15]);
  }
}


void read_user(User *users, int *num_users){
  // Structure .txt : id, username, password, age, email, location, date, genres, genres, genres.
    FILE *file = fopen("./Data/Users.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        User user;
        sscanf(line, "%d,%255[^,],%255[^,],%d,%255[^,],%255[^,],%11[^,],%15[^,],%15[^,],%15s",
               &user.id, user.username, user.password, &user.age, user.email, user.location,
               user.date, user.genres[0], user.genres[1], user.genres[2]);
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

