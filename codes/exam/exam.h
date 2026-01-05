#ifndef EXAM_H
#define EXAM_H

#include <string>
#include <sqlite3.h>
#include <iostream>

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
    int getCourseID();
    int getInstructorID();
    
    // Question management methods
    void createQuestion(sqlite3* db,Question q);
    void updateQuestion(sqlite3* db,Question q);
    void deleteQuetion(sqlite3* db,int questionId);
};

#endif