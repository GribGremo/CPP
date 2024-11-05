/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 21:44:27 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//CONCTRUCTORS/DESTRUCTOR

Dog::Dog(){
    type = "Dog";
    _b = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog& src):A_Animal(){
    _b = new Brain(*src._b);
    type = src.type;
    std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog(){
    delete _b;
    std::cout << "Dog destructor called" << std::endl;
}

//OPERATORS

Dog& Dog::operator=(const Dog& src){
    std::cout << "Dog operator" << std::endl;
    if (this != &src) {
        delete _b;
        _b = new Brain(*src._b);
        type = src.type;
    }
    return (*this);
}

//FUNCTIONS

void Dog::makeSound() const{
    std::cout << "*Bark bark*" << std::endl;
}

//SETTERS/GETTERS
void Dog::setIdea(const std::string& idea, const int it_idea){
        if (it_idea>99 || it_idea < 0)
        return ;
    _b->_ideas[it_idea] = idea; 
}
const std::string Dog::getIdea(const int it_idea){
        if (it_idea>99|| it_idea < 0)
        return ("");
    return( _b->_ideas[it_idea]);
}