#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

// Using struct to save information to reduce 
typedef struct{
    uint64_t size;
    uint64_t max;
    int padding;
}table_t;

// This array keeps track of the maximum values for the required 
// length of each cell. This is limited by uint64_t values; any value 
// larger than 4294967296 will overflow when squared.
const int limits[] =
{
    3, 9, 31, 99, 316, 999, 3162, 9999, 
    31622, 99999, 316227, 999999, 3162277, 
    9999999, 31622776, 99999999, 316227766, 
    999999999, 3162277660, 9999999999, 3162277660, 4294967296
};

bool valid_user_input(table_t *table);

int main(){

    // Get table size
    table_t table;

    do{
        printf("Enter a Multiplication Table Size:\n");
        if(valid_user_input(&table))
            break;
        printf("Invalid Entry.\n");
    }while(1);

    printf("Your value: %d\n", table_size);

    // Calculate max width
    int max = table_size*table_size + 2;
    int len = 0;
    while(max > 0){
        max /= 10;
        len++;
    }
    // print table

    return 0;
}

bool valid_user_input(table_t *table)
{
    // Hard limit set to 1000x1000 table for funsies
    char buffer[5] = {0};
    bool valid = true;
    int c;
    int n = 0;

    // Read an entire line; guarantee all input is digit and <= 3 chars
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            buffer[n++] = (char) c;
            if(c < '0' || c > '9' || n > 4)
                valid = false;
        }
    }

    if(!valid || n == 0)
        return false;

    table->size = atoi(buffer);
    table->max = strlen(buffer);
    return (table->size > 0 && table->size < 1001);
}


