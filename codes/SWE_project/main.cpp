#include <iostream>
#include "sqlite3.h"

using namespace std;

int main() {
    sqlite3* db;


    int exit = sqlite3_open("exam.db", &db);

    if (exit != SQLITE_OK) {
        cout << "Error opening DB: " << sqlite3_errmsg(db) << endl;
    } else {
        cout << "Mabrook! SQLite is working successfully inside Code::Blocks!" << endl;
    }

    sqlite3_close(db);
    return 0;
}
