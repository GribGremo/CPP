/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:55 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/02 14:36:30 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#define CYAN    "\033[36m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR
Ice::Ice(){
    std::cerr << CYAN << "Ice default constructor called" << RESET << std::endl;
    type = "ice";
}
Ice::Ice(const Ice& src){
    std::cerr << CYAN << "Ice copy constructor called" << RESET << std::endl;
    this->type = src.type;
    this->next = NULL;
}
//Careful, we  need to set-up type for constructor by copy cause we can attribute it to a AMateria* who has type set-up as default
Ice::~Ice(){
    std::cerr << CYAN << "Ice destructor called" << RESET << std::endl;
}

//OPERATORS While assigning a Materia to another, copying the type doesn’t make sense.
Ice& Ice::operator=(const Ice& src){
    std::cerr << CYAN << "Ice default constructor called" << RESET << std::endl;
    if (this != &src)
    {
        // type = src.type;
        next = NULL;
    }
    return (*this);
}

//FUNCTIONS
AMateria* Ice::clone() const{
    AMateria* m = new Ice(*this);//
    return m;
}
void Ice::use(ICharacter& target){
    std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}