/*
#ifndef GRAF_H
#define GRAF_H

#include "grapheasy.h"

typedef struct {
    char username[20];
} UserData;

typedef struct {
    int idAmistad;
    int idUser1;
    int idUser2;
    char data[20];
    int state;
} FriendshipData;

void createGraph(Graph *graph);
void readUsersFile(Graph *graph);
void readFriendsFile(Graph *graph);
void printGraph(Graph *graph);
void saveGraphAsImage(Graph *graph, const char *filename);

#endif  // GRAF_H
*/