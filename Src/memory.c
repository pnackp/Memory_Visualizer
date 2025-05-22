// Sorry for bad gramma , english 
//
// Memory Visual
//
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include <stdbool.h>
#include "undo_redo.h"

Block* head = NULL;
int MAX = 100; // memory MAX
int id = 0 ; // set id every Block

void my_malloc(int size){
	if(size > MAX){printf("Have memory space:%d free\n",MAX); return;}
	data_undo(head); // keep data in stack before do something
	MAX -= size;
	Block* temp = malloc(sizeof(Block)); // create new block // like normal doubly link list
	temp->size = size;
	temp->id = id; 
	temp->isFree = false;  
	temp->next = head; // set next is head 
	temp->prev = NULL; 
	if (head != NULL){
		head->prev = temp; // set prev
	}
	head = temp;
	printf("Allocated %d units at Block ID: %d\n" ,size,id);	
	id++;
	return;
}

void node_alloc(int index){
	if (head == NULL){printf("Empty Node\n");return;}
	data_undo(head);
	Block *ptr = head;
	while(ptr != NULL){
		if (ptr->id == index){ 
			if (ptr->isFree){
				ptr->isFree = false;
				printf("Block with ID %d has been successfully allocated.\n",index);
				return;
			}
			printf("Block with ID %d is already allocated.\n",index);
			return;
		}
		ptr = ptr->next;
	}
	printf("Invalid block ID\n");
	return;
}

void my_free(int index)	{
	data_undo(head);
	Block*ptr = head;
	while (ptr != NULL) {
		if (ptr->id == index && !ptr->isFree){
			ptr->isFree = true; // check if == number input and isfree = false set to free
			return;
		}
		ptr = ptr->next;
	}
	printf("Invalid block ID\n");
	return;
}

void defragment(){ // Concept check if ptr isfree and next is too .
	data_undo(head);
	Block* ptr = head; // then combine ptr with other block is free 
	while (ptr != NULL){
		if (ptr->isFree && ptr->next != NULL && ptr->next->isFree){
			Block* def = ptr->next; // def is RUNNER
	 		while (def != NULL && def->isFree) {
				Block* delet = def; // create delet for delete block
				ptr->size += def->size; // combine current * with another free
				ptr->next = def->next; 
				def = def->next;
				if (def != NULL){def->prev = ptr;} // check if next is not null
				free(delet); // free
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
		printf(" %s ] --> ", ptr->isFree ? "Free" : "Alloc"); // if else 
		ptr = ptr->next;
	}
	printf("NULL -> ");
	printf("%d free space\n",MAX);
	return;
}

void delet_node(int index){
	Block *ptr = head;
	while(ptr != NULL){
		if (ptr->id == index){
			if (ptr == head){
				head = ptr->next;
				if (head != NULL){head->prev = NULL;}
			}else {
				if (ptr->prev != NULL){
					ptr->prev->next = ptr->next;
				}
				if (ptr->next != NULL){
					ptr->next->prev = ptr->prev;
				}
			}
			MAX += ptr->size;
			free(ptr);
			printf("Block with ID %d has been deleted. Free space = %d \n", index, MAX);
			return;
		}
		ptr = ptr->next;
	}
	printf("No block found with ID %d.\n", index);
	return;
}

void clear_mem(){
	data_undo(head);
	while(head != NULL){
		Block*ptr = head;
		head = head->next;
		free(ptr);
	}
	printf("Memory has been cleared.\n");
	MAX = 100;
	printf("Available memory space: %d\n", MAX);
	return;
}


