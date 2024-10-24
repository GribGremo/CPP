/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/19 12:18:11 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
    std::cout << "Constructor Called" << std ::endl;
    fixed_point = 0;
}
Fixed::~Fixed(){
    std::cout << "Destructor Called" << std ::endl;
}
Fixed::Fixed(const Fixed& other){
    std::cout << "Copy contructor Called" << std ::endl;
    *this = other;
}
Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std ::endl;
    fixed_point = other.fixed_point;
    return (*this);//
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std ::endl;
    return (this->fixed_point);
}
void Fixed::setRawBits( int const raw ){
    this->fixed_point = raw;
    return;
}