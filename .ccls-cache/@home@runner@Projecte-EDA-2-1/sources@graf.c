#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/grafs.h"

void InsertarAmigo(NodoAmigo** lista, int idAmigo) {
    NodoAmigo* nuevoNodo = (NodoAmigo*)malloc(sizeof(NodoAmigo));
    nuevoNodo->idAmigo = idAmigo;
    nuevoNodo->siguiente = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        NodoAmigo* ultimo = *lista;
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nuevoNodo;
    }
}

void InsertarUsuario(NodoUsuario** listaUsuarios, int idUsuario) {
    // Verificar si el usuario ya existe
    NodoUsuario* nodoUsuarioExistente = *listaUsuarios;
    while (nodoUsuarioExistente != NULL) {
        if (nodoUsuarioExistente->idUsuario == idUsuario) {
            return;
        }
        nodoUsuarioExistente = nodoUsuarioExistente->siguiente;
    }

    // Crear un nuevo nodo de usuario
    NodoUsuario* nuevoNodo = (NodoUsuario*)malloc(sizeof(NodoUsuario));
    nuevoNodo->idUsuario = idUsuario;
    nuevoNodo->listaAmigos = NULL;
    nuevoNodo->siguiente = NULL;

    // Insertar el nuevo nodo al final de la lista de usuarios
    if (*listaUsuarios == NULL) {
        *listaUsuarios = nuevoNodo;
    } else {
        NodoUsuario* ultimo = *listaUsuarios;
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nuevoNodo;
    }
}


void AgregarAmistad(NodoUsuario** listaUsuarios, int idUsuario1, int idUsuario2) {
    NodoUsuario* nodoUsuario1 = *listaUsuarios;
    NodoUsuario* nodoUsuario2 = *listaUsuarios;
    while (nodoUsuario1 != NULL && nodoUsuario1->idUsuario != idUsuario1) {
        nodoUsuario1 = nodoUsuario1->siguiente;
    }
    while (nodoUsuario2 != NULL && nodoUsuario2->idUsuario != idUsuario2) {
        nodoUsuario2 = nodoUsuario2->siguiente;
    }

    if (nodoUsuario1 != NULL && nodoUsuario2 != NULL) {
        InsertarAmigo(&(nodoUsuario1->listaAmigos), idUsuario2);
        InsertarAmigo(&(nodoUsuario2->listaAmigos), idUsuario1);
    }
}

void LiberarListaAmigos(NodoAmigo* lista) {
    NodoAmigo* actual = lista;
    while (actual != NULL) {
        NodoAmigo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

void LiberarListaUsuarios(NodoUsuario* listaUsuarios) {
    NodoUsuario* actual = listaUsuarios;
    while (actual != NULL) {
        NodoUsuario* siguiente = actual->siguiente;
        LiberarListaAmigos(actual->listaAmigos);
        free(actual);
        actual = siguiente;
    }
}

void CrearGrafoAmistades() {
    FILE* archivoAmistades = fopen("./Data/Amigos.txt", "r");
    if (archivoAmistades == NULL) {
        printf("No se pudo abrir el archivo de amistades.\n");
        return;
    }

    NodoUsuario* listaUsuarios = NULL;

    char linea[100];
    while (fgets(linea, sizeof(linea), archivoAmistades) != NULL) {
        int idAmistad, idUsuarioEnvia, idUsuarioRecibe, estado;
        char fecha[50];
        sscanf(linea, "%d, %d, %d, %[^,], %d", &idAmistad, &idUsuarioEnvia, &idUsuarioRecibe, fecha, &estado);

        InsertarUsuario(&listaUsuarios, idUsuarioEnvia);
        InsertarUsuario(&listaUsuarios, idUsuarioRecibe);
        AgregarAmistad(&listaUsuarios, idUsuarioEnvia, idUsuarioRecibe);
    }

    fclose(archivoAmistades);

    // Imprimir el grafo de amistades representado por la lista de adyacencia
    NodoUsuario* nodoUsuario = listaUsuarios;
    while (nodoUsuario != NULL) {
        printf("Amistades de Usuario %d:", nodoUsuario->idUsuario);

        NodoAmigo* nodoAmigo = nodoUsuario->listaAmigos;
        while (nodoAmigo != NULL) {
            printf(" %d ", nodoAmigo->idAmigo);
            nodoAmigo = nodoAmigo->siguiente;
        }
        printf("\n");
        nodoUsuario = nodoUsuario->siguiente;
    }

    // Liberar memoria de la lista de usuarios y amigos
    LiberarListaUsuarios(listaUsuarios);
}
