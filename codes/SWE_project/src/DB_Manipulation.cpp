#include "DB_Manipulation.h"


void executeQuery(sqlite3* db, string sql) {
    char* messaggeError;
    int exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error: " << messaggeError << endl;
        sqlite3_free(messaggeError);
    }
}

// First, make sure you have the printer defined
static int printData(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "  ";
    }
    cout << endl;
    return 0;
}

// Second, the new function for selecting
void executeSelect(sqlite3* db, string sql) {
    char* error;
    // NOTICE: We replaced NULL with 'printData'
    int exit = sqlite3_exec(db, sql.c_str(), printData, 0, &error);

    if (exit != SQLITE_OK) {
        cerr << "Error: " << error << endl;
        sqlite3_free(error);
    }
}
