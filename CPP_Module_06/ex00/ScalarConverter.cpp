/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:37 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/24 13:34:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <cerrno>
#include <climits>
#include <iomanip>

//CONSTRUCTORS/DESTRUCTOR

ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& src){
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)src;
}
ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter destructor called" << std::endl;
}

//OPERATORS

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src){
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    (void)src;
    return (*this);
}

//METHODS
//Check if all characters are printable, return a boolean
bool strIsPrintable(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while(it != str.end()){
        if(!isprint(*it))
            return (false);
        it++;
    }
    return (true);
}

//ISTYPE
//Use strtol to check if the format is compatible with long, then ckeck int limits, return a boolean
bool isFormatInt(const std::string& str)
{
    char *end = NULL;
    long int n = strtol(str.c_str(), &end,10);
    if (*end != '\0' || n < INT_MIN || n > INT_MAX)
        return (false);
    return (true);
}
//Use strtod to check if the format is compatible with double and check overflow with errno, return a boolean
bool isFormatDouble(const std::string& str)
{
    char *end = NULL;
    errno = 0;
    strtod(str.c_str(), &end);
    if (*end != '\0' || errno == ERANGE)
        return (false);
    return (true);
}
//Use strtof to check if the format is compatible with float and check if the last character is f and at least one number berfore, return a boolean
bool isFormatFloat(const std::string& str)
{
    char *end = NULL;
    errno = 0;
    strtof(str.c_str(), &end);
    if (errno == ERANGE || *end != 'f' || str.size() == 1 || *(end + 1) != '\0')
        return (false);
    return (true);
}
//Verifying the format of the original string, return a string containing the type
const std::string findType(const std::string& str)
{
    if (isFormatInt(str))
        return ("int");
    if (isFormatDouble(str))
        return ("double");
    if (isFormatFloat(str))
        return ("float");
    if (str.length() == 1 && isprint(*str.begin()))
        return ("char");
    return ("Invalid format");
} 

//DISPLAY
//Print results for original string as char format
void displayFromChar(char c){
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(5) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(5) << static_cast<double>(c) << std::endl;
}

//Print results for original string as int format
void displayFromInt(int n){
    if (isprint(static_cast<char>(n)))
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(5) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(5) << static_cast<double>(n) << std::endl;
}

//Print results for original string as float format
void displayFromFloat(float f){
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (f >= 0 && f <= 127 && isprint(static_cast<unsigned char>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else if(f < static_cast<float>(INT_MIN) || f >static_cast<float>(INT_MAX))
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(5) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(5) << static_cast<double>(f) << std::endl;    
}

//Print results for original string as double format
void displayFromDouble(double d){
    std::cout<< "DOUBLE"<<std::endl;
    if (std::isnan(d) || std::isinf(d) )
        std::cout << "char: impossible" << std::endl;
    else if (d >= 0 && d <= 127 && isprint(static_cast<unsigned char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else if(d < INT_MIN || d > INT_MAX)
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(5)  << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(5) << d << std::endl;   
}

//METHODS
//Check if string is empty, printable, and have a valid format, identify the type format of original string and display accordingly

void ScalarConverter::convert(const std::string& str){
    std::string type;
    if (str.empty())
    {
        std::cout << "Impossible conversion: Empty argument" << std::endl;
        return ;
    }
    if (strIsPrintable(str))
    {
        type = findType(str);
        if (type == "char")
            displayFromChar(*str.begin());
        else if (type == "int")
            displayFromInt(strtol(str.c_str(), NULL, 10));
        else if (type == "float")
            displayFromFloat(strtof(str.c_str(), NULL));
        else if (type == "double")
            displayFromDouble(strtod(str.c_str(), NULL));
        else
            std::cout << "Impossible conversion: Invalid format" << std::endl;
    }
    else
        std::cout << "Impossible conversion: Not printable" << std::endl;
}
