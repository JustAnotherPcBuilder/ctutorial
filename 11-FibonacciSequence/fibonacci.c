#include <stdint.h>

int fib_loop(int n){
    int fib = 1;

    for(int i = 0; i < n; i++){
        fib += i;
    }

    return fib;
}

int fib_rec(int n, ...){

    static int c = 1;
    int sum = 0;

    if(c > 1){
        va_list args;
        va_start(args, 1);
        sum = va_arg(args, int);
    }
    
    sum += c;
    c++;

    if(n == 0)
        return sum;

    return fib_rec(n - 1, sum);
}


