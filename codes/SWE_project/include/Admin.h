#ifndef ADMIN_H
#define ADMIN_H
#include "DB_Manipulation.h"
#include "User.h"
class Admin : public User
{
    public:
        // Constructor
        Admin(string userName, string password) : User(userName, password){}
        bool login(sqlite3* db);
        void addStudent(sqlite3* db, Student &S);
        void updateStudentData(sqlite3* db, int stud_id);
        void removeStudent(sqlite3* db, int stud_id);
        void addInstructor(sqlite3* db, Instructor &I);
        void updateInstructorData(sqlite3* db, int instructor_id);
        void removeInstructor(sqlite* db, int instructor_id);
        void viewStudentDegree(sqlite* db, int student_id);
        void viewAllGrades(sqlite* db);


};

#endif // ADMIN_H
