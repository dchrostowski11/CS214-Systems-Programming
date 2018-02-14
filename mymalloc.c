#include <stdio.h>
#include <stdlib.h>

#define malloc(x) mymalloc(x, __FILE__,__LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)

static char myblock[5000]; // creates the array that will represent memory

struct node { // represents the data stored in each node of the linked list, whether a block of memory is full, and how many bytes/size of each block allocated
	int full; // 1 = full, 0 = empty
	int size; // size of allocated block
	struct node * next; // points to next block of memory
};


void * mymalloc(size_t x, __FILE__, __LINE__){
	if(x == 0){
		return NULL;
	}
	
}


int main(int argc, char **argv){

	//int * head = myblock[0]; //used to keep a reference to the beginning of memory
	
		
	return 0;
}
