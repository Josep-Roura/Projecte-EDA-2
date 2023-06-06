#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "../headers/publi.h"
#define MAX_LENGTH 256
#define MAX_LINE_LENGTH 1024

// 6. AÑADIR PUBLICACIÓN

// Estructura de la publicación:
// nº_publicación · álbum · artista · sello discográfico · año de publicación del album · descripción · canción favorita · usuario · fecha de la publicación.

Publication add_publication(User user) { // Función utilizada para añadir una publicación a través de la consola. Se añade al archivo Publications.txt y se añade al stack en el archivo main.c. La función recibe un usuario (que será el usuario logueado a través de la opción 3.) 
  
    // A través de diversos 'scanf', recogemos la información a través de la consola y se la asignamos a los distintos atributos de la publicación 'new_publication'. 
    Publication new_publication;
    getchar(); // Utilizamos la función getchar() para 'limpiar' el imput de la consola.
    printf("\nÁlbum:  ");
    scanf("%256[^\n]s", new_publication.album);
    getchar();
    printf("Artista:  ");
    scanf("%256[^\n]s", new_publication.artist);
    getchar();
    printf("Sello discográfico:  ");
    scanf("%256[^\n]s", new_publication.label);
    getchar();
    printf("Año de publicación:  ");
    scanf("%256[^\n]s", new_publication.year);
    getchar();
    printf("Descripción:  ");
    scanf("%256[^\n]s", new_publication.description);
    getchar();
    printf("Canción favorita:  ");
    scanf("%256[^\n]s", new_publication.track);
    
    
    
  // Una vez terminada la recogida de datos, añadimos los datos al archivo txt. Contamos las publicaciones previas para darle el numero de publicación a la nueva publicación.
  
     // Abrir el archivo en modo lectura y escritura.
    FILE *file2 = fopen("./Data/Publications.txt", "a+");
  
    if (file2 == NULL) { // Si no se puede abrir el archivo, se imprime el error y se hace return.
        printf("No se pudo abrir el archivo.\n");
        return;
    }
  
    // Contar las líneas en el archivo.
    int lineas_p = 1; 
    char caracter;
  
    while ((caracter = fgetc(file2)) != EOF) { // Realizamos una estructura while para contar cada línea del archivo. Se sumará una línea por cada salto de línea ('\n').
        if (caracter == '\n') {
            lineas_p++;
        }
    }
    
    // Asignamos el el valor del id de la publicación al siguiente valor del contador de líneas.
    new_publication.id_publication = (lineas_p + 1);
    
    // Obtener data local. Utilizamos distintas funciones de la libreria <time.h>
    char dateActual[50];
    time_t horaActual;
    struct tm *fecha1;
    horaActual = time(NULL);
    fecha1 = localtime(&horaActual);
    strftime(dateActual, sizeof(dateActual), "%Y-%m-%d", fecha1); // la variable dateActual representará la fecha en la que se realizó la publicación. Es una de las variables que se añadirán a la publicación al archivo txt. 
  
    
    // Escribir los datos en el archivo a través de la función fscanf.
    fprintf(file2, "\n%d · %s · %s · %s · %s · %s · %s · %s · %s", new_publication.id_publication, new_publication.album, new_publication.artist, new_publication.label, new_publication.year, new_publication.description, new_publication.track, user.username, dateActual);
  
    // Cerrar el archivo.
    fclose(file2);
  
    return new_publication; // La función devuelve una publicación que utilizaremos en el main para añadirlo al stack.
    
  }
  
  
  // 7. LISTAR LAS PUBLICACIONES DEL USUARIO REGISTRADO

// Ahora implementaremos una serie de funciones que utilizaremos en la implementación de la lista dinámica para listar las publicaciones del usuario logeado.
Publication* create_node() { //Función que crea el nodo de la lista dinámica
    Publication *node = (Publication*)malloc(sizeof(Publication)); // Reservamos espacio de memoria para el nodo.
    node->UserData = (User*)malloc(sizeof(User)); // Reservamos espacio de memoria para el usuario del que se listan las publicaciones.
    node->next = NULL; // Establecemos como vacío el siguiente elemento al nodo. 
    return node; // La función devuelve el nodo.
}

void insert_publication(Publication **head, Publication *node) { // El doble puntero a head representa la cabecera de la lista.
    if (*head == NULL) {
        *head = node; // Si la lista está vacía, el nodo se convierte en el head. 
    } else {
        Publication *current = *head; // Si existe una publicación en el puntero a head, el nodo se agrega a la lista después del último elemento (current).
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void free_list(Publication *head) { // Una vez mostradas por pantalla las publicaciones del usuario, necesitaremos una función que libere la memoria utilizada por los nodos y el usuario logueado.
    Publication *current = head;
    while (current != NULL) { // Con una estructura while, recorre y libera los elementos uno por uno y después el usuario.
        Publication *publi = current;
        current = current->next;
        free(publi->UserData);
        free(publi);
    }
}

// Una vez implementadas las funciones auxiliares, implementaremos la función que listará las publicaciones.
void list_publications(User user) { 
    
  // Abrimos el archivo de publicaciones en modo lectura.
    FILE *file1 = fopen("./Data/Publications.txt", "r");

    if (file1 == NULL) { // Si no se puede abrir el archivo, se imprime el error y se hace return. 
        printf("Error: No se pudo abrir el archivo.\n");
        return;
    }

    Publication *head = NULL; // Establecemos como nula la cabeza de la lista.
    char line[MAX_LINE_LENGTH]; // Creamos la variable 'line' que tendrá longitud máxima 'MAX_LINE_LENGTH' y que servirá para leer la información de cada línea del archivo de las publicaciones. Esta línea representará cad publicación en la línea.

    // Con una bucle while, extraemos todas las variables de la publicación para separarlas y asignarlas a la estructura del nodo. Las variables de la publicación están separadas por un carácter '·'. 
    while (fgets(line, MAX_LINE_LENGTH, file1) != NULL) {
        Publication *node = create_node(); // Utilizamos scanf para leer cada línea.
        sscanf(line, "%d · %[^·] · %[^·] · %[^·] · %[^·] · %[^·] · %[^·] · %[^ ·] · %[^\n]", &node->id_publication, node->album, node->artist, node->label, node->year, node->description, node->track, node->UserData->username, node->release_date);

        insert_publication(&head, node); // Tras esto, utilizamos esta función auxiliar para insertar el nodo con las variables recién asignadas en la lista dinámica.
    }

    fclose(file1); // Cerramos el archivo.



    // Buscamos las publicaciones que tengan el nombre de usuario ingresado y las imprimimos.
    Publication *current = head;
    while (current != NULL) {
        if (strcmp(current->UserData->username, user.username) == 0) {
            printf("\n%d · %s· %s· %s· %s· %s· %s· %s · %s\n", current->id_publication, current->album, current->artist, current->label, current->year, current->description, current->track, current->UserData->username, current->release_date);
        }
        current = current->next;
    }

  
    // Liberamos la memoria asignada para las publicaciones
    free_list(head);
}


// 8. LISTAR LAS PUBLICACIONES DE OTRO USUARIO.

// Esta función es igual que la anterior pero recibe un nombre de usuario por consola e imprime sus publicaciones. 

void list_publications_any_user() { 
    
    // Abrimos el archivo de publicaciones y asignamos a cada uno de los elementos de la línea a su valor correspondiente en la estructura de la publicación.
    FILE *file1 = fopen("./Data/Publications.txt", "r");

    if (file1 == NULL) { // Si no se puede abrir el archivo, se imprime el error y se hace return. 
        printf("Error: No se pudo abrir el archivo.\n");
        return;
    }

    Publication *head = NULL; // Establecemos como nula la cabeza de la lista.
    char line[MAX_LINE_LENGTH]; // Creamos la variable 'line' que tendrá longitud máxima 'MAX_LINE_LENGTH' y que servirá para leer la información de cada línea del archivo de las publicaciones. Esta línea representará cad publicación en la línea.

    // Con un bucle while, extraemos todas las variables de la publicación para separarlas y asignarlas a la estructura del nodo. Las variables de la publicación están separadas por un carácter '·'.  
    while (fgets(line, MAX_LINE_LENGTH, file1) != NULL) {
        Publication *node = create_node();
        sscanf(line, "%d · %[^·] · %[^·] · %[^·] · %[^·] · %[^·] · %[^·] · %[^ ·] · %[^\n]", &node->id_publication, node->album, node->artist, node->label, node->year, node->description, node->track, node->UserData->username, node->release_date);

        insert_publication(&head, node); // Tras esto, utilizamos esta función auxiliar para insertar el nodo con las variables recién asignadas en la lista dinámica.
    }

    fclose(file1);

    // Pedimos el nombre del usuario del que se quieren listar las publicaciones y lo modificamos para que el strcmp posterior se pueda hacer correctamente
    getchar();
    char user_name[MAX_LINE_LENGTH];
    printf("Introduzca el nombre del usuario: ");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = '\0';


    // Buscamos las publicaciones que tengan el nombre de usuario ingresado y las imprimimos
    Publication *current = head;
    while (current != NULL) {
        if (strcmp(current->UserData->username, user_name) == 0) {
            printf("\n%d · %s· %s· %s· %s· %s· %s· %s · %s\n", current->id_publication, current->album, current->artist, current->label, current->year, current->description, current->track, current->UserData->username, current->release_date);
        }
        current = current->next;
    }

  
    // Liberamos la memoria asignada para las publicaciones
    free_list(head);
}



// 9. REALIZAR CONTEO DE PALABRAS CON DICCIONARIO

// Creamos el diccionario con estructura w_count y longitud igual al numero de publicaciones por el máximo de publicaciones.
w_count dictionary[MAX_LINE_LENGTH*MAX_PUBLICATIONS];
int n_words = 0; // Variable que contabiliza el número de palabras distintas.

// Creamos la función que añadirá la palabra al diccionario o incrementará su conteo 
void add_word(const char *word){
    int i;
    int length = strlen(word);
    
    for (i = 0; i < length; i++){ //Chequeamos que no sea un símbolo la palabra.
        if (!isalpha(word[i])){
            return;
        }
    }
    
    char minuscula_word[50]; //Convertimos las mayúsculas en minúsculas para que sean iguales para el conteo (ejemplo 'The' y 'the').
    for (i = 0; i < length; i++) {
        minuscula_word[i] = tolower(word[i]);
    }
    minuscula_word[length] = '\0'; //Se añade al último carácter para que sea el carácter final.
  
    //Si existe la palabra en el diccionario, se incrementa su conteo.
    for (i = 0; i < MAX_LINE_LENGTH*MAX_PUBLICATIONS; i++) {
        if (strcmp (dictionary[i].word, minuscula_word) == 0){
            dictionary[i].count++;
            return;
        }
    }
  
    //Si no existe la palabra, se crea una variable con estructura w_count y se asigna el nombre de la palabra y se crea el conteo uno en la posición del diccionario 'n_word', que es el número de palabras distintas contabilizadas. 
    if (n_words < MAX_LINE_LENGTH*MAX_PUBLICATIONS) {
        strcpy(dictionary[n_words].word, minuscula_word);
        dictionary[n_words].count = 1;
        n_words++; // Aumenta el número de palabras distintas.
    } 
  
  }
  
// La siguiente función sirve para imprimir las 10 palabras más usadas.
void ranking_words(){
    int i = 0;
    int j = 1;
  
    w_count lil_word; //Esta variable representa la palabra más pequeña entre dos.
    
    
    // El bucle exterior maneja todas las palabras únicas del diccionario y el bucle interior realiza las comparaciones entre ellas, ordenándolas de mayor a menor (si dictionary[j] tiene menos repeticiones que dictionary[j+1], estas cambian el orden)  
    for (i = 0; i < n_words - 1; i++){
        for (j = 0; j < n_words - 1 - i; j++){
            if (dictionary[j].count < dictionary[j+1].count){
                lil_word = dictionary[j];
                dictionary[j] = dictionary[j+1];
                dictionary[j+1] = lil_word;
            }
        }
    }
  
    // Se imprimen las 10 primeras palabras del diccionario que serán las que más repeticiones tengan.
    printf("Las 10 palabras más usadas en las publicaciones son:\n");
    for (i = 0; i < n_words && i < 10; i++){
        printf("%d. %s: %d\n", i+1, dictionary[i].word, dictionary[i].count);
    }  
}
