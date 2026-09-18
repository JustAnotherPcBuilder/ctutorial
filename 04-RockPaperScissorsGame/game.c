#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_int(int start, int stop);

int main()
{
    int playing_game = 0;
    int player_score;
    char user_input[64] = {0};
    int computer_score;

    printf("ROCK PAPER SCICCORS!\n");
    printf("********************\n");

    do{
        // ask player for a choice
        printf("[0]: Rock\n[1]: Paper\n[2]: Scissors\n");
        scanf("Your selection: %s", user_input);

        printf("You selected: %s\n", user_input);
        // select pc choide
        // determine winner
        // ask to play again

    }while(playing_game);
    return 0;
}

int random_int(int start, int stop)
{
    static int seeded = 0;

    if(!seeded){
        srand(time(NULL));
    }

    int range = stop - start + 1;
    int limit = RAND_MAX - (RAND_MAX % range);

    int r; 
    do{
        r = rand();
    }while (r >= limit);

    return start + (r % range);
}
