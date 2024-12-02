/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:37:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/30 14:03:02 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

//STATIC
Ground_List* Character::ground = NULL;
int Character::countCharacter = 0;

//CONSTRUCTORS/DESTRUCTOR
Character::Character(){
    std::cerr << YELLOW << "Character default constructor called" << RESET << std::endl;
    if (Character::ground == NULL)
        Character::ground = new Ground_List();
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    name = "Default";
    Character::countCharacter++;
}
Character::Character(const std::string& name){
    std::cerr << YELLOW << "Character custom constructor called" << RESET << std::endl;
    if (Character::ground == NULL)
        Character::ground = new Ground_List();
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    this->name = name;
    Character::countCharacter++;
}
Character::Character(const Character& src){
    std::cerr << YELLOW << "Character copy constructor called" << RESET << std::endl;
    if (Character::ground == NULL)
        Character::ground = new Ground_List();
    for(int i = 0; i < 4; i++)
    {
        if (src.inventory[i] != NULL)
            this->inventory[i] = src.inventory[i]->clone();
        else    
            this->inventory[i] = NULL;
    }
    name = src.name;
    Character::countCharacter++;
}
Character::~Character(){
    std::cerr << YELLOW << "Character destructor called" << RESET << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
    Character::countCharacter--;
    if (Character::countCharacter == 0 && Character::ground != NULL)
    {
        delete Character::ground;
        Character::ground = NULL;
    }
}

//OPERATORS
Character& Character::operator=(const Character& src){
    std::cerr << YELLOW << "Character equal operator called" << RESET << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
        if (src.inventory[i] != NULL)
            this->inventory[i] = src.inventory[i]->clone();
        else    
            this->inventory[i] = NULL;
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
    if (m == NULL)
    {
        std::cout << YELLOW << "Entry 'm' is NULL, no actions made on "<< name << "'s inventory" << RESET << std::endl;
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << YELLOW << "Materia " << m->getType() << " type equipped at slot "<< i << " in the inventory of " << name << RESET << std::endl;
            return;
        }
    }
    std::cout << YELLOW << "No empty slot in the inventory of " << name << "(Max slot 4)"<< RESET << std::endl;
}
void Character::unequip(int idx){
    if (idx >=0 && idx < 4)
    {
        if (inventory[idx] != NULL)
        {
            ground->push(inventory[idx]);
            std::cout << YELLOW << "Materia at slot " << idx << "("<< inventory[idx]->getType() << ") unequipped in the inventory of " << name << RESET << std::endl;
            inventory[idx] = NULL;
        }
        else
        std::cout << YELLOW << "No Materia at slot " << idx << " in the inventory of " << name << RESET << std::endl;
    }
    else
        std::cout << YELLOW << "No slot " << idx << " in the inventory of " << name << "(Max slot 4)"<< RESET << std::endl;
}
void Character::use(int idx, ICharacter& target){
    if (idx >=0 && idx < 4)
    {
        if (inventory[idx] != NULL)
            inventory[idx]->use(target);
        else
            std::cout << YELLOW << "No Materia at slot " << idx << " in the inventory of " << name << RESET << std::endl;
    }
    else
        std::cout << YELLOW << "No slot " << idx << " in the inventory of " << name << "(Max slot 4)"<< RESET << std::endl;
}

void Character::print_inventory(){
    std::cout << YELLOW<< "~~~~~~~~INVENTORY~~~~~~~~" << RESET<< std::endl;
    std::cout << YELLOW<< "Character: " << this->name << RESET<< std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            std::cout << YELLOW<< "Slot " << i << ": " << inventory[i]->getType() << RESET<< std::endl;
        else
            std::cout << YELLOW<< "Slot " << i << ": empty" << RESET<< std::endl;
    }
    std::cout << YELLOW<< "~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET<< std::endl;
}