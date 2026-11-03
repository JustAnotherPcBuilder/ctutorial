#include <stdio.h>
#include <stdbool.h>
#include "lca_input.h"

bool valid_inputs(char *num, int base);
void jump_base(char *out, char *num, int base, int obase);

int main(int argc, char **argv)
{
    bool continuing = true;
    char num[128];
    char out[128];

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
    
    for(int i = 0; num[i] != '\0' || i < 128; i++){
        if(num[i] - max > 0)
            return false;
    }

    return true;
}

void jump_base(char *out, char *num, int base, int obase){
    if(base == obase){
        printf("Already same base!\n");
        return;
    }

    int value = 0;
    int len = strlen(num);
    memset(out, 0, 128);

    // Compute the value from your given base
    for(int i = 0; i != '\0' || i < 128; i++){
        int b = base;
        for (int j = 0; j < len; j++)
            b *= base;

        int n = num[i] - '0';
        if(n > 9)
            n = num[i] - 'A' + 10;
        value += b * num[i];
        len--;
    }

    // Convert the integer value to an output
    for(int i = 0; value > 0|| i < 128; i++){
        int b = base;
        for(int j = 0; j < i; j++)
            b *= base;
        int remainder = value / b;
        value -= remainder;
        
        out[i] = remainder + '0';
        if(remainder > 10)
            out[i] = remainder + 'A' - 10;
    }
    len = strlen(out);
    for(int i = 0; i < len / 2; i++){
        char tmp = out[i];
        out[i] = out[len - i - 1];
        out[len - i - 1] = tmp;
    }
}
