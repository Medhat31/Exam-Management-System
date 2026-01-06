
#include "ques.h"

// Setters
void Question::setQNo(int qNo) {
    quesNo = qNo;
}

void Question::setExamID(int _examId) {
    examId = to_string(_examId);
}

void Question::setContent(string _content) {
    content = _content;
}

void Question::setOption1(string _option1) {
    optionOne = _option1;
}

void Question::setOption2(string _option2) {
    optionTwo = _option2;
}

void Question::setOption3(string _option3) {
    optionThree = _option3;
}

void Question::setOption4(string _option4) {
    optionFour = _option4;
}

void Question::setAnswer(string _answer) {
    answer = _answer;
}

// Getters
int Question::getQNo() {
    return quesNo;
}

int Question::getExamID() {
    return stoi(examId);
}

string Question::getContent() {
    return content;
}

string Question::getOption1() {
    return optionOne;
}

string Question::getOption2() {
    return optionTwo;
}

string Question::getOption3() {
    return optionThree;
}

string Question::getOption4() {
    return optionFour;
}

string Question::getAnswer() {
    return answer;
}