/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:58:21 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/29 15:25:01 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//CONSTRUCTORS

FragTrap::FragTrap() : ClapTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_name = "Default";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_dmg = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(){
    std::cout << "FragTrap custom constructor called" << std::endl;
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_dmg = 30;
}
FragTrap::FragTrap(FragTrap& src) : ClapTrap(src){
    std::cout << "FragTrap constructor by copy called" << std::endl;
}
FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

//OPERATORS

FragTrap& FragTrap::operator=(FragTrap& src){
    this->setAttackdmg(src.getAttackdmg());
    this->setEnergypoints(src.getEnergypoints());
    this->setHitpoints(src.getHitpoints());
    this->setName(src.getName());
}

//FUNCTIONS

void FragTrap::highFivesGuys(void){
    std::cout << "Hey Guys!!! friendly! "<< this->getName() << " requested a friendly gesture, not sure anyone is in the mood." << std::endl;
}