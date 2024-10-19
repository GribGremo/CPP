/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/19 16:07:55 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*CONTRUCTORS*/
Fixed::Fixed(){
    std::cout << "Constructor Called" << std ::endl;
    fixed_point = 0;
}
Fixed::Fixed(const int n){
    std::cout << "Int Constructor Called" << std ::endl;

}
Fixed::Fixed(const float nf){
    std::cout << "Float Constructor Called" << std ::endl;

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

}
int Fixed::toInt( void ) const{

}