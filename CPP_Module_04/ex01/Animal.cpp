/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:28 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 12:20:10 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//CONCTRUCTORS/DESTRUCTOR

Animal::Animal() : type("Default"){
    std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const Animal& src): type(src.type){
    std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

//OPERATORS

Animal& Animal::operator=(const Animal& src){
    std::cout << "Animal operator" << std::endl;
    type = src.type;
    return (*this);
}

//SETTERS/GETTERS

std::string Animal::getType() const{
    return(type);
}


//FUNCTIONS

void Animal::makeSound() const{
}

//SETTERS/GETTERS
void Animal::setIdea(const std::string& idea, const int it_idea){
    (void) idea;
    (void)it_idea;
}
const std::string Animal::getIdea(const int it_idea){
    (void)it_idea;
    return("Help... please...");
}