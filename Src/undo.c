#include <stdio.h>
#include <stdlib.h>
#include "undo_redo.h"
#include "memory.h"

undo_redo* undo = NULL;

void clearnode(Block *temp){	
	while(temp != NULL){
		Block * clear = temp;
		temp = temp->next;
		free(clear);
	}
	return;
}

void sortarray(){
	clearnode(undo->arr[0]);
	for (int i = 0 ; i < undo->size-1 ; i++){
		undo->arr[i] = undo->arr[i+1];
	}
	undo->size--;
	return;
}

void moveout(){
	sortarray();
}

Block* copynode(Block *head){
	if (undo->size >= Array_MAX){moveout();}
	Block *temp = head;
	Block *lead = NULL;
	Block *tail = NULL;
	while (temp != NULL) {
		Block *new_node = malloc(sizeof(Block));
		new_node->size = temp->size;
		new_node->id = temp->id;
		new_node->isFree = temp->isFree;
		new_node->next = NULL;
		new_node->prev = NULL;
		if (lead == NULL){
			lead = new_node;
			tail = new_node;
		}else {
			new_node->prev = tail;
			tail->next = new_node;
			tail = new_node;
		}
		temp = temp->next;
	}
	return lead;
}

void data_undo(Block *head){
	if (undo == NULL){undo = malloc(sizeof(undo_redo)); undo->size = 0;}
	undo->arr[undo->size] = copynode(head);
	undo->size++;
	return;
}

void undo_call(){
}

