#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "3m.h"

int __compare_int(const void *arg1, const void *arg2){
    int a = *(const int *)arg1;
    int b = *(const int *)arg2;
    if(a < b)
        return -1;
    if(a > b)
        return 1;
    return 0;
}

void free_mode_t(m_mode_t *p){
    if(p != NULL){
        free(p);
    }
}

double mean(int count, int *list, int round){
    if(count < 1)
        return 0;
    
    if(round < 0)
        round = 0;

    double p = pow(10, round);
    int sum = 0;

    for(int i = 0; i < count; i++){
        sum += list[i];
    }

    double mean = (double) sum / (double) count;

    if(mean > 0.0f){
        return (double)((int)(mean * p + 0.5)) / p ;
    }

    return (double)((int)(mean * p - 0.5)) / p; 
}

int median(m_median_t *median, int count, int *list){
    if(!median)
        return -1;

    // Sort list
    qsort(list, count, sizeof(int), __compare_int);

    if(count % 2 == 0){
        median->count = 1;
        median->list[0] = list[(int) count / 2];
    }else{
        median->count = 2;
        median->list[1] = list[(int) count / 2];
        median->list[0] = list[(int) (count / 2 - 1)];
    }
    return 0;
}

int mode(m_mode_t *mode, int count, int *list){

    if(!mode)
        return -1;

	if(count < 1)
		return -1;

	int prev, cur, n, index, largest;

	// Need to account for the possibility that all elements are different
	int *tracker = calloc(count, sizeof(int));

	if(!tracker){
		perror("calloc");
		return -1;
	}

	// Sort the array to avoid the use of a hashmap
    qsort(list, count, sizeof(int), __compare_int);

	prev = list[0];
	index = n = largest = 1;
	tracker[0] = prev;

	// Track all instances, saving highest occurrence(s)
	for(int i = 1; i < count; i++){
		cur = list[i];

		if(cur == prev)
			n++;
		else
			n = 1;

		if(n == largest){
			// Add to tracker
			tracker[index] = cur;
			index++;

		}else if(n > largest){
			// Reset tracker
			index = 1;
			tracker[0] = cur;
			largest = n;
		}

		prev = cur;
	}

	// Allocate the array for the mode list
	mode->count = index;
	mode->list = malloc(sizeof(int) * index);
	if(!mode->list){
		perror("malloc mode->list");
		free(tracker);
		return -1;
	}

	for(int i = 0; i < index; i++){
		mode->list[i] = tracker[i];
	}
	
	free(tracker);
    return 0;
}
