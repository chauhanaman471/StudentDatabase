/**
 * @file StudentDb.h
 * @brief Stores student and course information in a database-like structure.
 * @author Aman Chauhan
 * @date 17 January 2025
 * @version 1.0
 * @note Master Student at HDA
 * @matriculationNumber 1127928
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include <map>
#include <memory>
#include <string>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include "Student.h"
#include "Course.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"

/**
 * @class StudentDb
 * @brief Manages the storage and operations for students and courses.
 *
 * This class provides methods to add, list, update, and search for students
 * and courses. It also supports enrolling students in courses and saving or
 * loading the database to and from streams.
 */
class StudentDb {
private:
    /**< Stores students indexed by matriculation number */
    std::map<int, Student> students;
    /**< Stores courses indexed by course key */
    std::map<int, std::unique_ptr<const Course>> courses;

public:
    /**
     * @brief Default constructor for the StudentDb class.
     *
     * Initializes the student and course databases as empty.
     */
    StudentDb();

    /**
     * @brief Destructor for the StudentDb class.
     *
     * Cleans up resources used by the student and course databases.
     */
    ~StudentDb();

    /**
     * @brief Adds a new course to the database.
     *
     * This method adds a new course entry to the database with the provided
     * course details.
     *
     * @param courseKey Unique identifier for the course.
     * @param title Title of the course.
     * @param major Major category for the course.
     * @param creditPoints Credit points associated with the course.
     */
    void addCourse(unsigned int courseKey, std::string title,
                   unsigned char major, float creditPoints);

    /**
     * @brief Lists all available courses in the database.
     *
     * This method prints out all courses that are currently stored in the
     * database.
     */
    void listCourse();

    /**
     * @brief Adds a new student to the database.
     *
     * This method creates a new student and adds it to the database with the
     * provided personal details.
     *
     * @param firstName First name of the student.
     * @param lastName Last name of the student.
     * @param dob Date of birth of the student.
     * @param street Street address of the student.
     * @param postalCode Postal code of the student's address.
     * @param cityName City name of the student's address.
     * @param additionalInfo Additional information about the student.
     */
    void addNewStudent(std::string firstName, std::string lastName,
                       Poco::Data::Date dob, std::string street,
                       unsigned short postalCode, std::string cityName,
                       std::string additionalInfo);

    /**
     * @brief Enrolls a student in a course.
     *
     * This method associates a student with a course for a specific semester.
     *
     * @param matrikelNumber Matriculation number of the student.
     * @param courseKey Key of the course to enroll in.
     * @param semester Semester in which the student is enrolling.
     */
    void addEnrollment(int matrikelNumber, int courseKey,
    		std::string semester);

    /**
     * @brief Prints information of a student by matriculation number.
     *
     * This method outputs the student's details including name, date of birth,
     * address, and enrollments.
     *
     * @param matrikelNumber Matriculation number of the student.
     */
    void printStudent(int matrikelNumber);

    /**
     * @brief Searches for students by substring in their names.
     *
     * This method searches the database for students whose first or last name
     * contains the specified substring.
     *
     * @param subString Substring to search for in student names.
     */
    void searchStudent(std::string subString);

    /**
     * @brief Updates student information by matriculation number.
     *
     * This method allows the modification of student details based on their
     * matriculation number.
     *
     * @param matrikelNumber Matriculation number of the student to update.
     */
    void updateStudent(int matrikelNumber);

    /**
     * @brief Writes the current database to an output stream.
     *
     * This method outputs the current state of the student and course database
     * to the specified stream.
     *
     * @param out Output stream to write to.
     */
    void write(std::ostream& out);

    /**
     * @brief Reads data from an input stream and updates the database.
     *
     * This method clears the current database and loads new student and course
     * information from the provided input stream.
     *
     * @param in Input stream to read from.
     */
    void read(std::istream& in);
};

#endif /* STUDENTDB_H_ */
