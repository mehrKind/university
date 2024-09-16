# University System App

This app is written by Alireza Mehraban and is designed for a university system. The app is entirely written in C++ and uses text files for its database.

## Student ID Ranges
- **Entry Year 400**: Student IDs are between 2 and 50.
- **Entry Year 401**: Student IDs are between 51 and 100.
- **Entry Year 99**: Student IDs are between 101 and 150.

## Program Overview

### Main Features
1. **Student Registration**: 
   - The registration process starts by entering the number `1`.
   
2. **User Panels**:
   - **Teacher's Panel**: 
     - Accessed by entering the ID `500`.
   - **Student Panel**: 
     - Accessed by entering a valid student ID.

### Student Identification
Upon entering a student number, the program will determine the entry year of the student.

## Master Panel (Teacher)
The teacher can perform the following actions:
- Define lessons for all three years.
- Add or remove students.
- View messages sent by students.
- Enter grades for courses chosen by students.

## Student Panel
The student panel includes the following features:
- Send messages to the teacher.
- View lessons defined by the teacher.
- Choose from the defined lessons.
- View grades assigned by the teacher for each lesson.

### Grade Format
The grade entered by the teacher is displayed before and after the name of the courses, respectively. The first grade corresponds to the first lesson, and the rest follow in order.

---

This app aims to streamline the university management process for both students and teachers.
