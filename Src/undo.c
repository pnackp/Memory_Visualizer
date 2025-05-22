#include <stdio.h>
#include <stdlib.h>
#include "undo_redo.h"
#include "memory.h"

undo_redo* undo = NULL;
undo_redo* redo = NULL;

void re_space(){
	MAX = 100;
	Block *temp = head;
	while (temp != NULL) {
		if (!temp->isFree) {
			MAX -= temp->size;
		}
		temp = temp->next;
	}
	return;
}

void clearnode(Block *temp){	
	while(temp != NULL){
		Block * clear = temp;
		temp = temp->next;
		free(clear);
	}
	return;
}

void sortarray(undo_redo*temp){ // clear node inside first before sort 
	clearnode(temp->arr[0]);
	for (int i = 0 ; i < temp->size-1 ; i++){
		temp->arr[i] = temp->arr[i+1];
	}
	temp->size--;
	return;
}

void moveout(undo_redo*temp){
	sortarray(temp);
}

Block* copynode(Block *head){ // Linklist
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
	if (undo == NULL){undo = malloc(sizeof(undo_redo)); undo->size = 0;} // if NULL create and alloc
	if (undo->size >= Array_MAX){moveout(undo);}
	undo->arr[undo->size] = copynode(head); // undo->array[??] == NODE;
	undo->size++;// increase for next node coming it's mean if didn't add size still = NULL;
	return;
}

void data_redo(Block *head){
	if (redo == NULL){redo = malloc(sizeof(undo_redo)); redo->size = 0;}
	if (redo->size >= Array_MAX){moveout(redo);}
	redo->arr[redo->size] = copynode(head);	
	redo->size++;	
	return;
}

void undo_call(){
	if (undo->size <= 0){printf("Noting to undo\n");return;} // check if not empty
	undo->size--; // need to decrese first beause size == NULL; must -1 first
	data_redo(head);
	clearnode(head); // clear head before replace with new
	head = copynode(undo->arr[undo->size]);
	re_space();
	return;
}

void redo_call(){
	if (redo->size <= 0){printf("Noting to redo\n");return;} 
	redo->size--; 	
	clearnode(head); 	
	head = copynode(redo->arr[redo->size]);
	re_space();
	return;
}

