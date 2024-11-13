/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:55 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/13 16:34:37 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//CONSTRUCTORS/DESTRUCTOR
Ice::Ice(){
    std::cout << "Ice default constructor called" << std::endl;
    type = "ice";
}
Ice::Ice(const Ice& src){
    std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
}
Ice::~Ice(){
    std::cout << "Ice destructor called" << std::endl;
}

//OPERATORS While assigning a Materia to another, copying the type doesn’t make sense.
Ice& Ice::operator=(const Ice& src){
    std::cout << "Ice default constructor called" << std::endl;
    if (this != &src)
    {
        type = src.type;
        next = NULL;//I chose to isolate my node this way, i don't intend to copy a full list of materia
    }
    return (*this);
}

//FUNCTIONS
AMateria* Ice::clone() const{
    AMateria* m = new Ice(*this);//
    return m;
}
void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}