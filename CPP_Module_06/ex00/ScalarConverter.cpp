/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/13 15:00:34 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//CONSTRUCTORS/DESTRUCTOR

ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& src){
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}
ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter destructor called" << std::endl;
}

//OPERATORS

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src){
    std::cout << "ScalarConverter assignment operator called" << std::endl;
}

//METHODS



void ScalarConverter::convert(const std::string& str){

}


int charToInt(char c){

}

float charToFloat(char c){

}

double charToDouble(char c){

}

char intToChar(int n){

}

float intToFloat(int n){
    
}

double intToDouble(int n){
    
}

char floatToChar(float f){

}

int floatToInt(float f){
    
}

char floatToChar(float f){
    
}

char doubletoChar(double d){

}

int doubletoInt(double d){
    
}

float doubletoFloat(double d){
    
}
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