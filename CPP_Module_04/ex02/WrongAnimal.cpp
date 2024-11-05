/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:22:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 11:46:37 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//CONSTRUCTORS
WrongAnimal::WrongAnimal(): type("Default"){
    std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& src){
    this->type = src.type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

//OPERATORS
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src){
    this->type = src.type;
    std::cout << "WrongAnimal equal operator called" << std::endl;
    return (*this);
}

//FUNCTIONS
void WrongAnimal::makeSound() const{
    std::cout << "This is the sound of a global animal: 'Meh'" << std::endl;
}

//SETTERS/GETTERS
std::string WrongAnimal::getType() const{
    return(this->type);
}