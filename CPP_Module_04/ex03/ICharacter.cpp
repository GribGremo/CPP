/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:20:35 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/06 13:00:46 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

//CONSTRUCTORS/DESTRUCTOR
ICharacter::ICharacter(){
    std::cout << "ICharacter default constructor called" << std::endl;
    name = "Default";
}
ICharacter::ICharacter(const ICharacter& src){
    std::cout << "ICharacter copy constructor called" << std::endl;

}
ICharacter::~ICharacter(){
    std::cout << "ICharacter destructor called" << std::endl;
}

//OPERATORS
ICharacter& ICharacter::operator=(const ICharacter& src){
    std::cout << "ICharacter equal operator called" << std::endl;
    name = src.name;
    return (*this);
}

