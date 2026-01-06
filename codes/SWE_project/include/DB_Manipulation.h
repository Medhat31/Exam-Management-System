#ifndef DB_MANIPULATION_H
#define DB_MANIPULATION_H
#include <iostream>
#include "../sqlite3.h"
#include <string>

using namespace std;

void executeQuery(sqlite3* db, string sql);
static int printData(void* data, int argc, char** argv, char** azColName);
bool executeSelect(sqlite3* db, const string& sql);

#endif // DB_MANIPULATION_H
