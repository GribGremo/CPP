/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/21 17:47:20 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

/*CONTRUCTORS*/
Fixed::Fixed(){
    std::cout << "Constructor Called" << std ::endl;
    fixed_point = 0 << fractionnal_bits;//a voir
}
Fixed::Fixed(const int n){
    std::cout << "Int Constructor Called" << std ::endl;
    fixed_point = n <<  fractionnal_bits;
}
Fixed::Fixed(const float nf){
    std::cout << "Float Constructor Called" << std ::endl;
    fixed_point = (int)(roundf(nf * 256));
}
Fixed::Fixed(const Fixed& other){
    std::cout << "Copy contructor Called" << std ::endl;
    *this = other;
}
Fixed::~Fixed(){
    std::cout << "Destructor Called" << std ::endl;
}

/*OPERATORS*/
Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std ::endl;
    fixed_point = other.fixed_point;
    return (*this);//
}
std::ostream& operator<<(std::ostream& out, const Fixed& obj){
    out << obj.toFloat();
    return (out);
}
//Comparisons operators
bool Fixed::operator<(const Fixed& other){
    if (fixed_point < other.fixed_point)
        return (1);
    else
        return (0);
}
bool Fixed::operator>(const Fixed& other){
    if (fixed_point > other.fixed_point)
        return (1);
    else
        return (0);
}
bool Fixed::operator<=(const Fixed& other){
    if (fixed_point <= other.fixed_point)
        return (1);
    else
        return (0);
}
bool Fixed::operator>=(const Fixed& other){
    if (fixed_point >= other.fixed_point)
        return (1);
    else
        return (0);
}
bool Fixed::operator==(const Fixed& other){
    if (fixed_point == other.fixed_point)
        return (1);
    else
        return (0);
}
bool Fixed::operator!=(const Fixed& other){
    if (fixed_point != other.fixed_point)
        return (1);
    else
        return (0);
}
//arithmetic operators
Fixed Fixed::operator+(const Fixed& other){
    Fixed res(this->toFloat() + other.toFloat());
    return(res);
}
Fixed Fixed::operator-(const Fixed& other){
    Fixed res(this->toFloat() - other.toFloat());
    return(res);
}
Fixed Fixed::operator*(const Fixed& other){
    Fixed res(this->toFloat() * other.toFloat());
    return(res);
}
Fixed Fixed::operator/(const Fixed& other){
    Fixed res(this->toFloat() / other.toFloat());
    return(res);
}
//incrementation operators
Fixed& Fixed::operator++(){
    fixed_point++;
    return (*this);
}
Fixed& Fixed::operator--(){
    fixed_point--;
    return (*this);
}
Fixed Fixed::operator++(int){
    Fixed temp(*this);
    fixed_point++;
    return(temp);
}
Fixed Fixed::operator--(int){
    Fixed temp(*this);
    fixed_point--;
    return(temp);
}

/*SETTERS/GETTERS*/ 
int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std ::endl;
    return (this->fixed_point);
}
void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std ::endl;
    this->fixed_point = raw;
    return;
}

/*FUNCTIONS*/
float Fixed::toFloat( void ) const{
    return ((float)fixed_point / 256);//
}
int Fixed::toInt( void ) const{
    return (roundf((float)fixed_point / 256));
}
Fixed& Fixed::min(Fixed& a, Fixed& b){
    if(a.fixed_point > b.fixed_point)
        return (b);
    else
        return (a);
}
Fixed& Fixed::max(Fixed& a, Fixed& b){
    if(a.fixed_point > b.fixed_point)
        return (a);
    else
        return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if(a.fixed_point > b.fixed_point)
        return (b);
    else
        return (a);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if(a.fixed_point > b.fixed_point)
        return (a);
    else
        return (b);
}