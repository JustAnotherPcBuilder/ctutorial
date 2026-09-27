#include <stdio.h>
#include <stdlib.h>

#include "3m.h"

typedef struct{
	int *data;
	int len;
}IntArray;

void get_stats(int len, int *list);

int main()
{
	IntArray a1 = { (int[]){ 1, 1, 1}, 3};
	IntArray a2 = { (int[]){ 1, 2, 3, 4, 5}, 5};
	IntArray a3 = { (int[]){ 1, 2, 3, 4}, 4};
	IntArray a4 = { (int[]){ 43, 3, 1234, 33, 1, 0, 3}, 7};
	IntArray a5 = { (int[]){ 1, 1, 2, 2, 3, 3, 4, 4 }, 8};
	IntArray a6 = { (int[]){ 4, 4, 3, 3, 2, 2, 1, 1}, 8};
	IntArray a7 = { (int[]){ 1, 4, 3, 2, 1, 2, 4, 3}, 8};
	IntArray a8 = { (int[]){ 1, 2, 3, 1, 2, 3, 3, 2, 1, 2 }, 10};

	IntArray array[] = { a1, a3, a3, a4, a5, a6, a7, a8};

	for(int i = 0; i < 8; i++){
		IntArray a = array[i];
		get_stats(a.len, a.data);
	}
	
    return 0;
}


void get_stats(int len, int *a){
	printf("{");
	for(int i = 0; i < len; i++){
		printf(" %d", a[i]);
	}
	printf(" }\n");
	m_median_t med;
	if(median(&med, 5, a) == -1)
		return ;
	m_mode_t mod;
	if(mode(&mod, 5, a) == -1)
		return ;
	double mn = mean(5, a, 2);

	printf("Mean: %f\n", mn);
	printf("Median:");
	for(int i = 0; i < med.count; i++){
		printf(" %d", med.list[i]);
	}
	printf("\n");

	printf("Mode:");
	for(int i = 0; i < mod.count; i++){
		printf(" %d", mod.list[i]);
	}
	printf("\n");
	
	if(med.count == 1){
		printf("Median: %d\n", med.list[0]);
	}
	free(mod.list);
}
