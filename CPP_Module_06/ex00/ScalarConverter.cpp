/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/23 16:06:18 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <algorithm>
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
    char *end = NULL;
    long int n = strtol(str.c_str(), &end,10);
    if (*end != '\0' || n < INT_MIN || n > INT_MAX)
        return (false);
    return (true);
    // size_t i = 0;
    // if (str.size() != i && (str[i] == '+' || str[i] == '-'))
    //     i++;
    // if (i == str.size())
    //     return (false);
    // while(i != str.size())
    // {
    //     if (!isdigit(str[i]))
    //         return (false);
    //     i++;
    // }
    // long long int n = strtol(str.c_str(), NULL, 10);
    // if (n < INT_MIN || n > INT_MAX)
    //     return (false);
    // return (true);
}

bool isFormatDouble(const std::string& str)
{
    char *end = NULL;
    strtod(str.c_str(), &end);
    if (*end != '\0')
        return (false);
    return (true);

    // if (str == "nan" || str == "+inf" || str == "-inf")
    //     return (true);
    // size_t i = 0;
    // if(std::count(str.begin(), str.end(),'.') != 1)// Check number of '.' in str
    //     return (false);
    // if (str.size() != i && (str[i] == '+' || str[i] == '-'))//Skip sign
    //     i++;
    // if (i == str.size() || str[i] == '.' || str.find_first_of(".") == str.size())// Ckeck '.' emplacement
    //     return (false);
    // while(i != str.size())
    // {
    //     if (!isdigit(str[i]) && str[i] != '.')
    //         return (false);
    //     i++;
    // }
    // return (true);
}

bool isFormatFloat(const std::string& str)
{
    char *end = NULL;
    strtof(str.c_str(), &end);
    if (*end != 'f' || str.size() == 1 || end != &str.at(str.size() - 1))
        return (false);
    return (true);

    /////////////////////////////////////////////////////

    // size_t e_pos = str.find('e');
    // size_t point_pos = str.find('.');
    // size_t f_pos = str.find('f');

    // if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
    //     return (true);
    // if(std::count(str.begin(), str.end(),'f') != 1 || str.size() - 1 != f_pos)// Check number of '.' in str
    //     return (false);


    // if(e_pos != std::string::npos)
    // {
    //     if(point_pos != std::string::npos && e_pos < point_pos)//if str contain '.' e must be after it
    //             return (false);
    //     if(str.find_first_of("0123456789") > e_pos || (!isdigit(str[e_pos + 1]) && str[e_pos + 1] != '+' || str[e_pos + 1] != '-'))// digit must be before e; digit or sign after
    //         return (false);
    //     if ((str[e_pos +1] == '-' ||str[e_pos +1] == '+') && !isdigit(str[e_pos + 2]))//if epos + 1 = + or -, next char must be a digit
    //         return (false);
    // }
    // size_t i = 0;
    // while(str[i] != '\0')
    // {
    //     if ((str[i] == '+' || str[i] == '-') && (i != 0 || i != str.find_first_of('e') + 1))//+- at start or after e
    //         return (false);
    //     if (str[i] == 'e' && str.find_first_of("0123456789") > str.find_first_of('e') || )
    //         return (false);
    // }

    ////////////////////////////////////////////////////////

    // if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
    //     return (true);
    // size_t i = 0;
    // if(std::count(str.begin(), str.end(),'.') != 1 || std::count(str.begin(), str.end(),'f') != 1)// Check number of '.' in str
    //     return (false);
    // if (str.size() != i && (str[i] == '+' || str[i] == '-'))//Skip sign
    //     i++;
    // if (i == str.size() || str[i] == '.' || str.find_first_of(".") == str.size() - 1|| str.find_first_of("f") != str.size() - 1)// Ckeck '.' and 'f' emplacement
    //     return (false);
    // while(i != str.size())
    // {
    //     if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
    //         return (false);
    //     i++;
    // }
    // return (true); 
}

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
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else if(f < static_cast<float>(INT_MIN) || f >static_cast<float>(INT_MAX))
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;    
}

void displayFromDouble(double d){
    if (std::isnan(d) || std::isinf(d) )
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else if(d < INT_MIN || d > INT_MAX)
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)  << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;   
}

//METHODS
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

