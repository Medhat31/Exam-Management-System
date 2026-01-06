#include "exam.h"

// Setters
void Exam::setExamID(int _examId)
{
    examId = _examId;
}

void Exam::setExamDate(string _examDate) {
    examDate = _examDate;
}

void Exam::setduration(float _duration) {
    duration = _duration;
}



void Exam::seInstructorID(int _instructorId) {
    instructorId = _instructorId;
}

// Getters
int Exam::getExamID() {
    return examId;
}

string Exam::getExamDate() {
    return examDate;
}

float Exam::getDuration() {
    return duration;
}



int Exam::getInstructorID() {
    return instructorId;
}

// Question management methods
void Exam::createQuestion(sqlite3* db, Question q)
{
    char* errorMessage;

    stringstream ss;
    ss << this->examId;
    string strExamID = ss.str();


    string sql = "INSERT INTO Questions (exam_id, content, answer, option1, option2, option3, option4) VALUES (" +
                 strExamID + ", '" +
                 q.getContent() + "', '" +
                 q.getAnswer() + "', '" +
                 q.getOption1() + "', '" +
                 q.getOption2() + "', '" +
                 q.getOption3() + "', '" +
                 q.getOption4() + "');";

    int rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage);

    if (rc != SQLITE_OK) {
        cout << "SQL Error in createQuestion: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Question added successfully!" << endl;
    }
}
void Exam::updateQuestion(sqlite3* db, Question q)
{
    char* errorMessage;


    stringstream ss;
    ss << q.getQNo();
    string strQNo = ss.str();


    string sql = "UPDATE Questions SET "
                 "content = '" + q.getContent() + "', "
                 "option1 = '" + q.getOption1() + "', "
                 "option2 = '" + q.getOption2() + "', "
                 "option3 = '" + q.getOption3() + "', "
                 "option4 = '" + q.getOption4() + "', "
                 "answer = '" + q.getAnswer() + "' "
                 "WHERE q_no = " + strQNo + ";";

    int rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage);

    if (rc != SQLITE_OK) {
        cout << "SQL Error in updateQuestion: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Question " << q.getQNo() << " updated successfully!" << endl;
    }
}

void Exam::deleteQuestion(sqlite3* db, int questionId)
{
    char* errorMessage;

    stringstream ss;
    ss << questionId;
    string strID = ss.str();

    string sql = "DELETE FROM Questions WHERE q_no = " + strID + ";";

    int rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage);

    if (rc != SQLITE_OK) {
        cout << "SQL Error in deleteQuestion: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Question " << questionId << " deleted successfully!" << endl;
    }
}
