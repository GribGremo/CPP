/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:55 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/06 12:42:19 by sylabbe          ###   ########.fr       */
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