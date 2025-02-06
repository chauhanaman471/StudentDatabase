/**
 * @file Student.cpp
 * @brief Implementation of the Student class for managing student information
 *        including constructors, getters, setters, and I/O operations.
 *
 * This file defines the methods for managing student data, including
 * initialization, accessors for student details (such as name, matriculation
 * number, and address), and methods for reading from and writing to files.
 * Additionally, it includes operator overloads for outputting student details.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#include "Student.h"
#include <iostream>
using namespace std;

// Static variable with storage space defined = 100000
unsigned int Student::nextMatrikelNumber = 100000;

// Default Constructor Implementation
/**
 * @brief Default constructor for the Student class.
 *
 * This constructor initializes the student object with default values
 * for name, date of birth, and address, and sets the matrikel number to 0.
 */
Student::Student() : firstName{""}, lastName{""}, dateofBirth{0, 0, 0},
        address{"", 0, "", ""} {
    matrikelNumber = 0;
}

/**
 * @brief Constructor that initializes a student with a given matrikel number.
 *
 * @param matrikelNumber The matrikel number to be assigned to the student.
 */
Student::Student(unsigned int matrikelNumber) : matrikelNumber{matrikelNumber}
{
    nextMatrikelNumber = matrikelNumber + 1;
}

// Constructor Implementation for full initialization
/**
 * @brief Constructor for initializing a student with given details.
 *
 * @param firstName First name of the student.
 * @param lastName Last name of the student.
 * @param dateofBirth Date of birth of the student.
 * @param address Address of the student.
 */
Student::Student(std::string firstName, std::string lastName,
        Poco::Data::Date dateofBirth, Address address) :
        firstName{firstName}, lastName{lastName},
        dateofBirth{dateofBirth}, address{address} {
    // Matrikel number is automatically assigned by the database
    matrikelNumber = nextMatrikelNumber++;
}

// Getter Implementations
/**
 * @brief Getter for the matrikel number of the student.
 *
 * @return The matrikel number of the student.
 */
unsigned int Student::getMatrikelNumber() const {
    return matrikelNumber;
}

/**
 * @brief Getter for the first name of the student.
 *
 * @return A constant reference to the first name of the student.
 */
const std::string& Student::getFirstName() const {
    return firstName;
}

/**
 * @brief Getter for the last name of the student.
 *
 * @return A constant reference to the last name of the student.
 */
const std::string& Student::getLastName() const {
    return lastName;
}

/**
 * @brief Getter for the address of the student.
 *
 * @return A reference to the address of the student.
 */
Address& Student::getAddress() {
    return address;
}

/**
 * @brief Getter for the list of enrollments of the student.
 *
 * @return A constant reference to the vector of enrollments.
 */
const std::vector<Enrollment>& Student::getEnrollments() const {
    return enrollments;
}

/**
 * @brief Getter for the next matrikel number to be assigned.
 *
 * @return The next matrikel number to be assigned.
 */
unsigned int Student::getNextMatrikelNumber() {
    return nextMatrikelNumber;
}

// Setter Implementations
/**
 * @brief Setter to update the address of the student.
 *
 * @param address The new address to be set for the student.
 */
void Student::setAddress(const Address& address) {
    this->address = address;
}

/**
 * @brief Setter to update the date of birth of the student.
 *
 * @param dateofBirth The new date of birth to be set for the student.
 */
void Student::setDateofBirth(const Poco::Data::Date& dateofBirth) {
    this->dateofBirth = dateofBirth;
}

/**
 * @brief Setter to update the first name of the student.
 *
 * @param firstName The new first name to be set for the student.
 */
void Student::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

/**
 * @brief Setter to update the last name of the student.
 *
 * @param lastName The new last name to be set for the student.
 */
void Student::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

/**
 * @brief Setter to update the enrollments of the student.
 *
 * @param enrollments The new list of enrollments to be set for the student.
 */
void Student::setEnrollments(const std::vector<Enrollment>& enrollments) {
    this->enrollments = enrollments;
}

/**
 * @brief Getter for the list of enrollments of the student (modifiable).
 *
 * @return A reference to the vector of enrollments.
 */
std::vector<Enrollment>& Student::getEnrollments() {
    return enrollments;
}

/**
 * @brief Setter to update the next matrikel number to be assigned.
 *
 * @param nextMatrikelNumber The new next matrikel number.
 */
void Student::setNextMatrikelNumber(unsigned int nextMatrikelNumber) {
    this->nextMatrikelNumber = nextMatrikelNumber;
}

// Operator Overload Implementation
/**
 * @brief Overloaded stream insertion operator to output student details.
 *
 * @param lhs The output stream.
 * @param myStudent The student whose details are to be printed.
 * @return The output stream with student details inserted.
 */
std::ostream& operator<<(std::ostream& lhs, const Student& myStudent) {
    lhs << "First Name: " << myStudent.firstName << endl;
    lhs << "Last Name: " << myStudent.lastName << endl;
    lhs << "Matrikel Number: " << myStudent.matrikelNumber << endl;
    lhs << "DOB: " << myStudent.dateofBirth.day() << ":" <<
    		myStudent.dateofBirth.month()
        << ":" << myStudent.dateofBirth.year() << endl;
    lhs << "Address: " << myStudent.address << endl;
    lhs << "Enrollments: " << endl;

    // Get the enrollment for the courses stored in the vector
    for (auto& enrollmentItr : myStudent.getEnrollments()) {
        // Each enrollment contains semester, grade, pointer to Course object
        const Course* coursePtr = enrollmentItr.getCourse();
        // Print the course (Block/Weekly Course details)
        coursePtr->print();
        // Get semester
        lhs << "Semester: " << enrollmentItr.getSemester() << endl;
        // Get grade
        lhs << "Student Grade: " << enrollmentItr.getGrade() << endl;
    }

    return lhs;
}

// File I/O Methods
/**
 * @brief Write the student data to an output stream.
 *
 * @param out The output stream where the student data will be written.
 */
void Student::write(std::ostream& out) {
    out << matrikelNumber << ";" << lastName << ";" << firstName << ";"
        << dateofBirth.day() << "." << dateofBirth.month() << "."
		<< dateofBirth.year()
        << ";" << address.getStreet() << ";" << address.getPostalCode()
        << ";" << address.getCityName() << ";" << address.getAdditionalInfo();
}

/**
 * @brief Read the student data from an input stream.
 *
 * @param in The input stream from which the student data will be read.
 */
void Student::read(std::istream& in) {
    getline(in, lastName, ';');    // Read the Last name
    getline(in, firstName, ';');   // Read the First name

    int dobDay, dobMonth, dobYear;
    in >> dobDay;
    in.ignore();    // Ignore '.'
    in >> dobMonth;
    in.ignore();    // Ignore '.'
    in >> dobYear;
    in.ignore();    // Ignore ';'

    dateofBirth = Poco::Data::Date(dobYear, dobMonth, dobDay); // Get the DOB

    address.read(in);  // Read the address details
}
