#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_int(int start, int stop);

int main()
{
	int choice, cpu, win, lose;
    int playing_game = 1;
    int player_score = 0;
    int computer_score = 0;
	char user_input;

    printf("ROCK PAPER SCICCORS!\n");
    printf("********************\n");
	const char *options[3] = {"Rock", "Paper", "Scissors"};

    do{
        // ask player for a choice
        printf("[0]: Rock\n[1]: Paper\n[2]: Scissors\nYour selection: ");
		scanf(" %c", &user_input);
		choice = atoi(&user_input);
		
        // select pc choice
		cpu = random_int(0,2);
		printf("Computer's selection: %s\n", options[cpu]);

		// determine winner
		switch(choice){
			case 0:
				win = 2;
				lose = 1;
				break;
			case 1:
				win = 0;
				lose = 2;
				break;
			case 2:
				win = 1;
				lose = 0;
		}

		if(cpu == win){
			printf("Congrats! You win.\n");
			player_score++;
		}else if(cpu == lose){
			printf("Too Bad! You lose.\n");
			computer_score++;
		}
		printf("Player Score: %d\n", player_score);
		printf("Computer Score: %d\n", computer_score);
		
        // ask to play again
		while(1){
			printf("Play again?(y/n)\n");
			scanf(" %c", &user_input);
			if(user_input != 'y' && user_input != 'n'){
				printf("Invalid entry.\n");
				continue;
			}
			break;
		}

		if(user_input == 'n')
			playing_game = 0;

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
