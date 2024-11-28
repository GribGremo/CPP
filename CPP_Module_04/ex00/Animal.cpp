/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:28 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 14:58:55 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

//CONCTRUCTORS/DESTRUCTOR

Animal::Animal() : type("Default_Animal"){
    std::cout << GREEN << "Animal default constructor called" <<RESET << std::endl;
}
Animal::Animal(const Animal& src): type(src.type){
    std::cout << GREEN<< "Animal copy constructor called" <<RESET<< std::endl;
}
Animal::~Animal(){
    std::cout << GREEN<< "Animal destructor called" <<RESET<< std::endl;
}

//OPERATORS

Animal& Animal::operator=(const Animal& src){
    std::cout << GREEN<< "Animal operator" <<RESET<< std::endl;
    type = src.type;
    return (*this);
}

//SETTERS/GETTERS

std::string Animal::getType() const{
    return(type);
}

//FUNCTIONS

void Animal::makeSound() const{
    std::cout << GREEN<< "This is sound of an Animal" <<RESET<< std::endl;
}