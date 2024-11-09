/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:37:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/09 09:12:35 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//CONSTRUCTORS/DESTRUCTOR
Character::Character(){
    std::cout << "Character default constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
    name = "Default";
}
Character::Character(const std::string& name){
    std::cout << "Character custom constructor called" << std::endl;
    this->name = name;
    for(int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}
Character::Character(const Character& src){
    std::cout << "Character copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        inventory[i] = src.inventory[i];
    }
    name = src.name;
}
Character::~Character(){
    std::cout << "Character destructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
}

//OPERATORS
Character& Character::operator=(const Character& src){
    std::cout << "Character equal operator called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
        inventory[i] = src.inventory[i];
    }
    name = src.name;
    return (*this);
}

//GETTERS/SETTERS
std::string const & Character::getName() const{
    return (name);
}

//FUNCTIONS
void Character::equip(AMateria* m){
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << "Materia " << m->getType() << " type equipped at slot "<< i << " in the inventory of " << name << std::endl;
            return;
        }
    }
}
void Character::unequip(int idx){
    // ! Attention pense a sauvegarder ton pointeur de materia quelque part avant de mettre a null
    if (idx >=0 && idx < 4)
    {
        if (inventory[idx] != NULL)
        {
            inventory[idx] = NULL;
            std::cout << "Materia at slot " << idx << "("<< inventory[idx]->getType() << ") unequipped in the inventory of " << name << std::endl;
        }
        else
        std::cout << "No Materia at slot " << idx << " in the inventory of " << name << std::endl;
    }
    else
        std::cout << "No slot " << idx << " in the inventory of " << name << "(Max slot 4)"<< std::endl;
}
void Character::use(int idx, ICharacter& target){
    if (idx >=0 && idx < 4)
    {
        if (inventory[idx] != NULL)
            inventory[idx]->use(target);
        else
            std::cout << "No Materia at slot " << idx << " in the inventory of " << name << std::endl;
    }
    else
        std::cout << "No slot " << idx << " in the inventory of " << name << "(Max slot 4)"<< std::endl;
}