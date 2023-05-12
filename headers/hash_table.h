/*
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 100

typedef struct {
    char key[50];
    char value[50];
} Entry;

unsigned int hash_function(const char *key);
void insert(const char *key, const char *value);
const char *get(const char *key);

#endif /* HASH_TABLE_H */
