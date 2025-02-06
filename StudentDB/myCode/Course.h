/**
 * @file Course.h
 * @brief Header file for the Course class, representing a general course.
 *
 * This file defines Course class, which serves as a base class for different
 * types of courses. It contains data members such as course key, title, major,
 * and credit points. It also provides methods to access
 * and modify these details
 * as well as methods to print, write, and read course data.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <map>
#include <string>

class Course {
protected:
	/**< Map of major ID to name */
    std::map<unsigned char, std::string> majorById;
    unsigned int courseKey; /**< Unique identifier for the course */
    std::string title; /**< The title of the course */
    unsigned char major; /**< The major associated with the course */
    float creditPoints; /**< The credit points for the course */

public:
    /**
     * @brief Constructs a Course object with the given details.
     *
     * This constructor initializes the course with a unique key, title,
     * major, and credit points.
     *
     * @param courseKey The unique identifier for the course.
     * @param title The title/name of the course.
     * @param major The major associated with the course.
     * @param creditPoints The credit points assigned to the course.
     */
    Course(unsigned int courseKey, std::string title, unsigned char major,
           float creditPoints);

    /**
     * @brief Destructor for the Course class.
     *
     * Virtual destructor ensures proper cleanup of derived classes when
     * deleted through a base class pointer.
     */
    virtual ~Course();

    /**
     * @brief Retrieves the unique course key.
     *
     * This method returns the unique identifier for the course.
     *
     * @return The course key.
     */
    unsigned int getCourseKey() const;

    /**
     * @brief Retrieves the credit points for the course.
     *
     * This method returns the number of credit points assigned to the course.
     *
     * @return The credit points of the course.
     */
    float getCreditPoints() const;

    /**
     * @brief Retrieves the major associated with the course.
     *
     * This method returns the major identifier associated with the course.
     *
     * @return The major identifier.
     */
    unsigned char getMajor() const;

    /**
     * @brief Retrieves the map of major IDs to names.
     *
     * This method returns the map that associates major IDs with their names.
     *
     * @return A reference to the map of major IDs and names.
     */
    const std::map<unsigned char, std::string>& getMajorById() const;

    /**
     * @brief Retrieves the title of the course.
     *
     * This method returns the title of the course.
     *
     * @return A reference to the course title.
     */
    const std::string& getTitle() const;

    /**
     * @brief Sets the course key.
     *
     * This method allows the course key to be modified.
     *
     * @param courseKey The new course key.
     */
    void setCourseKey(unsigned int courseKey);

    /**
     * @brief Prints the course details.
     *
     * This virtual method prints out the basic details of the course, such as
     * course key, title, major, and credit points.
     */
    virtual void print() const;

    /**
     * @brief Writes the course details to the specified output stream.
     *
     * This method writes course details, including course key, title, major,
     * and credit points, to the given output stream.
     *
     * @param out The output stream to write the course details to.
     */
    virtual void write(std::ostream& out) const;

    /**
     * @brief Reads the course details from the specified input stream.
     *
     * This method reads the course details from the given input stream and
     * updates the course data members.
     *
     * @param in The input stream to read the course details from.
     */
    virtual void read(std::istream& in);
};

#endif /* COURSE_H_ */
