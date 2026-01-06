#include "DB_Manipulation.h"


int main() {
    sqlite3* db;


    int exit = sqlite3_open("exam.db", &db);

    if (exit != SQLITE_OK) {
        cout << "Error opening DB: " << sqlite3_errmsg(db) << endl;
    } else {
//        cout << "Mabrook! SQLite is working successfully inside Code::Blocks!" << endl;
    }

//    string query = "INSERT INTO Students (name, password) VALUES ('Mohamed', 123) ";
//    executeQuery(db, query);

    string query;
//    query = "DELETE FROM Students WHERE student_id = 1;";
//    executeQuery(db, query);
//    query = "SELECT * FROM Students";
//    executeSelect(db, query);


    sqlite3_close(db);
    return 0;
}
