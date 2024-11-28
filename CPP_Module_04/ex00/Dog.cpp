/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 14:24:35 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define BLUE "\033[34m"
#define RESET "\033[0m"

//CONCTRUCTORS/DESTRUCTOR

Dog::Dog(){
    type = "Dog";
    std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
}
Dog::Dog(const Dog& src){
    type = src.type;
    std::cout << BLUE <<"Dog copy constructor called" << RESET<< std::endl;
}
Dog::~Dog(){
    std::cout << BLUE <<"Dog destructor called" << RESET<< std::endl;
}

//OPERATORS

Dog& Dog::operator=(const Dog& src){
    std::cout << BLUE <<"Dog assignment operator" << RESET<< std::endl;

    type = src.type;
    return (*this);
}

//FUNCTIONS

void Dog::makeSound() const{
    std::cout << BLUE << "*Bark bark*" << RESET<< std::endl;
}