/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/01 17:42:52 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//CONCTRUCTORS/DESTRUCTOR

Dog::Dog(){
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog& src){
    type = src.type;
    std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}

//OPERATORS

Dog& Dog::operator=(const Dog& src){
    std::cout << "Dog operator" << std::endl;

    type = src.type;
    return (*this);
}

//FUNCTIONS

void Dog::makeSound() const{
    std::cout << "*Bark bark*" << std::endl;
}