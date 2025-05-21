#ifndef UNDO_H
#define UNDO_H

#include "memory.h"
#define MAX_stack 5

typedef struct undo_redo{
	int size;
	Block* array[MAX_stack];
}undo_redo;

extern undo_redo* ur;

void keepdata(Block* origin);
void undo();

#endif
