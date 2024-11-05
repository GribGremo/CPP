/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:37:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/05 17:45:46 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//CONSTRUCTORS/DESTRUCTOR
Character::Character(){

}
Character::Character(const Character& src){

}
Character::~Character(){

}

//OPERATORS
Character& Character::operator=(const Character& src){

}

//GETTERS/SETTERS
std::string const & Character::getName() const{

}

//FUNCTIONS
void Character::equip(AMateria* m){

}
void Character::unequip(int idx){

}
void Character::use(int idx, ICharacter& target){

}