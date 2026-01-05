#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>
using namespace std;
class Question 
{
    private:
    int quesNo;
    string examId;
    string content;
    string optionOne;
    string optionTwo;
    string optionThree;
    string optionFour;
    string answer;
    public:
    
    void setQNo (int qNo);
    void setExamID(int _exam_id);
    void setContent(string _content);
    void setOption1(string _option1);
    void setOption2(string _option2);
    void setOption3(string _option3);
    void setOption4(string _option4);
    void setAnswer(string _answer);

    int getQNo();
    int getExamID();
    string getContent();
    string getOption1();
    string getOption2();
    string getOption3();
    string getOption4();
    string getAnswer();



};
#endif