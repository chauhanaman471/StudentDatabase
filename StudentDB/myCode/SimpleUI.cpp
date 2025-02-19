/**
 * @file SimpleUI.cpp
 * @brief Implementation of the SimpleUI class for interacting with the student
 *        database system.
 *
 * This file contains the implementation of the SimpleUI class, which provides
 * the user interface for interacting with the student database system. It
 * handles user input and performs various database operations such as adding
 * students, courses, enrollments, and more.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#include "SimpleUI.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;

/**
 * @brief Constructor that initializes the SimpleUI object with a reference
 *        to the student database.
 *
 * This constructor initializes the SimpleUI with the provided reference to
 * the student database object. The database reference is used to perform
 * various operations like adding students, courses, and enrollments.
 *
 * @param db A reference to the student database object.
 */
SimpleUI::SimpleUI(StudentDb &db): db{db} {
}

/**
 * @brief Runs the user interface allowing the user to interact with the
 *        student database.
 *
 * The run method displays a menu to the user and processes the input to
 * perform various operations such as adding a student, adding a course,
 * printing course details, etc. The method loops until the user chooses
 * to exit.
 */
void SimpleUI::run() {
	int dbChoice = -1; // Variable to store user choice from the menu
	while(dbChoice != 0) {
		// Display menu options
		cout <<"1 : Adding new course"<<endl;
		cout <<"2 : Printing all courses"<<endl;
		cout <<"3 : Adding new student"<<endl;
		cout <<"4 : Adding new enrollment"<<endl;
		cout <<"5 : Print student & their enrolled courses & its results"<<endl;
		cout <<"6 : Search student"<<endl;
		cout <<"7 : Update Student"<<endl;
		cout <<"8 : Write to CSV File"<<endl;
		cout <<"9 : Read from CSV File"<<endl;
		cout <<"10: Obtain data directly from server and Update dB"<<endl;
		cout <<"0 : To exit"<<endl;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Ignore the rest of the invalid input
            cout << "Invalid input. Enter a number between 0 and 10." << endl;
            continue; // Restart the loop
        }

		cout <<"Enter the choice for the database: "<<endl;
		cin >> dbChoice; // Getting user choice
		switch(dbChoice) {
		case 1: {
			// Adding a new course
			cout<<"User has chosen to add a new course"<<endl;
			cout <<"Course Key:"<<endl;
			unsigned int courseKey;
			cin >> courseKey;

			cout<<"Course Title:"<<endl;
			cin.ignore(); // To ignore the leftover newline
			string title;
			getline(cin, title);

			cout<<"Course Major (A: Automation, E: Embedded, "
					"C: Communication, P: Power): "<<endl;
			unsigned char major;
			cin >> major;

			cout<<"Course CP: "<<endl;
			float creditPoints;
			cin >> creditPoints;
			db.addCourse(courseKey, title, major, creditPoints);
			break;
		}
		case 2: {
			// Printing all courses
			cout<<"User has chosen to print all courses"<<endl;
			db.listCourse();
			break;
		}
		case 3: {
			// Adding a new student
			cout<<"User has chosen to add a new student"<<endl;

			cout<<"Student First Name:"<<endl;
			cin.ignore(); // Clear the leftover newline
			string firstName;
			getline(cin, firstName);

			cout<<"Student Last Name:"<<endl;
			string lastName;
			getline(cin, lastName);

			cout<<"Student DOB (Year):"<<endl;
			int dobYear;
			cin >> dobYear;
			cout<<"Student DOB (Month):"<<endl;
			int dobMonth;
			cin >> dobMonth;
			cout<<"Student DOB (Date):"<<endl;
			int dobDate;
			cin >> dobDate;
			Poco::Data::Date dob(dobYear, dobMonth, dobDate);

			cout<<"Address: Street Name:"<<endl;
			cin.ignore();
			string streetName;
			getline(cin, streetName);

			cout<<"Address: City Name:"<<endl;
			string cityName;
			getline(cin, cityName);

			cout<<"Address: Additional Information:"<<endl;
			string additionalInfo;
			getline(cin, additionalInfo);

			cout<<"Address: Postal Code:"<<endl;
			unsigned short postalCode;
			cin >> postalCode;

			// Add the student to the database
			db.addNewStudent(firstName, lastName, dob, streetName, postalCode,
					cityName, additionalInfo);
			break;
		}
		case 4: {
			// Adding a new enrollment
			cout<<"User has chosen to add a new enrollment"<<endl;
			cout<<"Please enter student Matrikel Number:"<<endl;
			int matrikelNumber;
			cin >> matrikelNumber;

			cout<<"Please enter course key:"<<endl;
			int courseKey;
			cin >> courseKey;

			cout<<"Please enter semester:"<<endl;
			cin.ignore();
			string semester;
			getline(cin, semester);
			db.addEnrollment(matrikelNumber, courseKey, semester);
			break;
		}
		case 5: {
			// Printing student and their enrolled course and its result
			cout<<"User has chosen to print student & their enrolled course "
				"and its result"<<endl;
			cout<<"Student Matrikel Number:"<<endl;
			int matrikelNumber;
			cin >> matrikelNumber;
			db.printStudent(matrikelNumber);
			break;
		}
		case 6: {
			// Searching for a student
			cout<<"User has chosen to search student"<<endl;
			cout<<"Enter a string/substring from student First Name "
					"or Last Name:"<<endl;
			string subString;
			cin >> subString;
			db.searchStudent(subString);
			break;
		}
		case 7: {
			// Updating student details
			cout<<"User has chosen to update student details"<<endl;
			cout<<"Please enter student Matrikel Number:"<<endl;
			int matrikelNumber;
			cin >> matrikelNumber;
			db.updateStudent(matrikelNumber);
			break;
		}
		case 8: {
			// Writing to CSV file
			cout<<"User entered the file name to write(.csv extension)"<<endl;
			string fileName;
			cin >> fileName;

			// Open the file
			std::ofstream file(fileName);
			if (!file) {
			    cout << "Error: Could not open file for writing"<<endl;
			    return;
			}

			// Write to the file
			db.write(file);

			// Close the file
			file.close();
			break;
		}
		case 9: {
			// Reading from CSV file
			cout<<"User entered the file name to read(.csv extension)"<<endl;
			string fileName;
			cin >> fileName;

			// Open the file
			std::ifstream file(fileName);
			if (!file) {
			    cout << "Error: Could not open file for reading"<<endl;
			    return;
			}

			// Read from the file
			db.read(file);

			// Close the file
			file.close();
			break;
		}
		case 10: {
		    // Obtain data directly from the server and update the database
		    cout << "Enter the number of student data to be added: " << endl;
		    int numStudent;
		    cin >> numStudent;

		    boost::asio::ip::tcp::iostream serverStream
			("www.hhs.users.h-da.cloud", "4242");

		    if (!serverStream) {
		        cerr << "Error: Could not connect to the server" << endl;
		        break;
		    }

		    for (int entries = 0; entries < numStudent; entries++) {
		        serverStream << "generate" << endl;
		        serverStream.flush();

		        string line;
		        string jsonData;

		        // Read until a valid JSON block is found
		        while (getline(serverStream, line)) {
		            // Check for JSON data markers '{' and '}'
		            if (line.find("{") != string::npos &&
		            		line.find("}") != string::npos) {
		                jsonData = line;
		                break;
		            }
		        }

		        if (jsonData.empty()) {
		            cerr << "No valid JSON data found" << endl;
		            continue;
		        }

		        // Parse the JSON using property_tree
		        try {
		            istringstream jsonStream(jsonData);
		            boost::property_tree::ptree jsonTree;
		            boost::property_tree::read_json(jsonStream, jsonTree);

		            string firstName = jsonTree.get<string>("name.firstName");
		            string lastName = jsonTree.get<string>("name.lastName");

		            int dobYear =
		            		jsonTree.get<int>("dateOfBirth.year", 1900);
		            int dobMonth =
		            		jsonTree.get<int>("dateOfBirth.month", 1) + 1;
		            int dobDay = jsonTree.get<int>("dateOfBirth.date", 1);

		            string street =
		            		jsonTree.get<string>("location.street", "Unknown");
		            string city =
		            		jsonTree.get<string>("location.city", "Unknown");
		            string postalCodeStr =
		            		jsonTree.get<string>("location.postCode", "0");

		            unsigned short postalCode =
		            		static_cast<unsigned short>(stoi(postalCodeStr));

		            Poco::Data::Date dateOfBirth(dobYear, dobMonth, dobDay);

		            db.addNewStudent(firstName, lastName, dateOfBirth,
		            		street, postalCode, city, "");

		        } catch (const std::exception& e) {
		            cerr << "Error parsing JSON: " << e.what() << endl;
		        }
		    }

		    serverStream << "quit" << endl;
		    serverStream.flush();
		    cout << "Connection closed with server" << endl;
		    break;
		}
		case 0: {
			// Exiting the program
			cout<<"Exiting the Program"<<endl;
			break;
		}
		default: {
			// Handle invalid choice
			cout<<"Invalid choice by the user"<<endl;
			break;
		}
		}
	}
}
