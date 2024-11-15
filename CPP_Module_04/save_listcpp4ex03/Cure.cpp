/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:48:03 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/15 11:26:39 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//CONSTRUCTORS/DESTRUCTOR
Cure::Cure(){
    std::cout << "Cure default constructor called" << std::endl;
    type = "cure";
}
Cure::Cure(const Cure& src){
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
}
Cure::~Cure(){
    std::cout << "Cure destructor called" << std::endl;
}

//OPERATORS 
Cure& Cure::operator=(const Cure& src){
    std::cout << "Cure default constructor called" << std::endl;
    if (this != &src)
    {
        type = src.type;
        next = NULL;
    }
    return (*this);
}

//FUNCTIONS
AMateria* Cure::clone() const{
    AMateria* m = new Cure(*this);//
    return m;
}
void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}