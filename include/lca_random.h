#ifndef __LCA_RANDOM_H__
#define __LCA_RANDOM_H__

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int random_int(int start, int stop)
{
    static int seeded = false;

    if(!seeded){
        seeded = true;
        srand(time(NULL));
    }

    int range = stop - start + 1;
    int limit = RAND_MAX - (RAND_MAX % range);

    int r; 
    do{
        r = rand();
    }while (r >= limit);

    return start + (r % range);
}

#endif
