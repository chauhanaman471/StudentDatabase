/**
 * @file SimpleUI.h
 * @brief Header file defining the SimpleUI class for interacting with the
 *        student database system.
 *
 * This file defines the SimpleUI class, which serves as an interface to
 * interact with the student database system. It provides functionality
 * to run the user interface, enabling users to perform operations on the
 * student database.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include "StudentDb.h" // Include the header for the student database

/**
 * @class SimpleUI
 * @brief This class provides the user interface for interacting with the
 *        student database.
 *
 * The SimpleUI class allows the user to perform operations such as adding,
 * removing, or querying student records in the database. It is initialized
 * with a reference to a StudentDb object to facilitate these operations.
 */
class SimpleUI {
private:
    /** Reference to the student database */
    StudentDb& db;

public:
    /**
     * @brief Constructs a SimpleUI object with a reference to the student
     *        database.
     *
     * This constructor initializes the SimpleUI with the given reference to
     * the student database. The database is used for interacting with student
     * data through various user commands.
     *
     * @param db A reference to the student database object.
     */
    SimpleUI(StudentDb& db);

    /**
     * @brief Starts the user interface and runs the main program loop.
     *
     * The run function initiates the user interface, allowing the user to
     * interact with the student database, input commands, and see the output.
     */
    void run();
};

#endif /* SIMPLEUI_H_ */
