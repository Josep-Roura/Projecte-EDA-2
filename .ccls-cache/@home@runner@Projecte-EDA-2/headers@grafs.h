#ifndef GRAF_H
#define GRAF_H

typedef struct NodoAmigo {
    int idAmigo;
    struct NodoAmigo* siguiente;
} NodoAmigo;

typedef struct NodoUsuario {
    int idUsuario;
    NodoAmigo* listaAmigos;
    struct NodoUsuario* siguiente;
} NodoUsuario;

void InsertarAmigo(NodoAmigo** lista, int idAmigo);
void InsertarUsuario(NodoUsuario** listaUsuarios, int idUsuario);
void AgregarAmistad(NodoUsuario** listaUsuarios, int idUsuario1, int idUsuario2);
void LiberarListaAmigos(NodoAmigo* lista);
void LiberarListaUsuarios(NodoUsuario* listaUsuarios);
void CrearGrafoAmistades();

#endif  // GRAF_H
