/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:08 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/26 10:52:46 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

//CONSTRUCTORS

ScavTrap::ScavTrap() : ClapTrap(){
    this->_name = "Default";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_dmg = 20;
    std::cout << YELLOW << "ScavTrap default constructor called"<< RESET << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_dmg = 20;
    std::cout << YELLOW << "ScavTrap custom constructor called" << RESET<< std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src){
    std::cout << YELLOW << "ScavTrap constructor by copy called" << RESET<< std::endl;
}
ScavTrap::~ScavTrap(){
    std::cout << YELLOW << "ScavTrap destructor called" << RESET<< std::endl;
}

//OPERATORS

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
    _attack_dmg=src._attack_dmg;
    _energy_points = src._energy_points;
    _hit_points = src._hit_points;
    _name = src._name;

    return (*this);
}

//FUNCTIONS
void ScavTrap::guardGate(){
    if (_energy_points <= 0 || _hit_points <= 0)
        std::cout<< YELLOW <<  this->_name << " is done, can't guard anymore." <<RESET<< std::endl;
    else
    {
        std::cout<< YELLOW << "Mwahaha, me the great " << this->getName() <<", i'm the cerberus of your hell, do not trespass me, or you're doomed, Gate Keeper Mode engaged" <<RESET<< std::endl;
        _energy_points--;
    }
}
void ScavTrap::attack(const std::string& target){
    if (_energy_points <= 0 || _hit_points <=0)
        std::cout<< YELLOW <<  this->_name << " is done, can't atack anymore." <<RESET<< std::endl;
    else
    {
        std::cout<< YELLOW << "Thank god i'm not as useless as my cousin. " << this->_name << " dealt " << this->_attack_dmg << " damages to " << target <<RESET<< std::endl;
        _energy_points--;
    }
}