#include "../headers/menu.h"
#include "../headers/terms.h"
#include "../headers/grafs.h"
#include "../headers/publi.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
  /*
    Graph graph;
    createGraph(&graph);
    readUsersFile(&graph);
    readFriendsFile(&graph);
    printGraph(&graph);
    saveGraphAsImage(&graph, "grafo.png");
*/  
    // Se muestra el mensaje de bienvenida
    printf("Bienvenidos a --nom aplicacio--, nuestra red social de música!\n");

    int option = 0;
    int log_in_completed = 0;
    do {
        show_menu();
        printf("Ingrese la opción deseada: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // DONE
                printf("Opción 1 seleccionada: Insertar nuevo usuario.\n");
                // Aquí irá el código para insertar un nuevo usuario.
                add_new_user();
                break;
            case 2: // DONE
                printf("Opción 2 seleccionada: Listar todos los usuarios existentes.\n");  // Josep
                print_users();
                // Aquí irá el código para listar todos los usuarios existentes.
                break;
            case 3: // DONE
                printf("Opción 3 seleccionada: Operar como un usuario específico.\n"); // Eric
                log_in_completed = user_log_in();
                // Aquí irá el código para operar como un usuario específico.
                break;
            case 4: //
              if (log_in_completed == 1) {
                printf("Opción 4 seleccionada: Enviar solicitudes de amistad.\n");
              }
              else {
                printf("\nDebes iniciar sesión primero.");
              }
                // Josep
                // Aquí irá el código para enviar solicitudes de amistad.
                break;
            case 5:
              if (log_in_completed == 1) {
                printf("Opción 5 seleccionada: Gestionar las solicitudes pendientes.\n");
              }
              else {
                printf("\nDebes iniciar sesión primero.");
              }
                // Aquí irá el código para gestionar las solicitudes pendientes.
                break;
            case 6:
              //if (log_in_completed == 1) {
                printf("Opción 6 seleccionada: Realizar una publicación.\n");
                add_publication();
              //}
                
              //else {
                //printf("\nDebes iniciar sesión primero.");
              //}
                // Aquí irá el código para realizar una publicación.
                //add_publication();
                break;
            case 7:
              if (log_in_completed == 1) {
                printf("Opción 7 seleccionada: Listar las publicaciones del usuario seleccionado.\n");
                list_publications();
              }
              else {
                printf("\nDebes iniciar sesión primero.");
              }
                // Aquí irá el código para listar las publicaciones del usuario seleccionado.
               // list_publications()
                break;
            case 8:
                printf("Opción 8 seleccionada: Mostrar términos de uso.\n");
                terms_of_use();
                break;
            case 9:
                printf("Opción 9 seleccionada: Salir (Terminar ejecución).\n");
                break;

            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (option != 9); // Se sale del bucle, y por lo tanto se cierra el menú, cuando se escoge una opción diferente a las posibles.

  return 0; 
}