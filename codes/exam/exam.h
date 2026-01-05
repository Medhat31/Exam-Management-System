#ifndef EXAM_H
#define EXAM_H

#include <string>
#include "question/ques.h"
using namespace std;

class Exam {
private:
    int exam_id;
    string exam_name;
    string exam_date;
    float duration;
    int instructor_id;

public:
    // Setters
    void setExamID(int _exam_id);
    void setExamDate(string _exam_date);
    void setduration(float _duration);
    void setCourseID(int _course_id);
    void seInstructorID(int _instructor_id);
    
    // Getters
    int getExamID();
    string getExamDate();
    float getDuration();
    int getCourseID();
    int getInstructorID();
    
    // Question management methods
    void createQuestion(Question q);
    void updateQuestion(Question q);
    void deleteQuetion(Question q);
};

#endif