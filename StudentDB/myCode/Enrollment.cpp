/**
 * @file Enrollment.cpp
 * @brief Source file for the Enrollment class, implementing the methods
 *        for student enrollment in a course.
 *
 * This file contains the implementation of the Enrollment class methods,
 * including constructors for enrolling a student in a course, getting and
 * setting enrollment details, and reading enrollment information from a file.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#include "Enrollment.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor to enroll a student in a course without a grade.
 *
 * This constructor initializes the enrollment with a semester and course
 * while setting the grade to 0.0f (default grade).
 *
 * @param semester The semester in which the student is enrolled.
 * @param course The course the student is enrolled in.
 */
Enrollment::Enrollment(std::string semester, const Course *course) :
    semester{semester}, course{course} {
    grade = 0.0f;
}

/**
 * @brief Constructor to enroll a student in a course with a grade.
 *
 * This constructor initializes the enrollment with a semester, grade, and
 * course details.
 *
 * @param semester The semester in which the student is enrolled.
 * @param grade The grade obtained by the student in the course.
 * @param course The course the student is enrolled in.
 */
Enrollment::Enrollment(std::string semester, float grade,
		const Course *course) :
    grade{grade}, semester{semester}, course{course} {
}

/**
 * @brief Gets the course associated with the enrollment.
 *
 * This method retrieves the course object associated with the student's
 * enrollment.
 *
 * @return A pointer to the associated Course object.
 */
const Course* Enrollment::getCourse() const {
    return course;
}

/**
 * @brief Gets the grade obtained by the student in the course.
 *
 * This method returns the grade for the student's enrollment in the course.
 *
 * @return The grade as a floating-point value.
 */
float Enrollment::getGrade() const {
    return grade;
}

/**
 * @brief Gets the semester of the enrollment.
 *
 * This method retrieves the semester in which the student is enrolled in
 * the course.
 *
 * @return The semester as a constant reference to a string.
 */
const std::string& Enrollment::getSemester() const {
    return semester;
}

/**
 * @brief Sets the grade for the enrollment.
 *
 * This method sets the grade for the student's enrollment in the course.
 *
 * @param grade The new grade to be assigned to the enrollment.
 */
void Enrollment::setGrade(float grade) {
    this->grade = grade;
}

/**
 * @brief Reads enrollment details from an input stream.
 *
 * This method allows reading of enrollment details from a stream (e.g., a
 * file). For now, it simply prints a message indicating that the user is
 * editing enrollment attributes.
 *
 * @param in The input stream to read the enrollment data from.
 */
void Enrollment::read(std::istream &in) {
    cout << "You are editing enrollment attributes now" << endl;
}
