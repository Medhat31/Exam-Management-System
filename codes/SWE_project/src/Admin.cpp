#include "Admin.h"
#include <iostream>


bool Admin::login(sqlite3* db, const string& username, const string& password)
{

    string sql = "SELECT admin_id FROM Admins WHERE name = ? AND password = ?;";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cout << "Error preparing Admin login: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {

        setID(sqlite3_column_int(stmt, 0));
        setUserName(username);
        setPassword(password);

        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}



void Admin::addStudent(sqlite3* db, Student &S)
{
    string sql = "INSERT INTO Students (name, password) VALUES (?, ?);";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);


    sqlite3_bind_text(stmt, 1, S.getUserName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, S.getPassword().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Student added successfully!\n";
    } else {
        cout << "Error adding student: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}

void Admin::removeStudent(sqlite3* db, int stud_id)
{
    string sql = "DELETE FROM Students WHERE student_id = ?;";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, stud_id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Student removed successfully!\n";
    } else {
        cout << "Error removing student.\n";
    }
    sqlite3_finalize(stmt);
}

void Admin::updateStudentData(sqlite3* db, int stud_id)
{

    string newName, newPass;
    cout << "Enter new Name: ";
    cin >> newName;
    cout << "Enter new Password: ";
    cin >> newPass;

    string sql = "UPDATE Students SET name = ?, password = ? WHERE student_id = ?;";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, newName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newPass.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, stud_id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Student data updated successfully!\n";
    }
    sqlite3_finalize(stmt);
}



void Admin::addInstructor(sqlite3* db, Instructor &I)
{
    string sql = "INSERT INTO Instructors (name, password) VALUES (?, ?);";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, I.getUserName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, I.getPassword().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Instructor added successfully!\n";
    }
    sqlite3_finalize(stmt);
}

void Admin::removeInstructor(sqlite3* db, int instructor_id)
{
    string sql = "DELETE FROM Instructors WHERE instructor_id = ?;";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, instructor_id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Instructor removed successfully!\n";
    }
    sqlite3_finalize(stmt);
}

void Admin::updateInstructorData(sqlite3* db, int instructor_id)
{
    string newName, newPass;
    cout << "Enter new Name: ";
    cin >> newName;
    cout << "Enter new Password: ";
    cin >> newPass;

    string sql = "UPDATE Instructors SET name = ?, password = ? WHERE instructor_id = ?;";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, newName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newPass.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, instructor_id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Instructor data updated successfully!\n";
    }
    sqlite3_finalize(stmt);
}


void Admin::viewStudentDegree(sqlite3* db, int student_id)
{

    string sql = "SELECT Exams.exam_name, student_degree "
                 "FROM Students_Exams "
                 "JOIN Exams ON Exams.exam_id = Students_Exams.exam_id "
                 "WHERE student_id = ?;";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, student_id);

    cout << "\n--- Student Grades ---\n";
    bool found = false;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        found = true;
        cout << "Exam: " << sqlite3_column_text(stmt, 0)
             << " | Grade: " << sqlite3_column_double(stmt, 1) << "%\n";
    }
    if (!found) cout << "No grades found for this student.\n";

    sqlite3_finalize(stmt);
}

void Admin::viewAllGrades(sqlite3* db)
{

    string sql = "SELECT Students.name, Exams.exam_name, student_degree "
                 "FROM Students_Exams "
                 "JOIN Students ON Students.student_id = Students_Exams.student_id "
                 "JOIN Exams ON Exams.exam_id = Students_Exams.exam_id;";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    cout << "\n--- All System Grades ---\n";
    cout << "Student \t Exam \t\t Grade\n";
    cout << "--------------------------------------\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        cout << sqlite3_column_text(stmt, 0) << " \t "
             << sqlite3_column_text(stmt, 1) << " \t "
             << sqlite3_column_double(stmt, 2) << "%\n";
    }

    sqlite3_finalize(stmt);
}
