#include <stdio.h>
#include <stdbool.h>
#include "lca_input.h"

bool valid_inputs(char *num, int base);
void jump_base(char *out, char *num, int base, int obase);

int main(int argc, char **argv)
{
    bool continuing = true;
    char num[128] = {0};
    char out[128] = {0};

    while(continuing){
        continuing = false;
        printf("Enter a number to convert from: ");
        while(!valid_hex_str(num, 128)){
            printf("Invalid Entry!\n");
            printf("Enter a number to convert from: ");
        }
        printf("Enter the base of your entered number.\n");
        int base = get_custom_int(2, 16);

        printf("Enter the base to convert your number to.\n");
        int obase = get_custom_int(2, 16);

        if(!valid_inputs(num, base)){
            printf("%s is an invalid base %d!\n", num, base);
        }else{
            jump_base(out, num, base, obase);
            printf("%s (in base %d) is %s (in base %d)\n", num, base, out, obase);
        }
        
        printf("Continue(y)?: ");
        int count = 0;
        int c;
        while((c = getchar()) != '\n' && c != EOF){
            count++;
            if(c == 'y' || c == 'Y')
                continuing = true;
        }
        if(count > 1)
            continuing = false;
    };

    return 0;
}

bool valid_inputs(char *num, int base){
    int max = base + '0' - 1;

    if(base > 10)
        max = base + 'A' - 11;
    
    for(int i = 0; num[i] != '\0' && i < 128; i++){
        if(num[i] - max > 0)
            return false;
    }

    return true;
}

void jump_base(char *out, char *num, int base, int obase){

    memset(out, 0, 128);
    int len = (int) strlen(num);

    if(base == obase){
        printf("Already same base!\n");
        strncpy(out, num, len);
        return;
    }

    int value = 0;

    // Compute the value from your given base
    int b = 1;
    for(int i = len - 1 ; i >= 0 ; i--){
        if((num[i] - '0') > 9)
            value += b * (num[i] - 'A' + 10);
        else
            value += b * (num[i] - '0');
        
        b *= base;
    }

    // Convert the integer value to an output
    b = 1;
    while(b < value){
        b *= obase;
    }
    b /= obase;
    for(int i = 0; value >= 0 && i < 128; i++){
        if(value == 0){
            out[i] = '0';
            break;
        }
        out[i] = (value / b);
        if(out[i] > 10)
            out[i] += 'A' - 10;
        else
            out[i] += '0';
        value %= b;
        b /= obase;
    }
    
}
