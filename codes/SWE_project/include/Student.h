#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>
#include <sqlite3.h>

using namespace std;

class Student : public User
{
public:
    // Constructor
    Student() : User(0, "", "") {}

    bool login(sqlite3* db, const string& username, const string& password);
    void showAvailableExams(sqlite3* db);
    void takeExam(sqlite3* db, int exam_id);
    void viewMyGrades(sqlite3* db);
};

#endif
