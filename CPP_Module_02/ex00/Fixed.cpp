/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/18 17:04:08 by sylabbe          ###   ########.fr       */
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
    
}
Fixed& Fixed::operator=(const Fixed& other){

}

int Fixed::getRawBits( void ) const{
    return (this->fixed_point);
}
void Fixed::setRawBits( int const raw ){
    this->fixed_point = raw;
    return;
}