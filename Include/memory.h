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

extern int MAX;
extern Block* head;

void my_malloc(int size);
void node_alloc(int index);
void my_free(int index);
void show_memory();
void defragment();
void delet_node(int index);
void clear_mem();

#endif
