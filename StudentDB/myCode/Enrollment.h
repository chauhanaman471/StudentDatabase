/**
 * @file Enrollment.h
 * @brief Header file for the Enrollment class, representing a student's
 *        enrollment in a course.
 *
 * This file contains the declaration of the Enrollment class. It holds the
 * grade, semester, and associated course details for a student's enrollment.
 * It also provides methods to access and modify enrollment information,
 * such as reading from a file.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include <string>
#include "Course.h"

class Enrollment {
private:
    float grade;             /**< Grade obtained by the student in course */
    std::string semester;    /**< Semester in which the course was taken */
    const Course* course;    /**< Pointer to the associated Course object */

public:
    /**
     * @brief Constructor to initialize enrollment with semester and course.
     *
     * This constructor initializes an enrollment with the semester and course.
     * The grade is not yet assigned in this case.
     *
     * @param semester The semester in which the course is taken.
     * @param course The course the student is enrolled in.
     */
    Enrollment(std::string semester, const Course* course);

    /**
     * @brief Constructor to initialize enrollment with semester, grade, course.
     *
     * This constructor initializes an enrollment with the semester, grade,
     * and course details.
     *
     * @param semester The semester in which the course is taken.
     * @param grade The grade obtained by the student in the course.
     * @param course The course the student is enrolled in.
     */
    Enrollment(std::string semester, float grade, const Course* course);

    /**
     * @brief Retrieves the semester of the enrollment.
     *
     * This method returns the semester in which the student took the course.
     *
     * @return The semester as a constant reference to a string.
     */
    const std::string& getSemester() const;

    /**
     * @brief Retrieves the course associated with the enrollment.
     *
     * This method returns a pointer to the course in which the student is
     * enrolled.
     *
     * @return A pointer to the associated Course object.
     */
    const Course* getCourse() const;

    /**
     * @brief Retrieves the grade obtained by the student in the course.
     *
     * This method returns the grade for the student's enrollment in the course.
     *
     * @return The grade as a floating-point value.
     */
    float getGrade() const;

    /**
     * @brief Sets the grade for the enrollment.
     *
     * This method allows the grade for the enrollment to be modified.
     *
     * @param grade The new grade to be set for the enrollment.
     */
    void setGrade(float grade);

    /**
     * @brief Reads the enrollment details from an input stream.
     *
     * This method reads the semester, grade, and course information from the
     * input stream and updates the enrollment object accordingly.
     *
     * @param in The input stream to read the enrollment data from.
     */
    void read(std::istream &in);
};

#endif // ENROLLMENT_H_
