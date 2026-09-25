#include <stdlib.h>
#include <math.h>

typedef struct{
    int count;
    int *list;
}m_mode_t;

typedef struct{
    int count;
    int list[2];
}m_median_t;

int __compare_int(const void *arg1, const void arg2){
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

    void *mem = malloc(count * sizeof(int[2]));

    if(!mem)
        return -1;

    for(int = 0; i < count; i)

    return 0;
}
