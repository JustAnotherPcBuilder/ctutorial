#include <stdio.h>
#include <sqlite3.h>

#define MAX_WORDS 86036 - 1
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

    sqlite3_close(db);

    return 0;
}
