#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define TABLE_MAX_STR_LEN 10
#define TABLE_MAX 4294967296

// Using struct to save information to reduce 
typedef struct{
    uint64_t size;
    int len;
    int padding;
}table_t;

// This array keeps track of the maximum values for the required 
// length of each cell. This is limited by uint64_t values; any value 
// larger than 4294967296 will overflow when squared.
const uint64_t limits[] = {
    0, 3, 31, 316, 3162,31622, 316227, 
    3162277, 31622776, 316227766, 
    3162277660, TABLE_MAX 
};

enum DigitLength{
    DIGIT_ONE,
    DIGIT_TWO,
    DIGIT_THREE,
    DIGIT_FOUR,
    DIGIT_FIVE,
    DIGIT_SIX,
    DIGIT_SEVEN,
    DIGIT_EIGHT,
    DIGIT_NINE,
    DIGIT_TEN,
    DIGIT_ELEVEN,
    DIGIT_TWELVE,
    DIGIT_THIRTEEN,
    DIGIT_FOURTEEN,
    DIGIT_FIFTEEN,
    DIGIT_SIXTEEN,
    DIGIT_SEVENTEEN,
    DIGIT_EIGHTEEN,
    DIGIT_NINETEEN,
    DIGIT_TWENTY
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

    printf("Your value: %ld\n", table.size);
    
    return 0;
}

// Simple loop to calculate memory per string.
void build_string(table_t *table)
{
    uint64_t current_limit = limits[0];
    for(int i = 0; i < table->len; i++){


    }
    switch()
}

bool valid_user_input(table_t *table)
{
    int buffer_max = TABLE_MAX_STR_LEN + 1;
    char buffer[buffer_max];
    bool valid = true;
    int c, largest, n = 0;

    memset(buffer, 0, sizeof(buffer));
    memset(table, 0, sizeof(table_t));

    // Read an entire line
    // Guarantee input does not exceed buffer
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            //discard leading 0's
            if(n == 0 && c == '0')
                continue;
            buffer[n++] = (char) c;
            if(c < '0' || c > '9' || n > buffer_max)
                valid = false;
        }
    }

    if(!valid || n == 0)
        return false;

    table->size = (uint64_t) strtoull(buffer, NULL, 10);

    if(table->size > TABLE_MAX)
        return false;

    // Get max width (table->len)
    largest = table->size * table->size;
    for(int i = 0; i <= TABLE_MAX_STR_LEN; i++){
        if(largest <= limits[i]){
            table->len = (2 * i) - 1;
            break;
        }
    }

    if(table->len == 0)
        return false;

    return true;
}

