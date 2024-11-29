/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:22 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/29 12:16:50 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR

AMateria::AMateria() : type("Default"), next(NULL){
    std::cerr << GREEN << "AMateria default constructor called" << RESET<< std::endl;
}
AMateria::AMateria(std::string const& type):type(type),next(NULL){
    std::cerr << GREEN <<"AMateria custom constructor called" << RESET<< std::endl;
}
AMateria::AMateria(const AMateria& src){
    std::cerr << GREEN <<"AMateria copy constructor called" << RESET<< std::endl;
    (void)src;
}
AMateria::~AMateria(){
    std::cerr << GREEN <<"AMateria destructor called" << RESET<< std::endl;
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



