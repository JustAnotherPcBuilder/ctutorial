#ifndef __HANGMAN_ENGINE_C__
#define __HANGMAN_ENGINE_C__
/****** Hangman ******
 -----
|     |
|    \0/
|     |
|    / \
|
|
*********************
[_][A][_][_][_][A][_]

Your Guesses: A, I, O
Lives Remaining: 5/6
Guess a letter: _
*/
#include <stdlib.h>

#define MAX_WORD_LENGTH 35
#define MAX_WORDS       85948

// Keep track of words used from dictionary
char *selected_words = (char *)calloc(sizeof(char), MAX_WORDS);

/*
 * transforms letters into index for tracking which letters are guessed
 */
int letter_to_index(char ch){
    int num;
    if(ch >= 'a' && ch <= 'z'){
        num = (int) ch - 'a';
    }else if(ch >='A' && ch <= 'Z'){
        num = (int) ch - 'A';
    }else{
        return num = -1;
    }
    return num;
}

/*
 * Checks whether the word has already been selected.
 * Creates a printable string to display for the game.
 * Creates data-structure of letters with number to update stringgame.
 * Creates data-structure of letters with number to update string
 */
int init_word(int id, char *word){
    if(id <= 0){
        fprintf(stderr, "Invalid id entered: %d.\n", id);
        return 1;
    }
    if(word == NULL){
        fprintf(stderr, "NULL word in init_word().\n");
        return 1;
    }

    int len = strlen(word);
    for(int i = 0; i < len; i++){

    }
    
} 

#endif
