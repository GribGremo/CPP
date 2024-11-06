/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:22 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/06 14:10:55 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//CONSTRUCTORS/DESTRUCTOR

AMateria::AMateria() : type("Default"){
    std::cout << "AMateria default constructor called" << std::endl;
}
AMateria::AMateria(std::string const& type):type(type){
    std::cout << "AMateria custom constructor called" << std::endl;
}
AMateria::AMateria(const AMateria& src){
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}
AMateria::~AMateria(){
    std::cout << "AMateria destructor called" << std::endl;
}

//GETTERS/SETTERS

std::string const & AMateria::getType() const{
    return(type);
}

//OPERATORS

AMateria& AMateria::operator=(const AMateria& src){
    std::cout << "AMateria equal operator called" << std::endl;
    if (this != &src)
    {
        type = src.type;        
    }
    return (*this);
}

//FUNCTIONS

void AMateria::use(ICharacter& target){
    //
}



