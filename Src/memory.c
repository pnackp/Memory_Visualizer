#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include <stdbool.h>

int MAX = 100; // memory MAX
int id = 0 ; // set id every Block
Block *head = NULL;

void my_malloc(int size){
	if(size > MAX){printf("Have memory space:%d free\n",MAX); return;}
	MAX -= size;
	Block* temp = malloc(sizeof(Block));
	temp->size = size;
	temp->id = id; 
	temp->isFree = false;
	temp->next = head;
	temp->prev = NULL;
	if (head != NULL){
		head->prev = temp;
	}
	head = temp;
	printf("Allocated %d units at Block ID: %d\n" ,size,id);
	id++;
	return;
}

void my_free(int index)	{
	Block*ptr = head;
	while (ptr != NULL) {
		if (ptr->id == index && !ptr->isFree){
			ptr->isFree = true;
			return;
		}
		ptr = ptr->next;
	}
	printf("Invalid block ID\n");
	return;
}

void defragment(){
	Block* ptr = head;
	while (ptr != NULL){
		if (ptr->isFree && ptr->next != NULL && ptr->next->isFree){
			Block* def = ptr->next;
			while (def->isFree && def != NULL) {
				def = def->next;
				return;
			}
		}		
		ptr = ptr->next;
	}
	return;
}

void show_memory(){
	Block *ptr = head;
	while(ptr != NULL){
		printf("[ID: %d | ",ptr->id);
		printf(" Size: %d |",ptr->size);
		printf(" %s ] --> ", ptr->isFree ? "Free" : "Alloc");
		ptr = ptr->next;
	}
	printf("NULL\n");
	return;
}

void undo(){}

