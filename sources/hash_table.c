/*
#include "../headers/hash_table.h"
#include <string.h>

Entry hash_table[TABLE_SIZE];

unsigned int hash_function(const char *key) {
    unsigned int hash = 0;
    int i = 0;
    while (key[i] != '\0') {
        hash += (unsigned int)key[i];
        i++;
    }
    return hash % TABLE_SIZE;
}

void insert(const char *key, const char *value) {
    unsigned int index = hash_function(key);
    strcpy(hash_table[index].key, key);
    strcpy(hash_table[index].value, value);
}

const char *get(const char *key) {
    unsigned int index = hash_function(key);
    return hash_table[index].value;
}
*/