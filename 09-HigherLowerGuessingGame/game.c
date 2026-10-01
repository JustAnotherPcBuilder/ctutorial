#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//CPU selects a number between 1 and 100 and the user has to guess what the number is.
typedef enum{
    G_STATE_START,
    G_STATE_USER_INPUT,
    G_STATE_COMPARE,
    G_STATE_TRY_AGAIN,
    G_STATE_UPDATE_SCORE,
    G_STATE_PLAY_AGAIN
}g_state_t;

typedef struct{
    g_state_t state;
    int cpu;
    int player;
    int score;
    bool playing;
}g_status_t;

int random_int(int start, int stop);
bool valid_user_input(int *guess);
bool valid_user_continue(bool *playing);

int main()
{

    g_status_t game = {G_STATE_START, 0, 0, 0, true};
    char *msg;
    int status = 0;

    while(game.playing){
        switch(game.state){
            case G_STATE_START:
                game.cpu = random_int(1,100);
                game.state = G_STATE_USER_INPUT;
                break;

            case G_STATE_USER_INPUT:
                printf("Enter a number between 1-100: ");
                if(valid_user_input(&(game.player)))
                    game.state = G_STATE_COMPARE;
                else
                    printf("Invalid input.\n");
                break;

            case G_STATE_COMPARE:
                game.state = G_STATE_TRY_AGAIN;
                if(game.cpu == game.player)
                    game.state = G_STATE_UPDATE_SCORE;
                break;

            case G_STATE_TRY_AGAIN:
                game.player < game.cpu ? (msg = "lower") : (msg = "higher");
                printf("Your score is %s than CPU!\nTry Again.\n", msg);
                game.state = G_STATE_USER_INPUT;
                break;

            case G_STATE_UPDATE_SCORE:
                printf("Congrats! You guessed correctly!\nYour score: %d\n", ++(game.score));
                game.state = G_STATE_PLAY_AGAIN;
                break;

            case G_STATE_PLAY_AGAIN:
                printf("Play again?(y/n)\n");
                if(valid_user_continue(&game.playing))
                    game.state = G_STATE_START;
                else
                    printf("Invalid input.\n");
                break;

            default:
                fprintf(stderr, "Should not occur...? Current State: %d", game.state);
                game.playing = false;
                status = 1;
                break;
        }
    }

    return status;
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

bool valid_user_input(int *guess)
{
    char buffer[4] = {0};
    bool valid = true;
    int c;
    int n = 0;

    // Read an entire line; guarantee all input is digit and <= 3 chars
    while((c = getchar()) != '\n' && c != EOF){
        if(valid){
            buffer[n++] = (char) c;
            if(c < '0' || c > '9' || n > 3)
                valid = false;
        }
    }

    if(!valid || n == 0)
        return false;

    *guess = atoi(buffer);
    return (*guess > 0 && *guess < 101);
}

bool valid_user_continue(bool *playing)
{
    char ch;
    int c;
    int n = 0;

    // Read an entire line; guarantee y/n answer
    while((c = getchar()) != '\n' && c != EOF){
        if(n++ == 0)
            ch = c;
    }

    if(n == 0 || n > 1)
        return false;
    
    if(ch == 'y' || ch == 'Y')
        return true;

    if(ch == 'n' || ch =='N'){
        *playing = false;
        return true;
    }

    return false;
}
