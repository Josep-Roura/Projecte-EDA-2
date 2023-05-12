/*
#include "../headers/grafs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createGraph(Graph *graph) {
    graph_init(graph);
}

void readUsersFile(Graph *graph) {
    FILE *file = fopen("./Data/Users.txt", "r");
    if (file == NULL) {
        printf("Error: No se pudo abrir el archivo Users.txt\n");
        return;
    }

    char line[100];
    fgets(line, sizeof(line), file);  // Ignorar la primera línea de encabezado

    while (fgets(line, sizeof(line), file) != NULL) {
        int idUser, edad;
        char username[20], password[20], email[50], ciudad[20], dataActual[20], gusto1[20], gusto2[20], gusto3[20];

        sscanf(line, "%d,%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
               &idUser, username, password, &edad, email, ciudad, dataActual, gusto1, gusto2, gusto3);

        graph_add_node(graph, username);
    }

    fclose(file);
}

void readFriendsFile(Graph *graph) {
    FILE *file = fopen("./Data/Amigos.txt", "r");
    if (file == NULL) {
        printf("Error: No se pudo abrir el archivo Amigos.txt\n");
        return;
    }

    char line[100];
    fgets(line, sizeof(line), file);  // Ignorar la primera línea de encabezado

    while (fgets(line, sizeof(line), file) != NULL) {
        int idAmistad, idUser1, idUser2, state;
        char data[20];

        sscanf(line, "%d,%d,%d,%[^,],%d", &idAmistad, &idUser1, &idUser2, data, &state);

        char username1[20];
        char username2[20];
        graph_get_node_value(graph, idUser1, username1);
        graph_get_node_value(graph, idUser2, username2);

        if (state == 1) {
            graph_add_edge(graph, username1, username2, "Aceptada", "color=blue");
        } else if (state == 0) {
            graph_add_edge(graph, username1, username2, "Pendiente", "color=red");
        }
    }

    fclose(file);
}

void printGraph(Graph *graph) {
    graph_print(graph);
}

void saveGraphAsImage(Graph *graph, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: No se pudo crear el archivo de imagen.\n");
        return;
    }

    graph_save_as_dot(graph, file);

    fclose(file);
}
*/