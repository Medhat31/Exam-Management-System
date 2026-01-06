#ifndef EXAM_H
#define EXAM_H
#include <string>
#include <iostream>
#include "DB_Manipulation.h"
#include "ques.h"
#include <sstream>
using namespace std;

class Exam {
private:
    int examId;
    string examName;
    string examDate;
    float duration;
    int instructorId;

public:
    // Setters
    void setExamID(int _examId);
    void setExamDate(string _examDate);
    void setduration(float _duration);
    void setCourseID(int _courseId);
    void seInstructorID(int _instructorId);

    // Getters
    int getExamID();
    string getExamDate();
    float getDuration();
    int getInstructorID();

    // Question management methods
    void createQuestion(sqlite3* db,Question q);
    void updateQuestion(sqlite3* db,Question q);
    void deleteQuestion(sqlite3* db,int questionId);
};

#endif
