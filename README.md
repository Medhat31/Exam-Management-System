# Exam Management System (C++ Console App) 

A comprehensive console-based Exam Management System developed using **C++** and **SQLite**. The system applies Object-Oriented Programming (OOP) principles to manage the educational process, allowing Admins, Instructors, and Students to interact dynamically.

## Features

### 1. Admin Role
- **User Management:** Add and remove Students and Instructors.
- **Global Reporting:** View grades for any student across all courses.
- **Full Access:** Inherits all Instructor privileges.

### 2. Instructor Role
- **Exam Creation:** Create new exams with custom duration and dates.
- **Question Management:** Add multiple-choice questions (MCQ) to exams.
- **Grading:** View results of students in specific exams.

### 3. Student Role
- **Exam Taking:** Browse available exams and take them interactively.
- **Auto-Grading:** Get immediate feedback and scores upon completion.
- **Gradebook:** View personal history and grades.

---

## Technical Stack
- **Language:** C++ (Standard 11/14/17).
- **Database:** SQLite3 (Integrated).
- **Concepts:**
  - OOP (Inheritance, Polymorphism, Encapsulation).
  - File/Database Handling.
  - Data Structures (Vectors).
- **UI:** Console-based with Typewriter effects for a better user experience.

---

## Project Structure# Exam-Management-System
A console-based Exam Management System implemented in C++ using OOP principles. The project follows an Agile-oriented SWE process, includes SMART requirements, UML diagrams (class, use case, activity, sequence), and demonstrates structured design, actor interactions, and modular system architecture.
├── include/ # Header files (.h) │ ├── Admin.h │ ├── Instructor.h │ ├── Student.h │ ├── User.h │ ├── exam.h │ └── DB_Manipulation.h ├── src/ # Source files (.cpp) │ ├── Admin.cpp │ └── ... ├── main.cpp # Entry point ├── sqlite3.h # SQLite header ├── sqlite3.c # SQLite source └── README.md # Documentation
## How to Run
1. **Clone the repository:**
   ```bash
   git clone https://github.com/Medhat31/Exam-Management-System.git
   Open the project in your IDE (e.g., Code::Blocks, VS Code).

Link SQLite: Ensure sqlite3.c is included in the build target or linked properly.

Build and Run: Compile main.cpp.

Team Members
This project was designed and developed by:

Marwan Helmy

Mahmoud Eissa

Medhat Osama

Roqaya Saad  

 Supervised by: Eng Shimaa Hamdy

Database Schema (ERD)
The system relies on 4 main entities:

Users: (ID, Username, Password, Role)

Exams: (ExamID, InstructorID, Subject, Duration)

Questions: (QuestionID, ExamID, Content, Options, CorrectAnswer)

Results: (StudentID, ExamID, Score)
