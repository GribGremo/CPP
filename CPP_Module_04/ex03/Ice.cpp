/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:55 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/05 18:23:08 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//CONSTRUCTORS/DESTRUCTOR
Ice::Ice(){
    std::cout << "Ice default constructor called" << std::endl;

}
Ice::Ice(const Ice& src){
    std::cout << "Ice default constructor called" << std::endl;

}
Ice::~Ice(){
    std::cout << "Ice default constructor called" << std::endl;

}

//OPERATORS
Ice& Ice::operator=(const Ice& src){
    std::cout << "Ice default constructor called" << std::endl;

}


//FUNCTIONS
AMateria* Ice::clone() const{
    AMateria* m = new Ice();
}
void Ice::use(ICharacter& target){
    std::cout << "Ice default constructor called" << std::endl;

}