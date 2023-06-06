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
    // Se muestra el mensaje de bienvenida.
    printf("Bienvenidos a --nom aplicacio--, nuestra red social de música!\n");

    
    int option = 0;
    int log_in_completed = 0;
    User Actual;
    Publication new_publication;

    publication_stack stack;
    stack.top = -1;
    
    do {
        show_menu();
        printf("Ingrese la opción deseada: ");
        if (scanf("%d", &option) != 1) { // Hacemos esto para que no se quede en bucle imprimiendo el menú cuando introduzcamos en valor no numérico.
          fflush(stdin); // Limpiamos el buffer de entrada.
          getchar(); // Ignoramos el carácter no válido.
          printf("\nOpción no válida. Por favor, ingrese una opción válida.\n");
          continue; // Volvemos al inicio del bucle.
        }

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
                Actual = user_log_in();
                log_in_completed = 1;
                printf("%s", Actual.username);
               
                // Aquí irá el código para operar como un usuario específico.
                break;
            case 4: //
                if (log_in_completed == 1) {
                  printf("Opción 4 seleccionada: Enviar solicitudes de amistad.\n");
                  void new_friend();
                }
                else {
                  printf("\nDebes iniciar sesión primero.\n");
                }
                // Aquí irá el código para enviar solicitudes de amistad.
                break;
            case 5:
                if (log_in_completed == 1) {
                  printf("Opción 5 seleccionada: Gestionar las solicitudes pendientes.\n");
                }
                else {
                  printf("\nDebes iniciar sesión primero.\n");
                }
              // Aquí irá el código para gestionar las solicitudes pendientes.
              break;
          
            case 6:
                if (log_in_completed == 1) {
                  printf("Opción 6 seleccionada: Realizar una publicación y mostrar las publicaciones de la sesión actual.\n");
                  
                  new_publication = add_publication(Actual);
                  
                  // Añadimos la publiación al stack.
                  stack.top++;
                  stack.publications[stack.top] = new_publication;

                  int i;
                  printf("\nPublicado en la sesión actual:\n");
                  for (i = 0; i <= stack.top; i++) {
                      printf("\n%d · %s · %s · %s · %s · %s · %s · %s\n", stack.publications[i].id_publication, stack.publications[i].album,
         stack.publications[i].artist, stack.publications[i].label, stack.publications[i].year, stack.publications[i].description, stack.publications[i].track, Actual.username);
                  }
                }
                else {
                  printf("\nDebes iniciar sesión primero.\n");
                }
              break;
          
            case 7:
                if (log_in_completed == 1) {
                  printf("Opción 7 seleccionada: Listar las publicaciones del usuario seleccionado.\n");
                  list_publications(Actual);
                }
                else {
                  printf("\nDebes iniciar sesión primero.\n");
                }           
              break;

            case 8:
                if (log_in_completed == 1) {
                  printf("Opción 8 seleccionada: Listar las publicaciones de otro usuario. \n");
                  list_publications_any_user();
                }
                else {
                  printf("\nDebes iniciar sesión primero.\n");
                }           
              break;
          
            case 9:
              if (log_in_completed == 1) {
                printf("Opción 9 seleccionada: Realizar conteo de palabras.\n");

                char word[50];  
                FILE *file = fopen("./Data/Publications.txt", "r");
                if (file == NULL){
                  printf("Error. No se pudo abrir el archivo.");
                  return 1;
                }
                
                while (fscanf(file, "%s", word) != EOF){
                  add_word(word);
                }

                fclose(file);

                ranking_words();
                
              } else {
                  printf("\nDebes iniciar sesión primero.\n");
              }           
              break;

            
            case 10:
                printf("Opción 10 seleccionada: Mostrar términos de uso.\n");
                terms_of_use();
                break;
          
            case 11:
                printf("Opción 11 seleccionada: Salir (Terminar ejecución).\n");
                break;

            default:
                printf("\nOpción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (option != 11); 

  return 0; 

}