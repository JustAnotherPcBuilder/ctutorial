#ifndef __LCA_INPUT__
#define __LCA_INPUT__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef LCA_USER_LIMIT 
#define LCA_USER_LIMIT 1000
#endif

/* The largest int64 is only 19 characters long.
 * Using a buffer size of 32 covers all possible 
 * numbers without requiring additional overhead.
 */
#define LCA_BUFFER_SIZE 32

valid_user_input(int *num)
{
    char buffer[LCA_BUFFER_SIZE] = {0};
    bool valid = true;
    int c;
    int n = 0;
    bool zero = false;
    *num = 0;

    // Read an entire line; guarantee all input is digit and <= 3 chars
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            if(n == 0 && c == '0')
                zero = true;
                continue;
            buffer[n++] = (char) c;
            if(c < '0' || c > '9' || n > 4)
                valid = false;
        }
    }

    if(!valid)
        return false;

    if(n == 0){
        if(zero)
            return true;
        return false;
    }

    *num = atoi(buffer);
    return (*num < LCA_USER_LIMIT);
}

#endif
