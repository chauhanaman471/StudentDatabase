/**
 * @file WeeklyCourse.h
 * @brief This header file defines the WeeklyCourse class, a derived class
 *        from the Course class. It contains information about weekly
 *        courses, including start time, end time, and the day of the week
 *        when the course occurs.
 *
 * @author Aman Chauhan
 * @date 17 Jan 2025
 * @version 1.0
 *
 * @note Master Student at HDA, specializing in Microelectronics.
 * @matriculation Number: 1127928
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include "Course.h"
#include <Poco/Data/Time.h>

/**
 * @class WeeklyCourse
 * @brief Derived class from Course that represents a weekly course with
 *        specific details like the day of the week, start time, and end time.
 *
 * This class contains methods for printing, writing to a file, and reading
 * from a file specific details for a weekly course.
 */
class WeeklyCourse : public Course {
private:
    /**
     * @brief Day of the week when the course occurs.
     */
    Poco::DateTime::DaysOfWeek dayOfWeek;

    /**
     * @brief Start time of the course.
     */
    Poco::Data::Time startTime;

    /**
     * @brief End time of the course.
     */
    Poco::Data::Time endTime;

public:
    /**
     * @brief Constructor that initializes the WeeklyCourse with the given
     *        course details such as course key, title, major, credit points,
     *        and specific details for the weekly course.
     *
     * @param courseKey Unique identifier for the course.
     * @param title Title of the course.
     * @param major Major of the course.
     * @param creditPoint Credit points for the course.
     * @param dayOfWeek Day of the week when the course is scheduled.
     * @param startTime Start time of the course.
     * @param endTime End time of the course.
     */
    WeeklyCourse(unsigned int courseKey,
                 std::string title,
                 unsigned char major,
                 float creditPoint,
                 Poco::DateTime::DaysOfWeek dayOfWeek,
                 Poco::Data::Time startTime,
                 Poco::Data::Time endTime);

    /**
     * @brief Constructor that only takes the course key as a parameter.
     *
     * @param courseKey Unique identifier for the course.
     */
    WeeklyCourse(unsigned int courseKey);

    /**
     * @brief Prints the details of the course, including its specific
     *        information such as the day of the week, start time, and end
     *        time.
     */
    void print() const;

    /**
     * @brief Writes the details of the course, including the additional
     *        weekly course details such as day of the week, start time,
     *        and end time to an output stream.
     *
     * @param out Output stream to which the course details are written.
     */
    void write(std::ostream& out) const;

    /**
     * @brief Reads the details of the weekly course from an input stream and
     *        stores it in the respective data members of the class.
     *
     * @param in Input stream from which the course details are read.
     */
    void read(std::istream& in);
};

#endif /* WEEKLYCOURSE_H_ */
