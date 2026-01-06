#include <iostream>
#include <string>
#include "sqlite3.h"
#include "DB_Manipulation.h"
#include "Admin.h"
#include "Instructor.h"
#include "Student.h"
#include "exam.h"
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void Welcome() {
    vector<string> msg_lines = {
        "####################################################",
        "##     Welcome to Our Exam Management System      ##",
        "##                                                ##",
        "##       This project Designed & Developed By:    ##",
        "##               -> Marwan Helmy                  ##",
        "##               -> Mahmoud Eissa                 ##",
        "##               -> Medhat Osama                  ##",
        "##               -> Roqaya Saad                   ##",
        "##                                                ##",
        "##       Supervised by: Eng Shimaa Hamdy          ##",
        "####################################################"
    };

    for (const string& line : msg_lines) {
        for (char c : line) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(15));
        }
        cout << endl;
    }

    cout << "\n      Starting System...";
    cin.get();
    system("cls");
}
using namespace std;

int main() {
Welcome();
    while  (true){
    sqlite3* db;
    int exit = sqlite3_open("exam.db", &db);

    if (exit != SQLITE_OK) {
        cerr << "Error opening DB: " << sqlite3_errmsg(db) << endl;
        return -1;
    }

    int role;
    string username, pass;


    cout << "1) Admin 2) Instructor 3) Student  4) Exit"<< endl;
    cout << "Select your role: ";
    cin >> role;
if (role == 4 ) break;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> pass;

    switch (role) {
    // ================= ADMIN SECTION =================
    case 1: {
        Admin admin(username, pass); // Admin needs constructor arguments
        if (admin.login(db, username, pass)) {
            cout << "\n[+] Login Success! Welcome Admin " << username << ".\n";
            int choice = 0;
            while (choice != 7) {
                cout << "\n Admin\n";
                cout << "1. Add Student\n";
                cout << "2. Remove Student\n";
                cout << "3. Add Instructor\n";
                cout << "4. Remove Instructor\n";
                cout << "5. View Student Degree\n";
                cout << "6. View All Grades\n";
                cout << "7. Logout\n";
                cout << "Choice: ";
                cin >> choice;

                if (choice == 1) {
                    string n, p;
                    cout << "Enter Student Name: "; cin >> n;
                    cout << "Enter Password: "; cin >> p;
                    Student s;
                    s.setUserName(n); s.setPassword(p);
                    admin.addStudent(db, s);
                }
                else if (choice == 2) {
                    int id; cout << "Enter Student ID to remove: "; cin >> id;
                    admin.removeStudent(db, id);
                }
                else if (choice == 3) {
                    string n, p;
                    cout << "Enter Instructor Name: "; cin >> n;
                    cout << "Enter Password: "; cin >> p;
                    Instructor i;
                    i.setUserName(n); i.setPassword(p);
                    admin.addInstructor(db, i);
                }
                else if (choice == 4) {
                    int id; cout << "Enter Instructor ID to remove: "; cin >> id;
                    admin.removeInstructor(db, id);
                }
                else if (choice == 5) {
                    int id; cout << "Enter Student ID: "; cin >> id;
                    admin.viewStudentDegree(db, id);
                }
                else if (choice == 6) {
                    admin.viewAllGrades(db);
                }
            }
        } else {
            cout << "\n[-] Invalid Admin credentials!\n";
        }
        break;
    }


    case 2: {
        Instructor instructor; // Default constructor
        if (instructor.login(db, username, pass)) {
            cout << "\n[+] Login Success! Welcome Dr. " << username << ".\n";
            int choice = 0;
            while (choice != 4) {
                cout << "\n--- Instructor Dashboard ---\n";
                cout << "1. Add New Exam\n";
                cout << "2. Add Question to Exam\n";
                cout << "3. View Exam Results\n";
                cout << "4. Logout\n";
                cout << "Choice: ";
                cin >> choice;

                if (choice == 1) {
                    string eName, eDate; int dur;
                    cout << "Exam Name: "; cin >> eName;
                    cout << "Date (YYYY-MM-DD): "; cin >> eDate;
                    cout << "Duration (mins): "; cin >> dur;
                    instructor.addExam(db, eName, eDate, dur);
                }
                else if (choice == 2) {
                    int eid; string content, o1, o2, o3, o4, ans;
                    cout << "Enter Exam ID: "; cin >> eid;
                    cout << "Question Content: "; cin.ignore(); getline(cin, content);
                    cout << "Option 1: "; getline(cin, o1);
                    cout << "Option 2: "; getline(cin, o2);
                    cout << "Option 3: "; getline(cin, o3);
                    cout << "Option 4: "; getline(cin, o4);
                    cout << "Correct Answer (text): "; getline(cin, ans);
                    instructor.addQuestion(db, eid, content, o1, o2, o3, o4, ans);
                }
                else if (choice == 3) {
                    int eid; cout << "Enter Exam ID: "; cin >> eid;
                    instructor.viewAllResults(db, eid);
                }
            }
        } else {
            cout << "\n[-] Invalid Instructor credentials!\n";
        }
        break;
    }


    case 3: {
        Student student; // Default constructor
        if (student.login(db, username, pass)) {
            cout << "\n[+] Login Success! Welcome " << username << ".\n";
            int choice = 0;
            while (choice != 4) {
                cout << "\n--- Student Dashboard ---\n";
                cout << "1. Show Available Exams\n";
                cout << "2. Take Exam\n";
                cout << "3. View My Grades\n";
                cout << "4. Logout\n";
                cout << "Choice: ";
                cin >> choice;

                if (choice == 1) {
                    student.showAvailableExams(db);
                }
                else if (choice == 2) {
                    int eid;
                    cout << "Enter Exam ID to start: "; cin >> eid;
                    student.takeExam(db, eid);
                }
                else if (choice == 3) {
                    student.viewMyGrades(db);
                }
            }
        } else {
            cout << "\n[-] Invalid Student credentials!\n";
        }
        break;
    }
    default:
        cout << "Invalid Role Selection!\n";
    }

    sqlite3_close(db);

}
    cout << "\nSystem Exited.\n";
    return 0;
}
