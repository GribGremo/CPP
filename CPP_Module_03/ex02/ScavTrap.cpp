/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:08 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/29 15:29:02 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//CONSTRUCTORS

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->_name = "Default";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_dmg = 20;
}
ScavTrap::ScavTrap(std::string& name) : ClapTrap(){
    std::cout << "ScavTrap custom constructor called" << std::endl;
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_dmg = 20;
}
ScavTrap::ScavTrap(ScavTrap& src) : ClapTrap(src){
    std::cout << "ScavTrap constructor by copy called" << std::endl;
}
ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

//OPERATORS

ScavTrap& ScavTrap::operator=(ScavTrap& src){
    this->setAttackdmg(src.getAttackdmg());
    this->setEnergypoints(src.getEnergypoints());
    this->setHitpoints(src.getHitpoints());
    this->setName(src.getName());
}

//FUNCTIONS
void ScavTrap::guardGate(){
    std::cout << "Mwahaha, me the great " << this->getName() <<", i'm the cerberus of your hell, do not trespass me, or you're doomed" << std::endl;
}
void ScavTrap::attack(const std::string& target){
    std::cout << "Thank god i'm not as useless as my cousin. " << this->getName() << " dealt " << this->getAttackdmg() << " damages to " << target << std::endl;
}