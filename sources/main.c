#include "../headers/menu.h"
#include "../headers/terms.h"
#include "../headers/user.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // Se muestra el mensaje de bienvenida
    printf("Bienvenidos a nuestra red social de música!\n");

    int option = 0;
    do {
        show_menu();
        printf("Ingrese la opción deseada: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Opción 1 seleccionada: Insertar nuevo usuario.\n");
                // Aquí irá el código para insertar un nuevo usuario.
                User users;
                int *num_users;
                add_new_user(&users, num_users);
                break;
            case 2:
                printf("Opción 2 seleccionada: Listar todos los usuarios existentes.\n");  // Josep
                print_users();
                // Aquí irá el código para listar todos los usuarios existentes.
                break;
            case 3:
                printf("Opción 3 seleccionada: Operar como un usuario específico.\n"); // Eric
                // Aquí irá el código para operar como un usuario específico.
                break;
            case 4:
                printf("Opción 4 seleccionada: Enviar solicitudes de amistad.\n"); // Josep
                // Aquí irá el código para enviar solicitudes de amistad.
                break;
            case 5:
                printf("Opción 5 seleccionada: Gestionar las solicitudes pendientes.\n");
                // Aquí irá el código para gestionar las solicitudes pendientes.
                break;
            case 6:
                printf("Opción 6 seleccionada: Realizar una publicación.\n");
                // Aquí irá el código para realizar una publicación.
                add_publication();
                break;
            case 7:
                printf("Opción 7 seleccionada: Listar las publicaciones del usuario seleccionado.\n");
                // Aquí irá el código para listar las publicaciones del usuario seleccionado.
                break;
            case 8:
                printf("Opción 8 seleccionada: Volver al menú principal.\n");
                break;
            case 9:
                printf("Opción 9 seleccionada: Mostrar términos de uso.\n");
                terms_of_use();
                break;
            case 10:
                printf("Opción 10 seleccionada: Salir (Terminar ejecución).\n");
                break;

            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (option != 10);

  return 0;
}