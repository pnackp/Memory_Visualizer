#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "undo_redo.h"
int main(){
	int input , size , index;
	do {
		printf("===== Memory Allocator Menu =====\n");
		printf("1. Allocate new memory\n");
		printf("2. Allocate free node memory\n");
		printf("3. Free memory\n");
		printf("4. Show memory\n");
		printf("5. Defragment\n");
		printf("6. Undo\n");
		printf("7. Redo\n");
		printf("8. Delete Node\n");
		printf("9. Clear Memory:\n");
		printf("10. Exit\n");
		printf("Choose:");
		scanf("%d",&input);

		switch (input) {
			case 1:printf("Enter size to allocate:");scanf("%d",&size);my_malloc(size);break;
			case 2:printf("Enter ID to allocate:");scanf("%d",&index);node_alloc(index);break;
			case 3:printf("Enter Block ID to free:");scanf("%d",&index);my_free(index);break;
			case 4:printf("Cureent Memory:\n");show_memory();break;
			case 5:defragment();break;
			case 6:undo_call();break;
			case 7:redo_call();break;
			case 8:printf("Enter ID to delete:");scanf("%d",&index);delet_node(index);break;
			case 9:clear_mem();break;
			default:printf("Invalid Number\n"); break;
		}
	}while (input != 10);
	printf("Good-Bye");
	return 0;
}
