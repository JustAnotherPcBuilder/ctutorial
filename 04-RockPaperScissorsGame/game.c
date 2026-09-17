/*### Rock Paper Scissors Game

Create a rock-paper-scissors game.

- Ask the player to pick rock, paper or scissors.
- Have the computer chose its move.
- Compare the choices and decide who wins.
- Print the results.

Subgoals:

- Give the player the option to play again.
- Keep a record of the score (e.g. Player: 3 / Computer: 6).

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int random_int(int start, int stop)
{
    static int seeded = 0;

    if(!seeded){
        srand(time(NULL));
        seeded = 1;
    }

    int range = stop - start + 1;
    int limit = RAND_MAX - (RAND_MAX % range);

    int r; 
    do{
        r = rand();
    }while (r >= limit);

    return start + (r % range);
}

int main()
{
    int player_score;
    int computer_score;
    return 0;
}


