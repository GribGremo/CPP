/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:39 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 18:03:30 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//CONCTRUCTORS/DESTRUCTOR

Cat::Cat(){
    type = "Cat";
    _b = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& src) : Animal(){
    _b = new Brain(*src._b);
    type = src.type;
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat::~Cat(){
    delete _b;
    std::cout << "Cat destructor called" << std::endl;
}

//OPERATORS

Cat& Cat::operator=(const Cat& src){
    std::cout << "Cat operator" << std::endl;
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
    std::cout << "*Meow Meow*" << std::endl;
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