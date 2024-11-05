/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:28 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 21:38:33 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

//CONCTRUCTORS/DESTRUCTOR

A_Animal::A_Animal() : type("Default"){
    std::cout << "A_Animal default constructor called" << std::endl;
}
A_Animal::A_Animal(const A_Animal& src): type(src.type){
    std::cout << "A_Animal copy constructor called" << std::endl;
}
A_Animal::~A_Animal(){
    std::cout << "A_Animal destructor called" << std::endl;
}

//OPERATORS

A_Animal& A_Animal::operator=(const A_Animal& src){
    std::cout << "A_Animal operator" << std::endl;
    type = src.type;
    return (*this);
}
