#include <stdio.h>
#include <stdlib.h>

#include "3m.h"

typedef struct {
    int *list;
    int count;
    int round;
    double expected;
} TestCase;

TestCase tests[] = {
    //                    list, count, round, exp 
    { (int[]){ 1, 1, 1, 1       },  4,  2,  1.0 },
    { (int[]){ 1, 1, 1, 1, 1    },  5,  2,  1.0 },
    { (int[]){ 1, 2, 3, 4, 5    },  5,  2,  3.0 },
    { (int[]){ 3, 3, 8, 1       },  4,  2,  3.75},
    { (int[]){ 3, 3, 8, 1       },  4,  1,  3.8},
    { (int[]){ 1, 0, 1, 8, 2    },  5,  2,  2.4 },
    { (int[]){ 0, 1, 0, 2, 9    },  5,  2,  2.4 },
    { (int[]){ 0, 1, 0, 2, 9    },  5,  0,  2.0 },
};

int number_of_tests = sizeof(tests) / sizeof(tests[0]);

int main(){
    for (int i = 0; i < number_of_tests; i++) {
        TestCase test = tests[i];
        double actual = mean(test.count, test.list, test.round);
        
        printf("{");
        for(int j = 0; j < test.count; j++){
            printf(" %d", test.list[j]);
        }
        printf(" }:\n\t%s (got %f, expected %f)\n\n",
               actual == test.expected ? "PASS" : "FAIL",
               actual, test.expected);
    }
    return 0;
}

