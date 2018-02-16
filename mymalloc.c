#include <stdio.h>
#include <stdlib.h>

#define malloc(x) mymalloc(x, __FILE__,__LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)

static char myblock[5000]; // creates the array that will represent memory

struct node { // represents the data stored in each node of the linked list, whether a block of memory is full, and how many bytes/size of each block allocated
	int free; 		// 1 = full, 0 = empty
	size_t size; 		// size of allocated block
	struct node *next; 	// points to next block of allocated memory
};

struct node *block = myblock; 	// points to first element of myblock[5000], will be used as reference to head of list

void initialize(){	// creates the first memory block for memory
	head_list->size = 5000 - sizeof(struct node);
	head_list->free = 1;
	head_list->next = NULL;
}

void * mymalloc(size_t x, __FILE__, __LINE__){
	if(x <= 0){		// makes sure x is a positive number
		return NULL;
	}
	if(x > 5000){		// makes sure emory requested is not larger than memory available 
		return NULL;
	}
	if(x > remaining_size){	// not yet defined but easy way to keep track of if there's space left or not
		printf("the size of the block is too small\n");
		exit(0);
	}
}


int main(int argc, char **argv){
	return 0;
}
