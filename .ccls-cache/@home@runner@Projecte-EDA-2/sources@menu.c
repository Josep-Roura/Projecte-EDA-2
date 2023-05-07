#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/terms.h"
#include "../headers/menu.h"

void show_menu() {
  printf("Welcome to --nom aplicacio-- \n");
  printf("\n");

  int option_menu = INVALID_OPTION;
  while (option_menu != OPTION_QUIT) {
    printf (" 1) Register.\n 2) Log In.\n 3) Terms of Use.\n 0) Quit.\n");
    printf("Choose an option:\n");
    scanf("%d", &option_menu);
    if (option_menu == 1) {
      
    }
    else if (option_menu == 2) {
      
    }
    else if (option_menu == 3) {
      terms_of_use();
      printf("\nWhat do you want to do now?\n");
    }
  }
}

  