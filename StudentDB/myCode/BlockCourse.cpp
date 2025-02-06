/**
 * @file BlockCourse.cpp
 * @brief Implementation file for BlockCourse class, which inherits from Course.
 *
 * This file contains the implementations of methods for the BlockCourse class,
 * which represents a block course with specific start and end dates and times.
 * The methods include constructors, print function, file input/output methods
 * (write and read), and others.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#include "BlockCourse.h"
#include <iostream>
using namespace std;

// Constructor Implementation
/**
 * @brief Constructor to initialize BlockCourse with course and time details.
 *
 * This constructor initializes both the base class `Course` and the derived
 * class `BlockCourse` with the required course and time-related details.
 *
 * @param courseKey The unique key identifying the course.
 * @param title The title of the course.
 * @param major The major associated with the course.
 * @param creditPoints The number of credit points for the course.
 * @param startDate The start date of the block course.
 * @param endDate The end date of the block course.
 * @param startTime The start time of the block course.
 * @param endTime The end time of the block course.
 */
BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
                         unsigned char major, float creditPoints,
                         Poco::Data::Date startDate, Poco::Data::Date endDate,
                         Poco::Data::Time startTime, Poco::Data::Time endTime)
    : Course{courseKey, title, major, creditPoints}, startDate{startDate},
      endDate{endDate}, startTime{startTime}, endTime{endTime} {
}

// Constructor with only courseKey parameter
/**
 * @brief Constructor to initialize BlockCourse with only the course key.
 *
 * This constructor initializes the course key and allows for other course
 * details to be set later.
 *
 * @param courseKey The unique key identifying the course.
 */
BlockCourse::BlockCourse(unsigned int courseKey) :
		Course{courseKey, "", ' ', 0} {
}

// Display method implementation
/**
 * @brief Prints the details of the block course.
 *
 * This function outputs the course details, including title, credit points,
 * major, and time-related details such as start date, end date, start time,
 * and end time.
 */
void BlockCourse::print() const {
    cout << "Block Course" << endl;
    /**< Prints the course details using the base class print method. */
    Course::print();
    cout << "Start Date: " << startDate.day() << "." << startDate.month() << "."
         << startDate.year() << endl;
    cout << "End Date: " << endDate.day() << "." << endDate.month() << "."
         << endDate.year() << endl;
    cout << "Start Time: " << startTime.hour() << ":" << startTime.minute()
         << ":" << startTime.second() << endl;
    cout << "End Time: " << endTime.hour() << ":" << endTime.minute()
         << ":" << endTime.second() << endl;
}

// Method Implementation to write to file and
// overwrite virtual write method in Course
/**
 * @brief Writes the course details to the specified output stream.
 *
 * This function writes the course details, including start and end dates,
 * and times to the specified output stream.
 *
 * @param out The output stream to which the course details will be written.
 */
void BlockCourse::write(std::ostream &out) const {
    out << "B;";
    /**< Writes the base class course details to the stream. */
    Course::write(out);
    out << ";" << startDate.day() << "." << startDate.month() << "."
        << startDate.year() << ";" << endDate.day() << "." << endDate.month()
        << "." << endDate.year() << ";"
		<< startTime.hour() << ":" << startTime.minute() << ";"
		<< endTime.hour() << ":" << endTime.minute();
}

// Method Implementation to read from the file and
//overwrite the virtual read method in Course
/**
 * @brief Reads the course details from the specified input stream.
 *
 * This function reads the course details, including start and end dates,
 * and times from the specified input stream.
 *
 * @param in The input stream from which the course details will be read.
 */
void BlockCourse::read(std::istream &in) {
	/**< Reads the base class course details from the input stream. */
    Course::read(in);

    int startDateYear, startDateMonth, startDateDay;
    int endDateYear, endDateMonth, endDateDay;

    // Read startDate
    in >> startDateDay;
    /**< Ignores the period ('.') separating the date components. */
    in.ignore();
    in >> startDateMonth;
    /**< Ignores the period ('.') separating the date components. */
    in.ignore();
    in >> startDateYear;

    startDate = Poco::Data::Date(startDateYear, startDateMonth, startDateDay);
    /**< Ignores the semicolon (;) separating the date components. */
    in.ignore();

    // Read endDate
    in >> endDateDay;
    /**< Ignores the period ('.') separating the date components. */
    in.ignore();
    in >> endDateMonth;
    /**< Ignores the period ('.') separating the date components. */
    in.ignore();
    in >> endDateYear;

    endDate = Poco::Data::Date(endDateYear, endDateMonth, endDateDay);
    /**< Ignores the semicolon (;) separating the date components. */
    in.ignore();

    int startTimeHour, startTimeMinute;
    int endTimeHour, endTimeMinute;

    // Read startTime
    in >> startTimeHour;
    /**< Ignores the colon (':') separating the time components. */
    in.ignore();
    in >> startTimeMinute;

    startTime = Poco::Data::Time(startTimeHour, startTimeMinute, 0);
    /**< Ignores the semicolon (;) separating the time components. */
    in.ignore();

    // Read endTime
    in >> endTimeHour;
    /**< Ignores the colon (':') separating the time components. */
    in.ignore();
    in >> endTimeMinute;

    endTime = Poco::Data::Time(endTimeHour, endTimeMinute, 0);
    /**< Ignores the newline character ('\n') after the last input. */
    in.ignore();
}
