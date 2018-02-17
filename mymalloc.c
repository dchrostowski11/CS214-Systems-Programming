#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define malloc(x) mymalloc(x, __FILE__,__LINE__)
#define free(x) free(x, __FILE__, __LINE__)

struct node { /* represents the data stored in each node of the linked list, whether a block of memory is full, and how many bytes/size of each block allocated */
    int free; 		// 1 = full, 0 = empty
    size_t size; 		// size of allocated block
    struct node *next; // points to next block of allocated memory
};

static char myblock[5000];
int amountLeft = 5000;
char* temp = &myblock[0];
struct node* head = NULL;

struct node* getBlock(struct node** mynode, size_t size){
	
	struct node* curr = head;
	
	while(curr != NULL && !(curr->free && curr->size >=size)){
		*mynode = curr;
		curr = curr->next;
	}
	
	return curr;
}

struct node* createBlock(struct node* mynode, size_t size){
	struct node *curr;
	curr = (struct node*) (((char*)temp) + sizeof(struct node)+size);
	if(mynode == NULL){
		
		mynode = curr;
	}
	
	curr->size = size;
	curr->next = NULL;
	curr->free = 0;
	return curr;
	
}
void * mymalloc(size_t size){
	
	struct node * curr = (struct node*) (((char*)temp) + sizeof(struct node)+size);
	struct node * last = (struct node*) (((char*)temp) + sizeof(struct node)+size);
	
	if(size<=0 ){
		printf("Invalid amount of memory requested\n");
		return NULL;
	}
	
	if(size>amountLeft){
		printf("Not enough memory left\n");
		return NULL;
	}
	
	if(head == NULL){
		curr->size = size;
		curr->next = NULL;
		curr->free = 0;
		head = curr;
	}else{
		last = head;
		curr = getBlock(&last, size);
		
		if(curr == NULL){
			curr = createBlock(last, size);
			
			if(curr == NULL){
				printf("unable to allocate memory\n");
				return NULL;
			}
			amountLeft -= size + sizeof(struct node);
		}else{
			curr -> free = 0;
		}
	}
	
	printf("Successfully allocated %lu bytes of memory\n", size);
	return ++curr;
	
}

void myfree(void *ptr){
	if(ptr == NULL){
		printf("pointer does not exist in memory!\n");
		return;
	}
	struct node *curr = head;	//points to head of memory
	struct node *prev = curr;
	
	while(curr != NULL){	//searches memory till block is found
		if(curr == ptr && (curr->free == 0)){	//found the block, must set free to 1 and update amount of free space in memory
			if((prev->free == 0) && (curr->next->free == 0)){ //if neither adjacent block is free, just free curr
				curr->free = 1;
				printf("Successfully freed memory");
			}
			if((prev->free == 0) && (curr->next->free == 1)){	//if only next block is free, combine the size of memory left
				curr->free = 1;
				curr->size += ((curr->next->size)+sizeof(struct node));
				printf("Successfully freed memory");
			}
			if((prev->free == 1) && (curr->next->free == 0)){	//if only previous block is free
				curr->free = 1;
				prev->size += ((curr->next->size)+sizeof(struct node));
				printf("Successfully freed memory");
			}
			if((prev->free == 1) && (curr->next->free == 1)){
				curr->free = 1;
				prev->size += ((curr->size + sizeof(struct node)) + (curr->next->size + sizeof(struct node)));
				printf("Successfully freed memory");
			}
		}
		prev = curr;
		curr = curr->next;
	}
	
	printf("unable to free memory\n");
}


int main(int argc, char **argv){

//	int i;
	myfree(mymalloc(2));
    return 0;
}
