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

void Exam::setCourseID(int _courseId) {
    // Note: There's no course_id member variable in the header
    // You may need to add it to the private section
    // For now, this is a placeholder implementation
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

int Exam::getCourseID() {
    // Note: There's no course_id member variable in the header
    // You may need to add it to the private section
    // For now, returning 0 as placeholder
    return 0;
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
    string sql = "INSERT INTO Questions (question_text, correct_answer, exam_id) VALUES ('" + 
                 q.getQuestionText() + "', '" + 
                 q.getCorrectAnswer() + "', " + 
                 to_string(this->exam_id) + ");";

    int rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage);

    if (rc != SQLITE_OK) {
        cout << "SQL Error in createQuestion: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Question added successfully!" << endl;
    }
}

void Exam::updateQuestion(sqlite3* db,Question q)
{
    // Implementation for updating a question
    // You would typically search for the question by its ID and update it
    // Example: Find question with matching q_no and update its fields
}

void Exam::deleteQuetion(sqlite3* db,int questionId) 
{
    // Implementation for deleting a question
    // You would typically search for the question by its ID and remove it
    // Example: Find question with matching q_no and remove from container
}