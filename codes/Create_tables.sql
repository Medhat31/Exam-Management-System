PRAGMA foreign_keys = ON;
CREATE TABLE Admins (
    admin_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    password TEXT NOT NULL
);
CREATE TABLE Instructors (
    instructor_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    password TEXT NOT NULL
);
CREATE TABLE Students (
    student_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    password TEXT NOT NULL
);
CREATE TABLE Exams (
    exam_id INTEGER PRIMARY KEY AUTOINCREMENT,
    exam_name TEXT NOT NULL,
    exam_date TEXT,
    duration INTEGER,
    instructor_id INTEGER,
    FOREIGN KEY (instructor_id) REFERENCES Instructors(instructor_id)
);
CREATE TABLE Questions (
    q_no INTEGER PRIMARY KEY AUTOINCREMENT,
    exam_id INTEGER,
    content TEXT NOT NULL,
    option1 TEXT,
    option2 TEXT,
    option3 TEXT,
    option4 TEXT,
    answer TEXT, 
    FOREIGN KEY (exam_id) REFERENCES Exams(exam_id)
);
CREATE TABLE Students_Exams (
    student_id INTEGER,
    exam_id INTEGER,
    student_degree DOUBLE,
    PRIMARY KEY (student_id, exam_id),
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (exam_id) REFERENCES Exams(exam_id)
);
INSERT INTO Admins (name, password) VALUES
('Marwan', 'MMMR'),
('Medhat', 'MMMR'),
('Eissa', 'MMMR'),
('Roqaya', 'MMMR');