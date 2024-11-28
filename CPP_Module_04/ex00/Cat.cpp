/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:39 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 14:26:07 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//CONCTRUCTORS/DESTRUCTOR

#define YELLOW "\033[33m"
#define RESET "\033[0m"


Cat::Cat(){
    type = "Cat";
    std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;
}
Cat::Cat(const Cat& src){
    type = src.type;
    std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
}
Cat::~Cat(){
    std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
}

//OPERATORS

Cat& Cat::operator=(const Cat& src){
    std::cout << YELLOW << "Cat operator" << RESET << std::endl;

    type = src.type;
    return (*this);
}

//FUNCTIONS

void Cat::makeSound() const{
    std::cout << YELLOW << "*Meow Meow*" << RESET << std::endl;
}