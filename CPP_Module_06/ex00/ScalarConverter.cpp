/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/18 13:32:50 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <algorithm>
#include <string>
#include <climits>



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


// float isPseudoLiteralsf(const std::string& str)
// {
//     if (str == "nanf")
//         return std::nanf("");
//     else if (str == "-inff")
//         return -std::numeric_limits<float>::infinity();
//     else if (str == "+inff")
//         return std::numeric_limits<float>::infinity();
//     if (str == "nan")
//         return std::nan("");
//     else if (str == "-inf")
//         return -1 / 0;
//     else if (str == "+inf")
//         return 1 / 0;
//     return (0.0f);
// }

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
    char* end = NULL;
    const char* strc = str.c_str();
    int n = strtol(strc, &end, 10);
    if (n < INT_MIN || n > INT_MAX)
        return (false);
    return (true); 
}

bool isFormatDouble(const std::string& str)
{
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
    char* end = NULL;
    const char* strc = str.c_str();
    int n = strtol(strc, &end, 10);
    if (n < INT_MIN || n > INT_MAX)
        return (false);
    return (true); 
}

bool isFormatFloat(const std::string& str)
{
    size_t i = 0;
    if(std::count(str.begin(), str.end(),'.') != 1 || std::count(str.begin(), str.end(),'f') != 1)// Check number of '.' in str
        return (false);
    if (str.size() != i && (str[i] == '+' || str[i] == '-'))//Skip sign
        i++;
    if (i == str.size() || str[i] == '.' || str.find_first_of(".") == str.size() || str.find_first_of("f") != str.size())// Ckeck '.' and 'f' emplacement
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
    if (isFormatDouble(str) || str == "nan" || str == "-inf" || str == "+inf")//Only digit + '.' not at start not at end +  pseudo literals double
        return ("double");
    if (isFormatFloat(str) || str == "nanf" || str == "-inff" || str == "+inff")//Only digit + '.' not at start not at end + 'f' at end + pseudo literals float
        return ("float");
    if (str.length() == 1 && isprint(*str.begin()))// One char printable only
        return ("char");
    return ("Invalid format");
} 

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
    (void) str;
    double d = 0.0f;
    // const char* strc = str.c_str();
    return (d);
}

float   stringToFloat(const std::string& str){
    (void) str;
    float f = 0.0;
    return (f);
}

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
        {
            std::cout << type << std::endl;
            // displayFromChar(stringToChar(str));
            std::cout << stringToChar(str) << std::endl;
        }
        else if (type == "int")
        {
            std::cout << type << std::endl;
            // displayFromInt(stringToInt(str));
            std::cout << stringToInt(str) << std::endl;

        }
        else if (type == "float")
        {
            std::cout << type << std::endl;
            // displayFromFloat(stringToFloat(str));
            std::cout << stringToFloat(str) << std::endl;
        }
        else if (type == "double")
        {
            std::cout << type << std::endl;
            // displayFromDouble(stringToDouble(str));
            std::cout << stringToDouble(str) << std::endl;
        }
        else
            std::cout << "Impossible conversion: Invalid format" << std::endl;
    }
    else
        std::cout << "Impossible conversion: Not printable" << std::endl;
}




// int charToInt(char c){

// }

// float charToFloat(char c){

// }

// double charToDouble(char c){

// }

// char intToChar(int n){

// }

// float intToFloat(int n){
    
// }

// double intToDouble(int n){
    
// }

// char floatToChar(float f){

// }

// int floatToInt(float f){
    
// }

// char floatToChar(float f){
    
// }

// char doubletoChar(double d){

// }

// int doubletoInt(double d){
    
// }

// float doubletoFloat(double d){
    
// }
/*

//include numeric limits, special values

-identifier le type recu
-convertir la string recu dans le type identifie
-tenter de convertir dans chaque type
-print chaque resultat sur le terminal (if not possible display "Type conversion not possible: custom message" )

char

int

float

double
*/