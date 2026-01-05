#include "exam.h"

// Setters
void Exam::setExamID(int _exam_id)
{
    exam_id = _exam_id;
}

void Exam::setExamDate(string _exam_date) {
    exam_date = _exam_date;
}

void Exam::setduration(float _duration) {
    duration = _duration;
}

void Exam::setCourseID(int _course_id) {
    // Note: There's no course_id member variable in the header
    // You may need to add it to the private section
    // For now, this is a placeholder implementation
}

void Exam::seInstructorID(int _instructor_id) {
    instructor_id = _instructor_id;
}

// Getters
int Exam::getExamID() {
    return exam_id;
}

string Exam::getExamDate() {
    return exam_date;
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
    return instructor_id;
}

// Question management methods
void Exam::createQuestion(Question q) {
    // Implementation for creating a question
    // You might want to store questions in a container (vector, array, etc.)
    // Example: questions.push_back(q);
}

void Exam::updateQuestion(Question q) {
    // Implementation for updating a question
    // You would typically search for the question by its ID and update it
    // Example: Find question with matching q_no and update its fields
}

void Exam::deleteQuetion(Question q) {
    // Implementation for deleting a question
    // You would typically search for the question by its ID and remove it
    // Example: Find question with matching q_no and remove from container
}