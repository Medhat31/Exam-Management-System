#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>
#include "DB_Manipulation.h"
#include "User.h"
#include "Student.h"
#include "Instructor.h"

using namespace std;

class Admin : public User
{
public:

    Admin(string userName, string password) : User(0, userName, password) {}


    bool login(sqlite3* db, const string& username, const string& password) override;


    void addStudent(sqlite3* db, Student &S);
    void updateStudentData(sqlite3* db, int stud_id);
    void removeStudent(sqlite3* db, int stud_id);


    void addInstructor(sqlite3* db, Instructor &I);
    void updateInstructorData(sqlite3* db, int instructor_id);
    void removeInstructor(sqlite3* db, int instructor_id);


    void viewStudentDegree(sqlite3* db, int student_id);
    void viewAllGrades(sqlite3* db);
};

#endif // ADMIN_H
