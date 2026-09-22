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
#include <stdlib.h>
#include <stdbool.h>

void print_change(int big, int small);
bool verify_input(char *input, int *big, int *small);
bool is_numerical(char *str);

int main()
{
    char input[64] = {0};
    int big, small;

    while(1){
        printf("Enter Quantity (or q to quit): ");
        scanf("%63s", input);

        if(!strcmp(input, "q"))
            break;

        if(!verify_input(input, &big, &small)){
            printf("Bad input\n");
            continue;
        }
        
        print_change(big, small);
    }
    return 0;
}

bool verify_input(char *input, int *big, int *small)
{
	int count = 0;
	char *str;
	while((str = strtok(input, ".")) != NULL){
		switch(count++){
			case 0:
				if(!is_numerical(str))
					return false;
				*big = atoi(str);
				break;
			case 1:
				if(!is_numerical(str))
					return false;
				*small = atoi(str);
				break;
			default:
				return false;
		}
	}
    return true;
}

bool is_numerical(char *str)
{
	int i = 0;
	int c;
	while((c = str[i]) != '\0'){
		if(c < '0' || c > '9')
			return false;
		i++;
	}
	return true;
}

void print_change(int big, int small)
{
	printf("Dollars: %d\n", big);
	printf("Cents: %d\n", small);
}

