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
		while(curr != NULL && !(curr->free && curr->size >=size)){
			curr = curr->next;
		}
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
	return (void*)++curr;
	
}

void myfree(void *ptr){
	struct node* myblock = (struct node*) ptr-1;
	struct node* myhead = head;
	if(!ptr){
		printf("Unable to free memory\n");
	}
	
	if(!myhead){
		printf("Unable to free memory\n");
	}
	
	
	while(myhead != NULL){
		if(myblock == myhead){
			if(myhead->free == 0){
				myhead->free = 1;
				printf("Successfully freed memory location\n");
				return;
			}else{
				printf("Memory location already freed\n");
				return;
			}
		}
		
		myhead = myhead->next;
	}
	
	printf("Memory location does not exist\n");
	return;
	
	
}


int main(int argc, char **argv){

	int i;
	//Just randomly testing stuff
	for(i=0;i<150;i++){
		int* p = (int*) mymalloc(1);
		myfree(p+10);
	}
    return 0;
}
