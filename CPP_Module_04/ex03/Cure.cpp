/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:48:03 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/02 14:42:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR
Cure::Cure(){
    std::cerr << MAGENTA << "Cure default constructor called" << RESET << std::endl;
    type = "cure";
}
Cure::Cure(const Cure& src){
    std::cerr << MAGENTA <<"Cure copy constructor called" << RESET<< std::endl;
    this->type = src.type;
    this->next = NULL;
}
//Careful, we  need to set-up type for constructor by copy cause we can attribute it to a AMateria* who has type set-up as default

Cure::~Cure(){
    std::cerr << MAGENTA <<"Cure destructor called" << RESET<< std::endl;
}

//OPERATORS 
Cure& Cure::operator=(const Cure& src){
    std::cerr << MAGENTA <<"Cure assignment operator called" << RESET<< std::endl;
    if (this != &src)
    {
        // type = src.type;
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
    std::cout << MAGENTA <<"* heals " << target.getName() << "’s wounds *" << RESET<< std::endl;
}