/* Hangman.c 
 * ---------
 * Hangman game where a random number is created to grab a random word
 * from a dictionary database. This word will be compared against the 
 * user's previous guesses to complete the word or start another game.
 * Score is tracked.
 */

#include <stdio.h>
#include <sqlite3.h>

#define MAX_WORDS 85948
#define DATABASE_FILE "dictionary.db"

int main(){

    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open(DATABASE_FILE, &db);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    printf("Successfully opened database.\n");

    //SQL QUERY to get a specific rowid:
    //snprintf("SELECT * from words where rowid = %d;", rowid);
    sqlite3_close(db);

    return 0;
}


