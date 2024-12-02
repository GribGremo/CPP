/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:20:35 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/30 10:55:08 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#define BRIGHT_YELLOW "\033[93m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR
// ICharacter::ICharacter(){
//     std::cerr << BRIGHT_YELLOW << "ICharacter default constructor called" << RESET << std::endl;
//     name = "Default";
// }
// ICharacter::ICharacter(const ICharacter& src){
//     std::cerr << BRIGHT_YELLOW << "ICharacter copy constructor called" << RESET << std::endl;
//     *this = src;
// }
ICharacter::~ICharacter(){
    std::cerr << BRIGHT_YELLOW << "ICharacter destructor called" << RESET << std::endl;
}

//OPERATORS
// ICharacter& ICharacter::operator=(const ICharacter& src){
//     std::cerr << BRIGHT_YELLOW << "ICharacter equal operator called" << RESET << std::endl;
//     name = src.name;
//     return (*this);
// }

