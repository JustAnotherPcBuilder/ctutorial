#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 120

char *responses[] = {
    "Most undoubtably.", "It is written.", "Yes.", "Most assurably.",
    "Indeed.","Absolutely.", "You may rely on it.", "Most likely.",
    "This can never be.", "Unfortunately not.", "The gods will against this.", 
    "No.", "Absolutely not.", "Probably... not.", "I doubt it.", "Don't rely on it.",
    "This... I cannot say.","Unclear.","Try again, later.", "..." 
};

int f()
{
    return rand() % 19;
}

int main()
{
    char *question = NULL;
    size_t max = BUFFER_SIZE;
    srand(time(NULL));
    int r = f();
    printf("What does your heart desire to know?\n:");
    getline(&question, &max, stdin);

    printf("Visualizing the mind's eye...\n%s\n", responses[r] );
    free(question);
    return 0;
}


