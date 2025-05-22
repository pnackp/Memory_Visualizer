#ifndef UNDO_REDO_H
#define UNDO_REDO_H
#include "memory.h"

#define Array_MAX 5

typedef struct undo_redo{
	int size;
	Block* arr[Array_MAX];
}undo_redo;

void data_redo();
void data_undo();

//for main
void undo_call();
void redo_call();

#endif
