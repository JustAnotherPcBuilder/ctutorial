#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define TABLE_MAX_STR_LEN 10
#define TABLE_MAX 4294967296

// Using struct to save information to reduce 
typedef struct{
    uint64_t size;
    uint64_t len;
    int padding;
}table_t;

// This array keeps track of the maximum values for the required 
// length of each cell. This is limited by uint64_t values; any value 
// larger than 4294967296 will overflow when squared.
const int limits[] = {
    3, 31, 316, 3162,31622, 316227, 
    3162277, 31622776, 316227766, 
    3162277660, 3162277660 
};

bool valid_user_input(table_t *table);

int main(){

    // Get table size
    table_t table;

    while(1){
        printf("Enter a Multiplication Table Size:\n");
        if(valid_user_input(&table))
            break;
        printf("Invalid Entry.\n");
    }

    printf("Your value: %d\n", table_size);

    // Calculate max width

    
    return 0;
}

void build_string(table_t *table)
{
    
}

bool fast_str_len(int num){
    if(num < 0)
        return false;


}

calc_len(int num, int max){
    
}

bool valid_user_input(table_t *table)
{
    int buffer_max = TABLE_MAX_STR_LEN + 1;
    char buffer[buffer_max] = {0};
    bool valid = true;
    int c;
    int n = 0;

    // Read an entire line; guarantee all input is digit and <= max size
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            buffer[n++] = (char) c;
            if(c < '0' || c > '9' || n > buffer_max)
                valid = false;
        }
    }

    if(!valid || n == 0)
        return false;

    table->size = atoi(buffer);
    table->strlen = strlen(buffer);

    return (table->size < TABLE_MAX);
}

