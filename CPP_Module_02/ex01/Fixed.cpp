/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/23 16:06:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

/*CONTRUCTORS*/
Fixed::Fixed(){
    std::cout << "Constructor Called" << std ::endl;
    fixed_point = 0 << fractionnal_bits;
}
Fixed::Fixed(const int n){
    std::cout << "Int Constructor Called" << std ::endl;
    fixed_point = n <<  fractionnal_bits;
}
Fixed::Fixed(const float nf){
    std::cout << "Float Constructor Called" << std ::endl;
    fixed_point = (int)(roundf(nf * (1 << fractionnal_bits)));
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
    return (*this);
}
std::ostream& operator<<(std::ostream& out, const Fixed& src){
    out << src.toFloat();
    return (out);
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
    return ((float)fixed_point / (1 << fractionnal_bits));
}
int Fixed::toInt( void ) const{
    return (roundf((float)fixed_point / (1 << fractionnal_bits)));
}