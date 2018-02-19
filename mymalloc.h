#ifndef mymalloc_h
#define mymalloc_h
#include <stdio.h>
#include <stddef.h> 
#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)

struct node {  /*represents the data stored in each node of the linked list, whether a block of memory is full, and how many bytes/size of each block allocated */
    int free; 		// 1 = full, 0 = empty
    size_t size; 		// size of allocated block
    struct node *next; // points to next block of allocated memory
}; 

struct node* createBlock(struct node* mynode, size_t size);
void *mymalloc(size_t size);
void myfree(void *ptr);

#endif
