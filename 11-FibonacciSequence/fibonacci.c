#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fib_loop(int n);
int fib_rec(int n, ...);
bool valid_user_input(int *num);

int main(){
    int num;
    while(1){
        printf("Enter num: ");
        if(valid_user_input(&num))
            break;
        printf("Bad input. Try again.\n");
    }

    // int a = fib_loop(num);
    // printf("Fibunacci Loop Result: %d\n", a);
    int a = fib_rec(num);
    printf("Fibunacci Recursion Result: %d\n", a);
    return 0;
}

int fib_loop(int n)
{
    if(n == 0)
        return 0;

    int temp = 0;
    int prev = 0;
    int fib = 1;

    for(int i = 0; i < n; i++){
        temp = fib;
        fib += prev;
        prev = temp;
    }

    return fib;
}

int fib_rec(int n, ...)
{
    static bool first = true;
    int fib = 1;
    int prev = 0;

    if(!first){
        va_list args;

        va_start(args, n);

        fib = va_arg(args, int);
        prev = va_arg(args, int);
        if(n == 1)
            return fib + prev;

    }else{
        first = false;
        if(n == 1)
            return 1;
    }


    if(n == 1)
        return fib + prev;

    return fib_rec(n - 1, fib + prev, fib);
}

bool valid_user_input(int *num)
{
    // Hard limit set to 1000x1000 table for funsies
    char buffer[5] = {0};
    bool valid = true;
    int c;
    int n = 0;

    // Read an entire line; guarantee all input is digit and <= 3 chars
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            if(n == 0 && c == '0')
                continue;
            buffer[n++] = (char) c;
            if(c < '0' || c > '9' || n > 4)
                valid = false;
        }
    }

    if(!valid || n == 0)
        return false;

    *num = atoi(buffer);
    return (*num < 1001);
}
