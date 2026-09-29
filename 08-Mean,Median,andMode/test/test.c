#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "3m.h"

typedef struct{
    int *list;
    int count;
    int round;
}TestCase;

TestCase tests[] = {
    { (int[]){ 1, 1, 1                      }, 3, 2},
    { (int[]){ 1, 2, 3, 4, 5                }, 5, 2},
    { (int[]){ 1, 2, 3, 4                   }, 4, 2},
    { (int[]){ 43, 3, 1234, 33, 1, 0, 3     }, 7, 2},
    { (int[]){ 1, 1, 2, 2, 3, 3, 4, 4       }, 8, 2},
    { (int[]){ 4, 4, 3, 3, 2, 2, 1, 1       }, 8, 2},
    { (int[]){ 1, 4, 3, 2, 1, 2, 4, 3       }, 8, 2},
    { (int[]){ 1, 2, 3, 1, 2, 3, 3, 2, 1, 2 }, 10,2}
};

int num = sizeof(tests) / sizeof(tests[0]);

void get_stats(int len, int *list);

int main()
{

    for(int i = 0; i < num; i++){
        TestCase test = tests[i];

        // Print list
        printf("{");
        for(int i = 0; i < test.count; i++){
            printf(" %d", test.list[i]);
        }
        printf(" }\n");

        m_median_t med;
        if(median(&med, test.count, test.list) == -1)
            return -1;

        m_mode_t mod;
        if(mode(&mod, test.count, test.list) == -1)
            return -1;

        double mn = mean(test.count, test.list, test.round);

        printf("Mean: %f\n", mn);
        printf("Median:");
        for(int i = 0; i < med.count; i++){
            printf(" %d", med.list[i]);
        }
        printf("\n");

        printf("Mode:");
        for(int i = 0; i < mod.count; i++){
            printf(" %d", mod.list[i]);
        }
        printf("\n");
        
        if(med.count == 1){
            printf("Median: %d\n", med.list[0]);
        }
        free(mod.list);   
    }
    
    return 0;
}
