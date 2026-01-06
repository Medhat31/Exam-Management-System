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
void Exam::createQuestion(sqlite3* db,Question q)
{
    char* errorMessage;
    
    // Construct SQL: INSERT INTO Questions (question_text, correct_answer, exam_id) ...
    // Note: Ensure your Question class has getQuestionText() and getCorrectAnswer()
    string sql = "INSERT INTO Questions (exam_id,content,answer,option1,option2,option3,option4) VALUES ('" + 
                 q.getQuestionText() + "', '" + 
                 q.getCorrectAnswer() + "', " + 
                 to_string(this->examId) + ");";

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

    // We use UPDATE to change existing data. 
    // We identify the specific question using the 'q_no' column.
    string sql = "UPDATE Questions SET "
                 "content = '" + q.getContent() + "', "
                 "option1 = '" + q.getOption1() + "', "
                 "option2 = '" + q.getOption2() + "', "
                 "option3 = '" + q.getOption3() + "', "
                 "option4 = '" + q.getOption4() + "', "
                 "answer = '" + q.getAnswer() + "' "
                 "WHERE q_no = " + to_string(q.getQNo()) + ";";

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

    // DELETE removes the entire row where the q_no matches the questionId provided.
    string sql = "DELETE FROM Questions WHERE q_no = " + to_string(questionId) + ";";

    int rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage);

    if (rc != SQLITE_OK) {
        cout << "SQL Error in deleteQuestion: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Question " << questionId << " deleted successfully!" << endl;
    }
}