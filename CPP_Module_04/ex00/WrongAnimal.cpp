/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:22:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 14:59:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define CYAN    "\033[36m"
#define RESET "\033[0m"

//CONSTRUCTORS
WrongAnimal::WrongAnimal(): type("Default_Wrong_Animal"){
    std::cout << CYAN << "WrongAnimal default constructor called" << RESET << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& src){
    this->type = src.type;
    std::cout << CYAN <<"WrongAnimal copy constructor called" << RESET<< std::endl;
}
WrongAnimal::~WrongAnimal(){
    std::cout << CYAN <<"WrongAnimal destructor called" << RESET<< std::endl;
}

//OPERATORS
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src){
    this->type = src.type;
    std::cout << CYAN <<"WrongAnimal equal operator called" << RESET<< std::endl;
    return (*this);
}

//FUNCTIONS
void WrongAnimal::makeSound() const{
    std::cout << CYAN <<"This is sound of a wrong animal" << RESET<< std::endl;
}

//SETTERS/GETTERS
std::string WrongAnimal::getType() const{
    return(this->type);
}