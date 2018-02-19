#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "mymalloc.h"
#include "mymalloc.c"

//NOT SURE IF THIS WILL WORK BUT I TRIED LOL
int main(int argc, char** argv){

	struct timeval total_start, start, end, total_end;

	int i,j,n=0, z=0;
	int* arr[150];
	int* p, *q, *a, *k;

	gettimeofday(&total_start, NULL);
	
	for(i=0; i<100;i++){
		//WORKLOAD 1
		gettimeofday(&start, NULL);
		for(j=0; j<150;j++){
			p = (int *) mymalloc(1);
			myfree(p);
		}
		gettimeofday(&end,NULL);
		//printf("%lu.%06lu\n", start.tv_sec, start.tv_usec);
		//printf("%lu.%06lu\n", end.tv_sec, end.tv_usec);	
		printf("WORKLOAD 1: %f\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);
		
		//WORKLOAD 2
		gettimeofday(&start, NULL);
		for(j=0; j<150; j++){
			arr[j] = (int *) mymalloc(1);
			myfree(arr[j]);
		}
		gettimeofday(&end,NULL);
		//printf("%lu.%06lu\n", start.tv_sec, start.tv_usec);
		//printf("%lu.%06lu\n", end.tv_sec, end.tv_usec);	
	
		printf("WORKLOAD 2: %f\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);
		
		//WORKDLOAD 3
		gettimeofday(&start, NULL);		
		while(n>150){
			int x = rand();
			
			if(x%2 == 0){
				q = (int*) mymalloc(1);
			}else{
				myfree(q);
			}
			n++;
		}
		gettimeofday(&end,NULL);
		//printf("%lu.%06lu\n", start.tv_sec, start.tv_usec);
		//printf("%lu.%06lu\n", end.tv_sec, end.tv_usec);	
	
		printf("WORKLOAD 3: %f\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);		
		
		//WORKLOAD 4
		gettimeofday(&start, NULL);		
		int n = 0, x;
		while(n>150){
			x = rand() % (64 - 1 - 1);
			printf("X is: %d\n", x);
			n += x;
			q = mymalloc(x);
			myfree(q);
		}	
		gettimeofday(&end,NULL);
		//printf("%lu.%06lu\n", start.tv_sec, start.tv_usec);
		//printf("%lu.%06lu\n", end.tv_sec, end.tv_usec);	
	
		printf("WORKLOAD 4: %f\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);				
	
		//WORKLOAD 5
		gettimeofday(&start, NULL);
		int num = 1;
		for(i = 0; i < 100; i++){
			a = (int*) mymalloc(num);
			myfree(a);
			num += 30;
		}
		gettimeofday(&end, NULL);
		printf("WORKLOAD 5: %f\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);						
		
		//WORKLOAD 6
		gettimeofday(&start, NULL);
		for(i = 0; i < 100; i++){
			k = (int*) mymalloc(5);
			myfree(k);
		}
		gettimeofday(&end, NULL);
		printf("WORKLOAD 6: %f\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);
		
	}
		
	gettimeofday(&total_end, NULL);
	printf("%lu.%06lu\n", total_start.tv_sec, total_start.tv_usec);
	printf("%lu.%06lu\n", total_end.tv_sec, total_end.tv_usec);	
	
	printf("%f\n", (total_end.tv_sec - total_start.tv_sec) + (total_end.tv_usec - total_start.tv_usec)/1000000.0);
	
	
	
	return 0;
}
