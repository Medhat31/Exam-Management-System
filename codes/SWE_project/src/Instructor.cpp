#include "Instructor.h"

 bool Instructor::login(sqlite3* db, const string& username, const string& password)
    {
        string sql =
            "SELECT instructor_id FROM Instructors "
            "WHERE name = ? AND password = ?;";

        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            setID(sqlite3_column_int(stmt, 0));
            setUserName(username);
            setPassword(password);

            sqlite3_finalize(stmt);
            return true;
        }

        sqlite3_finalize(stmt);
        return false;
    }


    void Instructor::addExam(sqlite3* db, const string& examName, const string& examDate, int duration)
    {
        string sql =
            "INSERT INTO Exams (exam_name, exam_date, duration, instructor_id) "
            "VALUES (?, ?, ?, ?);";

        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

        sqlite3_bind_text(stmt, 1, examName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, examDate.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, duration);
        sqlite3_bind_int(stmt, 4, getID());

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        cout << "Exam added successfully.\n";
    }

     void Instructor::addQuestion(sqlite3* db, int exam_id, const string& content, const string& o1, const string& o2,
                      const string& o3, const string& o4, const string& correct)
    {
        string sql =
            "INSERT INTO Questions "
            "(exam_id, content, option1, option2, option3, option4, answer) "
            "VALUES (?, ?, ?, ?, ?, ?, ?);";

        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, exam_id);
        sqlite3_bind_text(stmt, 2, content.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, o1.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, o2.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, o3.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 6, o4.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 7, correct.c_str(), -1, SQLITE_STATIC);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        cout << "Question added successfully.\n";
    }

      void Instructor::viewStudentResult(sqlite3* db, int student_id, int exam_id)
    {
        string sql =
            "SELECT student_degree FROM Students_Exams "
            "WHERE student_id = ? AND exam_id = ?;";

        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, student_id);
        sqlite3_bind_int(stmt, 2, exam_id);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            cout << "Student Degree: "
                 << sqlite3_column_double(stmt, 0) << "%\n";
        }
        else
        {
            cout << "No result found.\n";
        }

        sqlite3_finalize(stmt);
    }

     void Instructor::viewAllResults(sqlite3* db, int exam_id)
    {
        string sql =
            "SELECT Students.name, student_degree "
            "FROM Students_Exams "
            "JOIN Students ON Students.student_id = Students_Exams.student_id "
            "WHERE exam_id = ?;";

        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, exam_id);

        cout << "\nExam Results:\n";
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            cout << sqlite3_column_text(stmt, 0)
                 << " : " << sqlite3_column_double(stmt, 1) << "%\n";
        }

        sqlite3_finalize(stmt);
    }
