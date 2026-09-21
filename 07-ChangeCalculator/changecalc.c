/*
 * Change Calculator
 * *****************
 * Prints out the change to hand out 
 *
 * Bills: 100, 20, 10, 5, 1
 * Coins: 25, 10, 5, 1
 */

#include <stdio.h>
#include <string.h>

void print_change(int big, int small);
int verify_input(char *input, int *big, int *small);

int main()
{
    char input[64];
    int big, small;

    while(1){
        printf("Enter Quantity (or q to quit): ");
        scanf("%63s", input);

        if(!strcmp(input, "q"))
            break;

        if(!verify_input(input, &big, &small)){
            printf("Bad input");
            continue;
        }
        
        print_change(big, small);
    }
    return 0;
}

int verify_input(char *input, int *big, int *small)
{
    return 0;
}

void print_change(int big, int small)
{

}

