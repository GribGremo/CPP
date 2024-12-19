/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/19 18:51:49 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <limits>
#include <cstdlib>
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
bool isFormatInt(const std::string& str)
{
    size_t i = 0;
    if (str.size() != i && (str[i] == '+' || str[i] == '-'))
        i++;
    if (i == str.size())
        return (false);
    while(i != str.size())
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    long long int n = strtol(str.c_str(), NULL, 10);
    if (n < INT_MIN || n > INT_MAX)
        return (false);
    return (true); 
}

bool isFormatDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return (true);
    size_t i = 0;
    if(std::count(str.begin(), str.end(),'.') != 1)// Check number of '.' in str
        return (false);
    if (str.size() != i && (str[i] == '+' || str[i] == '-'))//Skip sign
        i++;
    if (i == str.size() || str[i] == '.' || str.find_first_of(".") == str.size())// Ckeck '.' emplacement
        return (false);
    while(i != str.size())
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return (false);
        i++;
    }
    return (true);
}

bool isFormatFloat(const std::string& str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return (true);
    size_t i = 0;
    if(std::count(str.begin(), str.end(),'.') != 1 || std::count(str.begin(), str.end(),'f') != 1)// Check number of '.' in str
        return (false);
    if (str.size() != i && (str[i] == '+' || str[i] == '-'))//Skip sign
        i++;
    if (i == str.size() || str[i] == '.' || str.find_first_of(".") == str.size() - 1|| str.find_first_of("f") != str.size() - 1)// Ckeck '.' and 'f' emplacement
        return (false);
    while(i != str.size())
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
            return (false);
        i++;
    }
    return (true); 
}

const std::string findType(const std::string& str)
{
    if (isFormatInt(str))//Only digit case
        return ("int");
    if (isFormatDouble(str))//Only digit + '.' not at start not at end +  pseudo literals double
        return ("double");
    if (isFormatFloat(str))//Only digit + '.' not at start not at end + 'f' at end + pseudo literals float
        return ("float");
    if (str.length() == 1 && isprint(*str.begin()))// One char printable only
        return ("char");
    return ("Invalid format");
} 

//CONVERT
char    stringToChar(const std::string& str){
    char    c;

    c = *str.begin();
    return (c);
}

int     stringToInt(const std::string& str){
    (void)str;
    int n = 0;

    char* end = NULL;
    const char* strc = str.c_str();
    n = strtol(strc, &end, 10);
    return (n);
}

double  stringToDouble(const std::string& str){
    double d = strtod(str.c_str(), NULL);
    // int sgn = 1;
    // if (*str.begin() == '-')//May take care of space
    //     sgn = -1;
    // if (std::isinf(d))
    //     return d;//(std::numeric_limits<double>::infinity() * sgn);
    // else if (std::isnan(d))
    //     return d;//std::numeric_limits<double>::quiet_NaN();
    return (d);
}

float   stringToFloat(const std::string& str){
    float f = strtof(str.c_str(), NULL);
    // int sgn = 1;
    // if (*str.begin() == '-')//May take care of space
    //     sgn = -1;
    // if (std::isinf(f))
    //     return f;//(std::numeric_limits<float>::infinity() * sgn);
    // else if (std::isnan(f))
    //     return f;//std::numeric_limits<float>::quiet_NaN();
    return (f);
}

//DISPLAY
void displayFromChar(char c){
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void displayFromInt(int n){
    if (isprint(static_cast<char>(n)))
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void displayFromFloat(float f){
    if (isprint(static_cast<char>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;    
}

void displayFromDouble(double d){
    if (isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;   
}

//
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
        std::cout << "TYPE: " << type << std::endl;
        if (type == "char")
        {
            std::cout << "VALUE: " << stringToChar(str) << std::endl;
            displayFromChar(stringToChar(str));
        }
        else if (type == "int")
        {
            std::cout << "VALUE: " << stringToInt(str) << std::endl;
            displayFromInt(stringToInt(str));
        }
        else if (type == "float")
        {
            std::cout << "VALUE: " << stringToFloat(str) << std::endl;
            displayFromFloat(stringToFloat(str));
        }
        else if (type == "double")
        {
            std::cout << "VALUE: " << stringToDouble(str) << std::endl;
            displayFromDouble(stringToDouble(str));
        }
        else
            std::cout << "Impossible conversion: Invalid format" << std::endl;
    }
    else
        std::cout << "Impossible conversion: Not printable" << std::endl;
}