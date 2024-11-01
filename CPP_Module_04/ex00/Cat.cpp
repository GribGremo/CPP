/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:39 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/01 17:44:33 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//CONCTRUCTORS/DESTRUCTOR

Cat::Cat(){
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& src){
    type = src.type;
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
}

//OPERATORS

Cat& Cat::operator=(const Cat& src){
    std::cout << "Cat operator" << std::endl;

    type = src.type;
    return (*this);
}

//FUNCTIONS

void Cat::makeSound() const{
    std::cout << "*Meow Meow*" << std::endl;
}