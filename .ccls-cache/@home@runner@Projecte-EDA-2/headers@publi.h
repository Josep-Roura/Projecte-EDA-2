#include "../headers/user.h"
#define MAX_LENGTH 256
#define MAX_PUBLICATIONS 100
#define MAX_LINE_LENGTH 1024

typedef struct {
  User *UserData;
  char song[MAX_LENGTH];
  char artist[MAX_LENGTH];
  char album[MAX_LENGTH];
  char link[MAX_LENGTH];
  int year;
} Publication;  

void add_publication(Publication* publication);