#include "Student.h"

 bool Student::login(sqlite3* db, const string& username, const string& password)
    {
        string sql =
            "SELECT student_id FROM Students "
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

    // ================================================================

    void Student::showAvailableExams(sqlite3* db)
    {
        string sql = "SELECT exam_id, exam_name FROM Exams;";
        sqlite3_stmt* stmt;

        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

        cout << "\nAvailable Exams:\n";
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            cout << "Exam ID: " << sqlite3_column_int(stmt, 0)
                 << " | Name: " << sqlite3_column_text(stmt, 1) << endl;
        }

        sqlite3_finalize(stmt);
    }

    // ================================================================

        void Student::takeExam(sqlite3* db, int exam_id)
    {
        string sql =
            "SELECT content, option1, option2, option3, option4, answer "
            "FROM Questions WHERE exam_id = ?;";

        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, exam_id);

        int total = 0, correct = 0;

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            total++;
            cout << "\nQ" << total << ": "
                 << sqlite3_column_text(stmt, 0) << endl;

            cout << "A) " << sqlite3_column_text(stmt, 1) << endl;
            cout << "B) " << sqlite3_column_text(stmt, 2) << endl;
            cout << "C) " << sqlite3_column_text(stmt, 3) << endl;
            cout << "D) " << sqlite3_column_text(stmt, 4) << endl;

            char ans;
            cout << "Your answer: ";
            cin >> ans;

            string correctAns =
                (const char*)sqlite3_column_text(stmt, 5);

            if (toupper(ans) == toupper(correctAns[0]))
                correct++;
        }

        sqlite3_finalize(stmt);

        double score = (double)correct / total * 100;

        string insert =
            "INSERT INTO Students_Exams (student_id, exam_id, student_degree) "
            "VALUES (?, ?, ?);";

        sqlite3_prepare_v2(db, insert.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, getID());
        sqlite3_bind_int(stmt, 2, exam_id);
        sqlite3_bind_double(stmt, 3, score);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        cout << "\nYour Score: " << score << "%\n";
    }
    // ================================================================
        void Student::viewMyGrades(sqlite3* db)
    {
        string sql =
            "SELECT Exams.exam_name, student_degree "
            "FROM Students_Exams "
            "JOIN Exams ON Exams.exam_id = Students_Exams.exam_id "
            "WHERE student_id = ?;";

        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, getID());

        cout << "\nMy Grades:\n";
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            cout << sqlite3_column_text(stmt, 0)
                 << " : " << sqlite3_column_double(stmt, 1) << "%\n";
        }

        sqlite3_finalize(stmt);
    }
