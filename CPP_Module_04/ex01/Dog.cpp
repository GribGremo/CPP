/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 16:17:29 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define BLUE "\033[34m"
#define RESET "\033[0m"

//CONCTRUCTORS/DESTRUCTOR

Dog::Dog(){
    type = "Dog";
    _b = new Brain();
    std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
}
Dog::Dog(const Dog& src):Animal(){
    _b = new Brain(*src._b);
    type = src.type;
    std::cout << BLUE<< "Dog copy constructor called" << RESET<< std::endl;
}
Dog::~Dog(){
    delete _b;
    std::cout << BLUE<< "Dog destructor called" << RESET<< std::endl;
}

//OPERATORS

Dog& Dog::operator=(const Dog& src){
    std::cout << BLUE<< "Dog operator" << RESET<< std::endl;
    if (this != &src) {
        delete _b;
        _b = new Brain(*src._b);
        type = src.type;
    }
    return (*this);
}

//FUNCTIONS

void Dog::makeSound() const{
    std::cout << BLUE<< "*Bark bark*" << RESET<< std::endl;
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