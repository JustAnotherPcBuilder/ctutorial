#ifndef __LCA_INPUT_H_
#define __LCA_INPUT_H_

#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* The largest int64 is only 19 characters long.
 * Using a buffer size of 32 covers all possible 
 * numbers without requiring additional overhead.
 */
#define LCA_INT_BUFFER_SIZE 32

bool valid_user_int(int *num)
{
    char buffer[LCA_INT_BUFFER_SIZE] = {0};
    bool valid = true;
    int c;
    int n = 0;
    bool zero = false;
    *num = 0;

    // read any integer value; ignore leading 0's
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            if(n == 0){
                if(c == '0'){
                    zero = true;
                    continue;
                }
                if(c == '-'){
                    buffer[n++] = (char) c;
                    continue;
                }
            }
            buffer[n++] = (char) c;
            if(c < '0' || c > '9' || n == LCA_INT_BUFFER_SIZE)
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
    return true;
}

bool valid_hex_str(char *buffer, int size){
    memset(buffer, 0, size);
    bool valid = true;
    int c;
    int n = 0;
    bool zero = false;

    // read any integer value; ignore leading 0's
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            if(n == 0){
                if(c == '0'){
                    zero = true;
                    continue;
                }
                if(c == '-'){
                    buffer[n++] = (char) c;
                    continue;
                }
            }

            buffer[n++] = (char) toupper((unsigned char) c);
            if(!isxdigit((unsigned char) c) || n == LCA_INT_BUFFER_SIZE)
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

    return true;
}

int get_custom_int(int lower, int upper)
{
    int num;
    while(1){
        printf("Enter a number: ");
        if(valid_user_int(&num)){
            if(num >= lower && num <= upper)
                break;
        }
        printf("Invalid number! Must be between %d and %d!\n", lower, upper);
    }

    return num;
}

int get_whole(void)
{
    return get_custom_int(0, INT_MAX);
}

int get_int(void)
{
    return get_custom_int(INT_MIN, INT_MAX);
}


#endif
