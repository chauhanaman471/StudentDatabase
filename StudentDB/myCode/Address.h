/**
 * @file Address.h
 * @brief Header file for the Address class definition.
 *
 * This file defines the Address class and provides its constructor,
 * setter and getter methods, as well as overloaded operator functions.
 *
 * @author Aman Chauhan
 * @date 2025-01-30
 * @version 1.0
 * @note Master Student at HDA, Matriculation Number: 1127928
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>

/**
 * @class Address
 * @brief Represents an address with street, postal code, city name, and
 * additional information.
 *
 * The Address class encapsulates the details of an address, providing methods
 * for updating & retrieving its attributes. It also provides file reading and
 * operator overloading.
 */
class Address {
private:
    std::string street;          /**< Street of the address. */
    unsigned short postalCode;   /**< Postal code of the address. */
    std::string cityName;        /**< Name of the city. */
    std::string additionalInfo;  /**< Additional information about address. */

public:
    /**
     * @brief Constructor to initialize an Address object with specific details.
     *
     * Initializes the address object with street, postal code, city name, and
     * additional information.
     *
     * @param street Street name of the address.
     * @param postalCode Postal code of the address.
     * @param cityName City name of the address.
     * @param additionalInfo Additional information regarding the address.
     */
    Address(std::string street,
            unsigned short postalCode,
            std::string cityName,
            std::string additionalInfo);

    /**
     * @brief Default constructor to initialize an empty Address object.
     */
    Address();

    /**
     * @brief Setter to update the additional information of the address.
     *
     * @param additionalInfo New additional information for the address.
     */
    void setAdditionalInfo(const std::string &additionalInfo);

    /**
     * @brief Setter to update the city name of the address.
     *
     * @param cityName New city name for the address.
     */
    void setCityName(const std::string &cityName);

    /**
     * @brief Setter to update the postal code of the address.
     *
     * @param postalCode New postal code for the address.
     */
    void setPostalCode(unsigned short postalCode);

    /**
     * @brief Setter to update the street name of the address.
     *
     * @param street New street name for the address.
     */
    void setStreet(const std::string &street);

    /**
     * @brief Overloaded << operator to output the address details.
     *
     * @param lhs The output stream to which the address will be written.
     * @param myAddress The address object to be output.
     * @return std::ostream& Returns the modified output stream.
     */
    friend std::ostream& operator<<(std::ostream& lhs,
    		const Address& myAddress);

    /**
     * @brief Getter to retrieve the additional information of the address.
     *
     * @return const std::string& The additional information of the address.
     */
    const std::string& getAdditionalInfo() const;

    /**
     * @brief Getter to retrieve the city name of the address.
     *
     * @return const std::string& The city name of the address.
     */
    const std::string& getCityName() const;

    /**
     * @brief Getter to retrieve the postal code of the address.
     *
     * @return unsigned short The postal code of the address.
     */
    unsigned short getPostalCode() const;

    /**
     * @brief Getter to retrieve the street name of the address.
     *
     * @return const std::string& The street name of the address.
     */
    const std::string& getStreet() const;

    /**
     * @brief Read the address data from an input stream (file).
     *
     * @param in The input stream from which the address data will be read.
     */
    void read(std::istream& in);
};

/**
 * @brief Overloaded << operator to output Address object details.
 *
 * @param lhs The output stream to which the address will be written.
 * @param myAddress The Address object to be output.
 * @return std::ostream& Returns the modified output stream.
 */
std::ostream& operator<<(std::ostream& lhs, const Address& myAddress);

#endif /* ADDRESS_H_ */
