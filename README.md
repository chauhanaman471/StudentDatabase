# Student Database Project

## Overview
The Student Database (StudentDB) project is a simple student management system designed to store and manipulate student records, course information, and enrollments.

## Features
### 1. Course Management
- Add new courses.
- List all available courses.

### 2. Student Management
- Add new students with automatically generated matriculation numbers.
- Search students by first or last name.
- View detailed student information including enrolled courses and results.
- Update student information, including enrollments and grades.

### 3. Enrollment Management
- Enroll students in courses.
- Prevent duplicate enrollments.
- Update or remove enrollments.

### 4. Data Persistence
- Save student, course, and enrollment data to a file in a CSV-like format.
- Load data from a saved file.

### 5. Test Data Generation
- Fetch test student data from an external server using network communication.
- Parse JSON responses and create student records.

## Usage
During running the program, a menu-driven user interface will be displayed with the following options:
1. Add a new course
2. List all courses
3. Add a new student
4. Enroll a student in a course
5. Print student details
6. Search for a student
7. Update student information
8. Save database to file
9. Load database from file
10. Fetch test data from an external server
0. Exit

Follow the on-screen instructions to interact with the database.

## Code Structure
- `StudentDb.cpp/.h`: Handles student and course data storage.
- `Course.cpp/.h`: Defines course properties and methods.
- `Student.cpp/.h`: Defines student properties and methods.
- `SimpleUI.cpp/.h`: Implements the command-line interface for user interaction.
- `Enrollment.cpp/.h`: Manages course enrollments.

