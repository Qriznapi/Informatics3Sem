#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct dynarray {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

void* ecmalloc(size_t n);
void clear(Dynarray* pd);
void init(Dynarray* pd, size_t initial_size);
void reserve(Dynarray* pd, size_t new_capacity);
void push_back(Dynarray* pd, int x);
int get(const Dynarray* pd, size_t index);
void set(Dynarray* pd, size_t index, int value);
void print(const Dynarray* pd);
void destroy(Dynarray* pd);

#endif
