/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/14 14:52:27 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <algorithm>
#include <string>



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

bool isFormatDouble(const std::string& str)
{
    if (std::count(str.begin(),str.end(), '.') != 1)
        return (false);
    if (str.find_first_not_of("0123456789.") != std::string::npos)
        return (false);
    if (*str.begin() == '.' || *(str.end() - 1) == '.')
        return (false);
    return (true); 
}

bool isFormatFloat(const std::string& str)
{
    if (std::count(str.begin(),str.end(), '.') != 1 || std::count(str.begin(),str.end(), 'f') != 1)
        return (false);
    if (str.find_first_not_of("0123456789.f") != std::string::npos)
        return (false);
    if (*(str.end() - 1) != 'f')
        return (false);
    if (*str.begin() == '.' || *(str.end() - 2) == '.')
        return (false);
    return (true); 
}

const std::string findType(const std::string& str)
{
    if (str.find_first_not_of("0123456789") == std::string::npos)//Only digit case
        return ("int");
    if (isFormatDouble(str) || str == "nan" || str == "-inf" || str == "+inf")//Only digit + '.' not at start not at end +  pseudo literals double
        return ("double");
    if (isFormatFloat(str) || str == "nanf" || str == "-inff" || str == "+inff")//Only digit + '.' not at start not at end + 'f' at end + pseudo literals float
        return ("float");
    if (str.length() == 1 && isprint(*str.begin()))// One char printable only
        return ("char");
    return ("Invalid format");
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
            std::cout << type << std::endl;
            // displayFromChar(stringToChar(str));
        else if (type == "int")
            std::cout << type << std::endl;
            // displayFromInt(stringToInt(str));
        else if (type == "float")
            std::cout << type << std::endl;
            // displayFromFloat(stringToFloat(str));
        else if (type == "double")
            std::cout << type << std::endl;
            // displayFromDouble(stringToDouble(str));
        else
            std::cout << "Impossible conversion: Invalid format" << std::endl;
    }
    else
        std::cout << "Impossible conversion: Not printable" << std::endl;
}

char    stringToChar(const std::string& str){
    char    c;

    c = *str.begin();
    return (c);
}

int     stringToInt(const std::string& str){
    int n;

    char* end = NULL;
    const char* strc = str.c_str();
    n = strtol(strc, &end, 10);
    return (n);
}

double  stringToDouble(const std::string& str){
    double d;

    d = 
}

float   stringToFloat(const std::string& str){

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