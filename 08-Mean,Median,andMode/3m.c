typedef struct{
    int count;
    int *list;
}mode_t;

typedef struct{
    int count;
    int list[2];
}median_t;

void free_mode_t(mode_t *p){
    if(p != NULL){
        if(p->list != NULL)
            free(p->list);
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

median_t *median(int count, int *list, int round){
    double median;
    // Sort list
    
    // Find mid point
    
    // Return both numbers if list is even
    
}

mode_t *mode(int count, int *list, int round){
    int mode;

    return mode;
}
