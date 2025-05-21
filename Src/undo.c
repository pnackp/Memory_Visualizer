#include <stdio.h>
#include <stdlib.h>
#include "undo.h"
#include "memory.h"

undo_redo* ur = NULL;

void freeBlockList(Block* head) {
	while (head != NULL) {
		Block* fee = head;
		head = head->next;
		free(fee);
	}
}

void moveout(){
	freeBlockList(ur->array[0]); // free node inside 0 and sort arrays
	for (int i = 1; i < ur->size; i++) {
		ur->array[i - 1] = ur->array[i];
	}
	ur->size--;
	return;
}

Block* copynode(Block*origin){
	if (ur->size >= 5){moveout();} // if > 5 need to delete bottom first like queue
	Block *new_front = NULL;
	Block *rear = NULL ; 
	while(origin != NULL){
		Block *new_block = malloc(sizeof(Block));
		new_block->size = origin->size;
		new_block->id = origin->id;
		new_block->isFree = origin->isFree;
		new_block->prev = NULL;
		new_block->next = new_front;
		if (new_front != NULL){
			new_front->prev = new_block;
		}else {rear = new_block;}
		new_front = new_block;
		origin = origin->next;
	}
	return new_front;
}

void keepdata(Block* origin){// This fucntion for save data 
	ur->array[ur->size] = copynode(origin);  // keep data to structer array by call fucntion
	ur->size++;
	return;
}

void undo(){
	if (ur->size <= 0){printf("Stack-Empty\n");return;}
	ur->size--;
	freeBlockList(head); // deleted all head and replace with head saved
	head = copynode(ur->array[ur->size - 1]);
	return;
}


