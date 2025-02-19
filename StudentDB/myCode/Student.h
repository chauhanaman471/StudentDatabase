/**
 * @file Student.h
 * @brief Header file defining the Student class for managing student
 *        information, including personal details, enrollments, and address.
 *
 * This file declares the Student class, which is responsible for handling
 * student data such as matrikel number, first name, last name, date of birth,
 * enrollments, and address. The class also provides methods for accessing
 * and modifying this data.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <vector>
#include <Poco/Data/Date.h>
#include "Enrollment.h"
#include "Address.h"

/**
 * @class Student
 * @brief Class representing a student with personal details, enrollments,
 *        and address.
 *
 * This class manages student information, including matrikel number, first
 * and last names, date of birth, enrollments, and address. It provides
 * methods to access and modify the data and is also responsible for
 * serializing and deserializing the data to and from a file.
 */
class Student {
private:
	/// Static variable to track the next matrikel number.
	static unsigned int nextMatrikelNumber;

	/// Matrikel number of the student.
	unsigned int matrikelNumber;

	/// First name of the student.
	std::string firstName;

	/// Last name of the student.
	std::string lastName;

	/// Date of birth of the student.
	Poco::Data::Date dateofBirth;

	/// List of enrollments for the student.
	std::vector<Enrollment> enrollments;

	/// Address of the student.
	Address address;

public:
	/**
	 * @brief Default constructor for the Student class.
	 *
	 * This constructor initializes a student object with default values.
	 */
	Student();

	/**
	 * @brief Constructor for initializing a student with given details.
	 *
	 * @param firstName First name of the student.
	 * @param lastName Last name of the student.
	 * @param dateofBirth Date of birth of the student.
	 * @param address Address of the student.
	 */
	Student(std::string firstName, std::string lastName,
			Poco::Data::Date dateofBirth, Address address);

	/**
	 * @brief Constructor that initializes a student with a matrikel number.
	 *
	 * @param matrikelNumber Matrikel number of the student.
	 */
	Student(unsigned int matrikelNumber);

	/**
	 * @brief Getter for the matrikel number of the student.
	 *
	 * @return The matrikel number of the student.
	 */
	unsigned int getMatrikelNumber() const;

	/**
	 * @brief Getter for the first name of the student.
	 *
	 * @return The first name of the student.
	 */
	const std::string& getFirstName() const;

	/**
	 * @brief Getter for the last name of the student.
	 *
	 * @return The last name of the student.
	 */
	const std::string& getLastName() const;

	/**
	 * @brief Getter for the next matrikel number to be assigned.
	 *
	 * @return The next matrikel number to be assigned.
	 */
	unsigned int getNextMatrikelNumber();

	/**
	 * @brief Getter for the list of enrollments of the student.
	 *
	 * @return A constant reference to the vector of enrollments.
	 */
	const std::vector<Enrollment>& getEnrollments() const;

	/**
	 * @brief Getter for the list of enrollments of the student (modifiable).
	 *
	 * @return A reference to the vector of enrollments.
	 */
	std::vector<Enrollment>& getEnrollments();

	/**
	 * @brief Getter for the address of the student.
	 *
	 * @return A reference to the address of the student.
	 */
	Address& getAddress();

	/**
	 * @brief Setter to update the address of the student.
	 *
	 * @param address The new address to be set for the student.
	 */
	void setAddress(const Address& address);

	/**
	 * @brief Setter to update the date of birth of the student.
	 *
	 * @param dateofBirth The new date of birth of the student.
	 */
	void setDateofBirth(const Poco::Data::Date& dateofBirth);

	/**
	 * @brief Setter to update the first name of the student.
	 *
	 * @param firstName The new first name of the student.
	 */
	void setFirstName(const std::string& firstName);

	/**
	 * @brief Setter to update the last name of the student.
	 *
	 * @param lastName The new last name of the student.
	 */
	void setLastName(const std::string& lastName);

	/**
	 * @brief Setter to update the enrollments of the student.
	 *
	 * @param enrollments The new list of enrollments for the student.
	 */
	void setEnrollments(const std::vector<Enrollment>& enrollments);

	/**
	 * @brief Setter to update the next matrikel number to be assigned.
	 *
	 * @param nextMatrikelNumber The new next matrikel number.
	 */
	void setNextMatrikelNumber(unsigned int nextMatrikelNumber);

	/**
	 * @brief Overloaded stream insertion operator to output student details.
	 *
	 * @param lhs The output stream.
	 * @param myStudent The student whose details are to be printed.
	 * @return The output stream with student details inserted.
	 */
	friend std::ostream& operator<<(std::ostream& lhs,
			const Student& myStudent);

	/**
	 * @brief Write the student data to an output stream.
	 *
	 * @param out The output stream where the data will be written.
	 */
	void write(std::ostream& out);

	/**
	 * @brief Read the student data from an input stream.
	 *
	 * @param in The input stream from which the data will be read.
	 */
	void read(std::istream& in);
};

// Overloading << operator for object belonging to student class
/**
 * @brief Overloaded stream insertion operator for student object.
 *
 * @param lhs The output stream to which the student details will be written.
 * @param myStudent The student whose details are to be printed.
 * @return The output stream with student details inserted.
 */
std::ostream& operator<<(std::ostream& lhs, const Student& myStudent);

#endif /* STUDENT_H_ */
