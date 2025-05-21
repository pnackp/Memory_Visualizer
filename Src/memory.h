#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>

typedef struct Block {
    int size;
    int id;
    bool isFree; // 1 = Free, 0 = alloc
    struct Block* next;
    struct Block* prev; // ถ้าอยาก defrag ซ้าย-ขวา
} Block;

extern Block* head;

void my_malloc(int size);
void my_free(int index);
void show_memory();
void defragment();

#endif
