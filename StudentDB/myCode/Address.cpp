/**
 * @file Address.cpp
 * @brief Implementation file for the Address class.
 *
 * This file implements the methods declared in the Address class, including
 * constructors, setter and getter functions, overloaded operator<<, and the
 * read method to load address data from a file.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#include "Address.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor to initialize Address object with specific details.
 *
 * Initializes the address object with street, postal code, city name, and
 * additional information.
 *
 * @param street The street name of the address.
 * @param postalCode The postal code of the address.
 * @param cityName The city name of the address.
 * @param additionalInfo Any additional information regarding the address.
 */
Address::Address(std::string street, unsigned short postalCode,
                 std::string cityName, std::string additionalInfo) :
    street{street}, postalCode{postalCode}, cityName{cityName},
    additionalInfo{additionalInfo} {
}

/**
 * @brief Default constructor to initialize an empty Address object.
 *
 * Sets all member variables to their default values.
 */
Address::Address() : street{""},postalCode{0},cityName{""},additionalInfo{""}{
}

/**
 * @brief Setter to update the additional information of the address.
 *
 * @param additionalInfo The new additional information for the address.
 */
void Address::setAdditionalInfo(const std::string &additionalInfo) {
    this->additionalInfo = additionalInfo;
}

/**
 * @brief Setter to update the city name of the address.
 *
 * @param cityName The new city name for the address.
 */
void Address::setCityName(const std::string &cityName) {
    this->cityName = cityName;
}

/**
 * @brief Setter to update the postal code of the address.
 *
 * @param postalCode The new postal code for the address.
 */
void Address::setPostalCode(unsigned short postalCode) {
    this->postalCode = postalCode;
}

/**
 * @brief Setter to update the street name of the address.
 *
 * @param street The new street name for the address.
 */
void Address::setStreet(const std::string &street) {
    this->street = street;
}

/**
 * @brief Getter to retrieve the additional information of the address.
 *
 * @return const std::string& The additional information of the address.
 */
const std::string& Address::getAdditionalInfo() const {
    return additionalInfo;
}

/**
 * @brief Getter to retrieve the city name of the address.
 *
 * @return const std::string& The city name of the address.
 */
const std::string& Address::getCityName() const {
    return cityName;
}

/**
 * @brief Getter to retrieve the postal code of the address.
 *
 * @return unsigned short The postal code of the address.
 */
unsigned short Address::getPostalCode() const {
    return postalCode;
}

/**
 * @brief Getter to retrieve the street name of the address.
 *
 * @return const std::string& The street name of the address.
 */
const std::string& Address::getStreet() const {
    return street;
}

/**
 * @brief Overloaded << operator to output Address object details.
 *
 * Outputs the address details (street, postal code, city, additional info) to
 * the output stream.
 *
 * @param lhs The output stream to which the address will be written.
 * @param myAddress The Address object to be output.
 * @return std::ostream& Returns the modified output stream.
 */
std::ostream& operator<<(std::ostream &lhs, const Address &myAddress) {
    lhs << " " << myAddress.street << ", " << myAddress.postalCode << ", "
        << myAddress.cityName << ", " << myAddress.additionalInfo << endl;
    return lhs;
}

/**
 * @brief Reads address data from an input stream (file).
 *
 * This method reads the address information, including street, postal code,
 * city name, and additional info from the provided input stream.
 *
 * @param in The input stream from which the address data will be read.
 */
void Address::read(std::istream &in) {
    getline(in, street, ';');         /**< Read the street name. */
    in >> postalCode;                 /**< Read the postal code. */
    in.ignore();
    getline(in, cityName, ';');       /**< Read the city name. */
    getline(in, additionalInfo, '\n'); /**< Read the additional info. */
}
