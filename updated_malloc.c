#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "mymalloc.h"

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
		fprintf(stderr, "Invalid amount of memory requested %s: %d\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	
	if(size>amountLeft){
		fprintf(stderr, "Not enough memory left %s: %d\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
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
				fprintf(stderr, "unable to allocate memory %s: %d\n", __FILE__, __LINE__);
				exit(EXIT_FAILURE);
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

/*
int main(int argc, char **argv){
	
	struct timeval start,end;
	int *p, i;
	gettimeofday(&start, NULL);
	for(i = 0; i < 100; i++){
		p = mymalloc(20 *sizeof(int));
		myfree(p);
	}
	gettimeofday(&end, NULL);
	
	printf("%lu.%06lu\n", start.tv_sec, start.tv_usec);
	printf("%lu.%06lu\n", end.tv_sec, end.tv_usec);	
	
	printf("%f\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);
	printf("HELLO\n");
	
    return 0;
} */
