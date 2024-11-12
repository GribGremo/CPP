/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:22 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/12 13:25:10 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//CONSTRUCTORS/DESTRUCTOR

AMateria::AMateria() : type("Default"), next(NULL){
    std::cout << "AMateria default constructor called" << std::endl;
}
AMateria::AMateria(std::string const& type):type(type),next(NULL){
    std::cout << "AMateria custom constructor called" << std::endl;
}
AMateria::AMateria(const AMateria& src){
    std::cout << "AMateria copy constructor called" << std::endl;
    (void)src;
}
AMateria::~AMateria(){
    std::cout << "AMateria destructor called" << std::endl;
}

//OPERATOR

AMateria& AMateria::operator=(const AMateria& src){
    (void)src;
    return(*this);
}

//GETTERS/SETTERS

std::string const & AMateria::getType() const{
    return(type);
}
AMateria* AMateria::getNext() const{
    return (next);
}
void AMateria::setNext(AMateria* m){
    this->next = m;
}

//FUCNTIONS
void AMateria::use(ICharacter& target){
    (void)target;
}



