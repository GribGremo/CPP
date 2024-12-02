/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:22 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/02 12:53:54 by sylabbe          ###   ########.fr       */
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
//It has no sense to make contructor by copy, we  won't be able to use it considering we can't instantiate AMateria.
AMateria::AMateria(const AMateria& src){
    std::cerr << GREEN <<"AMateria copy constructor called" << RESET<< std::endl;
    // this->type = src.type; While assigning a Materia to another, copying the type doesn’t make sense. If i use a AMateria pointer i could litterally make a ice materia become a cure materia, non-sense.
    // this->next = NULL;
    (void)src;
}
AMateria::~AMateria(){
    std::cerr << GREEN <<"AMateria destructor called" << RESET<< std::endl;
}

//OPERATOR
//We could use pointer and dereference it, but it wisely not recommended to do, we could make a partial copy of a derived object, which is not so good, could use '= delete' (c++11) or put them in protected so noone used it.
AMateria& AMateria::operator=(const AMateria& src){
    std::cerr << GREEN <<"AMateria assignment operator called" << RESET<< std::endl;

    // this->type = src.type; While assigning a Materia to another, copying the type doesn’t make sense. If i use a AMateria pointer i could litterally make a ice materia become a cure materia, non-sense.
    // this->next = NULL;
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



