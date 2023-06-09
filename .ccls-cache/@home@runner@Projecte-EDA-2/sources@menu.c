#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/terms.h"
#include "../headers/menu.h"

void show_menu() {
    printf("\n");
    printf("\n--> MENÚ DE OPCIONES <--\n");
    printf("\n");
    printf("[1] Insertar nuevo usuario.\n");
    printf("[2] Listar todos los usuarios existentes.\n");
    printf("[3] Operar como un usuario específico.\n");
    printf("[4] Enviar solicitudes de amistad.\n");
    printf("[5] Gestionar las solicitudes pendientes.\n");
    printf("[6] Realizar una publicación y mostrar las publicaciones de la sesión actual.\n");
    printf("[7] Listar las publicaciones del usuario.\n");
    printf("[8] Listar las publicaciones de otro usuario.\n");
    printf("[9] Realizar conteo de palabras.\n");
    printf("[10] Crear grafo de las amistades.\n");
    printf("[11] Mostrar los términos de uso.\n");
    printf("[12] Salir (Terminar ejecución).\n");
    printf("--------------------------------------------\n");
}

  