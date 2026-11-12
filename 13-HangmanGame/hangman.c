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

int initialize_database(sqlite3 **p_db, sqlite3_stmt **p_stmt);
int get_word_from_database(const unsigned char **word_ptr, sqlite3 *db, sqlite3_stmt *stmt, int row_id);

int main(){

    sqlite3 *db;        // database
    sqlite3_stmt *stmt; // statement
    const unsigned char *word = NULL;
    int id = 89;

    initialize_database(&db, &stmt);
    get_word_from_database(&word, db, stmt, id);
    if(word != NULL){
        printf("%s\n", word);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);


    return 0;
}

int initialize_database(sqlite3 **p_db, sqlite3_stmt **p_stmt){

    int rc; // return code
            
    rc = sqlite3_open_v2(DATABASE_FILE, p_db, SQLITE_OPEN_READONLY, NULL);

    sqlite3 *db = *p_db;

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database. RC: %d, MSG: %s\n", 
                rc, sqlite3_errmsg(db));
        sqlite3_close(db);
        return rc;
    }

    printf("Successfully opened database.\n");

    const char *sql_query = "SELECT * FROM words WHERE rowid = ?";
    rc = sqlite3_prepare_v2(db, sql_query, -1, p_stmt, NULL);

    if(rc != SQLITE_OK){
        fprintf(stderr, "Failed preparing SQL Statement. RC: %d, MSG: %s\n", 
                rc, sqlite3_errmsg(db));
        sqlite3_close(db);
    }

    return rc;
}

int get_word_from_database(const unsigned char **word_ptr, sqlite3 *db, sqlite3_stmt *stmt, int row_id){
    // Binding index 1 to variable 1, which should be an int
    // This is needed when using multiple ? parameters in a query
    // Since only a single ? is needed, only Index Parameter 1 is used
    int rc;
    rc = sqlite3_reset(stmt);
    rc = sqlite3_bind_int(stmt, 1, row_id);
    rc = sqlite3_step(stmt);

    switch(rc){
        case SQLITE_ROW:
            // This will occur after every successful step (returning data)
            *word_ptr = sqlite3_column_text(stmt, 0);
            break;

        case SQLITE_DONE:
            // This should occur only when database stepped through several times
            fprintf(stderr, "No match found! Row ID: %d\n", row_id);
            return 1;

        default:
            // Output any SQL Errors
            fprintf(stderr, "Return Code: %d, Msg: %s\n", rc, 
                    sqlite3_errmsg(db));
            sqlite3_close(db);
            return rc;
    }
    
    return 0;
}
