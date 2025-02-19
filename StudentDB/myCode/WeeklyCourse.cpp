/**
 * @file WeeklyCourse.cpp
 * @brief This file implements the methods for the WeeklyCourse class, which
 *        represents a weekly course with specific details like the day of
 *        the week, start time, and end time.
 *
 * @author Aman Chauhan
 * @date 17 Jan 2025
 * @version 1.0
 *
 * @note Master Student at HDA, specializing in Microelectronics.
 * @matriculation Number: 1127928
 */

#include "WeeklyCourse.h"
#include <iostream>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
using namespace std;

/**
 * @brief Constructor that initializes a WeeklyCourse with course details
 *        including the course key, title, major, credit points, and weekly
 *        course details such as day of the week, start time, and end time.
 *
 * @param courseKey Unique identifier for the course.
 * @param title Title of the course.
 * @param major Major of the course.
 * @param creditPoint Credit points for the course.
 * @param dayOfWeek Day of the week when the course is scheduled.
 * @param startTime Start time of the course.
 * @param endTime End time of the course.
 */
WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
        unsigned char major, float creditPoint,
        Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime,
        Poco::Data::Time endTime):
        Course{courseKey,title,major,creditPoint},
        dayOfWeek{dayOfWeek},
        startTime{startTime},
        endTime{endTime} {
}

/**
 * @brief Constructor that initializes a WeeklyCourse with only the course
 *        key. Default values are used for the rest of the course attributes.
 *
 * @param courseKey Unique identifier for the course.
 */
WeeklyCourse::WeeklyCourse(unsigned int courseKey):Course{courseKey,"",' ',0}{
}

/**
 * @brief Prints the details of the weekly course, including the course
 *        information from the parent class and specific details such as
 *        the day of the week, start time, and end time.
 */
void WeeklyCourse::print() const {
    // Temporarily print the course details
    cout << "Weekly Course" << endl;
    Course::print();
    string weekDay;
    switch(dayOfWeek) {
        case 0: weekDay = "SUNDAY"; break;
        case 1: weekDay = "MONDAY"; break;
        case 2: weekDay = "TUESDAY"; break;
        case 3: weekDay = "WEDNESDAY"; break;
        case 4: weekDay = "THURSDAY"; break;
        case 5: weekDay = "FRIDAY"; break;
        case 6: weekDay = "SATURDAY"; break;
        default: weekDay = "INVALID INPUT BY USER"; break;
    }
    cout << "Day of Week: " << weekDay << endl;
    cout << "Start Time: " << startTime.hour() << ":"
         << startTime.minute() << ":"
         << startTime.second() << endl;
    cout << "End Time: " << endTime.hour() << ":"
         << endTime.minute() << ":"
         << endTime.second() << endl;
}

/**
 * @brief Writes the details of the weekly course to an output stream. This
 *        includes the course details from the parent class and specific
 *        weekly course details such as day of the week, start time, and
 *        end time.
 *
 * @param out Output stream to which the course details are written.
 */
void WeeklyCourse::write(std::ostream &out) const {
    out << "W;";
    Course::write(out);
    out << ";" << dayOfWeek << ";" << startTime.hour() << ":" <<
    		startTime.minute()
        << ";" << endTime.hour() << ":" << endTime.minute();
}

/**
 * @brief Reads the details of the weekly course from an input stream and
 *        updates the class attributes. It reads the course information from
 *        the parent class and the weekly course details including the day of
 *        the week, start time, and end time.
 *
 * @param in Input stream from which the course details are read.
 */
void WeeklyCourse::read(std::istream &in) {
    Course::read(in); // Read the course class attributes till CP

    // Read and set the day of the week
    int weekDay;
    in >> weekDay;
    switch(weekDay) {
        case 0: dayOfWeek = Poco::DateTime::SUNDAY; break;
        case 1: dayOfWeek = Poco::DateTime::MONDAY; break;
        case 2: dayOfWeek = Poco::DateTime::TUESDAY; break;
        case 3: dayOfWeek = Poco::DateTime::WEDNESDAY; break;
        case 4: dayOfWeek = Poco::DateTime::THURSDAY; break;
        case 5: dayOfWeek = Poco::DateTime::FRIDAY; break;
        case 6: dayOfWeek = Poco::DateTime::SATURDAY; break;
    }

    in.ignore(); // Ignore the semicolon

    int startTimeHour, startTimeMinute;
    int endTimeHour, endTimeMinute;

    // Read and set the start time
    in >> startTimeHour;
    in.ignore(); // Ignore the colon
    in >> startTimeMinute;
    startTime = Poco::Data::Time(startTimeHour, startTimeMinute, 0);

    in.ignore(); // Ignore the semicolon

    // Read and set the end time
    in >> endTimeHour;
    in.ignore(); // Ignore the colon
    in >> endTimeMinute;
    endTime = Poco::Data::Time(endTimeHour, endTimeMinute, 0);

    in.ignore(); // Ignore the newline '\n'
}
