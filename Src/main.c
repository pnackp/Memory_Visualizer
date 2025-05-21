#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "undo.h"
int main(){
	ur = malloc(sizeof(undo_redo));
	ur->size = 0;
	int input , size , index;
	do {
		printf("===== Memory Allocator Menu =====\n");
		printf("1. Allocate memory\n");
		printf("2. Free memory\n");
		printf("3. Show memory\n");
		printf("4. Defragment\n");
		printf("5. Undo\n");
		printf("6. Exit\n");
		printf("Choose:");
		scanf("%d",&input);

		switch (input) {
			case 1:printf("Enter size to allocate:");scanf("%d",&size);my_malloc(size);break;
			case 2:printf("Enter Block ID to free:");scanf("%d",&index);my_free(index);break;
			case 3:printf("Cureent Memory:\n");show_memory();break;
			case 4:printf("Choose Defragmented memory:");scanf("%d",&size);break;
			case 5:printf("Undo:");undo();break;
			default:printf("Invalid Number\n"); break;
		}
	}while (input != 6);
	printf("Good-Bye");
	return 0;
}
