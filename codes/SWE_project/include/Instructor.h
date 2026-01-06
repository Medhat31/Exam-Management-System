#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "User.h"
#include <iostream>
#include "DB_Manipulation.h"

using namespace std;

class Instructor : public User
{
public:
    // Constructor
    Instructor() : User(0, "", "") {}


    bool login(sqlite3* db, const string& username, const string& password) ;
    void addExam(sqlite3* db, const string& examName, const string& examDate, int duration);
    void addQuestion(sqlite3* db, int exam_id, const string& content, const string& o1, const string& o2,
const string& o3, const string& o4, const string& correct);
    void viewStudentResult(sqlite3* db, int student_id, int exam_id);
    void viewAllResults(sqlite3* db, int exam_id);
};

#endif
