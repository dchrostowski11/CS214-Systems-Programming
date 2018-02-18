#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mymalloc.c"

int main(int argc, char** argv){
	int i,j,n=0;
	int* arr[150];
	int* p, *q;
	for(i=0; i<100;i++){
		
		for(j=0; j<150;j++){
			p = (int *) mymalloc(1);
			myfree(p);
		}
		
		for(j=0; j<150; j++){
			arr[j] = (int *) mymalloc(1);
			myfree(arr[j]);
		}
		
		while(n>150){
			int x = rand();
			
			if(x%2 == 0){
				q = mymalloc(1);
			}else{
				myfree(q);
			}
			n++;
		}
		
		int n = 0, x;
		while(n>150){
			x = rand() % (64 - 1 - 1);
			n += x;
			q = mymalloc(1);
			myfree(q);
			
		}
		
	}
	return 0;
}
