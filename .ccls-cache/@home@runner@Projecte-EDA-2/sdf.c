while (key < num_users && proof_username != 1) {
  if (strcmp(list_usernames[key], username) == 0) { 
    // Comprobamos si existe el usuario. Esta parte de código cuenta como implementación del algoritmo Linear Search.
    printf("\nUsuario %s encontrado.\n", username);
    proof_username = 1;
    break;
    
  } else {
    printf("\nUsuario %s no encontrado.\n", username);
  }
  key++;
}
