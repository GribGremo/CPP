/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:39 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 16:16:15 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

//CONCTRUCTORS/DESTRUCTOR

Cat::Cat(){
    type = "Cat";
    _b = new Brain();
    std::cout << YELLOW <<"Cat default constructor called" << RESET << std::endl;
}
Cat::Cat(const Cat& src) : Animal(){
    _b = new Brain(*src._b);
    type = src.type;
    std::cout << YELLOW <<"Cat copy constructor called" << RESET<< std::endl;
}
Cat::~Cat(){
    delete _b;
    std::cout << YELLOW <<"Cat destructor called" << RESET<< std::endl;
}

//OPERATORS

Cat& Cat::operator=(const Cat& src){
    std::cout << YELLOW <<"Cat operator" << RESET<< std::endl;
    if (this != &src)
    {
        delete _b;
        _b = new Brain(*src._b);
        type = src.type;
    }
    return (*this);
}

//FUNCTIONS

void Cat::makeSound() const{
    std::cout << YELLOW <<"*Meow Meow*" << RESET<< std::endl;
}

//SETTERS/GETTERS
void Cat::setIdea(const std::string& idea, const int it_idea){
    if (it_idea>99|| it_idea < 0)
        return ;
    _b->_ideas[it_idea] = idea; 
}
const std::string Cat::getIdea(const int it_idea){
    if (it_idea > 99|| it_idea < 0)
        return ("");
    return( _b->_ideas[it_idea]);
}