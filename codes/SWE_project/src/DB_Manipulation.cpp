#include "DB_Manipulation.h"


void executeQuery(sqlite3* db, string sql) {
    char* messaggeError;
    int exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error: " << messaggeError << endl;
        sqlite3_free(messaggeError);
    } else {
        cout << "Query executed successfully." << endl;
    }
}

// First, make sure you have the printer defined
static int printData(void* data, int argc, char** argv, char** azColName) {
    int* rowCount = (int*)data;
    (*rowCount)++;

    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "  ";
    }
    cout << endl;

    return 0;
}

bool executeSelect(sqlite3* db, const string& sql) {
    char* error = nullptr;
    int rowCount = 0;

    int exit = sqlite3_exec(db, sql.c_str(), printData, &rowCount, &error);

    if (exit != SQLITE_OK) {
        cerr << "Error: " << error << endl;
        sqlite3_free(error);
        return false;
    }

    return rowCount > 0;  // THIS is your answer
}
