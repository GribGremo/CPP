/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:08 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/30 17:19:02 by sylabbe          ###   ########.fr       */
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
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(){
    std::cout << "ScavTrap custom constructor called" << std::endl;
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_dmg = 20;
}
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src){
    std::cout << "ScavTrap constructor by copy called" << std::endl;
}
ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

//OPERATORS

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
    _attack_dmg = src._attack_dmg;
    _energy_points = src._energy_points;
    _hit_points = src._hit_points;
    _name = src._name;
    return (*this);
}

//FUNCTIONS
void ScavTrap::guardGate(){
    if (_energy_points <= 0 || _hit_points <=0)
        std::cout <<  this->_name << " is done, can't guard anymore." << std::endl;
    else
    {
        std::cout << "Mwahaha, me the great " << this->getName() <<", i'm the cerberus of your hell, do not trespass me, or you're doomed, Gate Keeper Mode engaged" << std::endl;
        _energy_points--;
    }

}
void ScavTrap::attack(const std::string& target){
    if (_energy_points <= 0 || _hit_points <=0)
        std::cout <<  this->_name << " is done, can't atack anymore." << std::endl;
    else
    {
        std::cout << "Thank god i'm not as useless as my cousin. " << this->_name << " dealt " << this->_attack_dmg << " damages to " << target << std::endl;
        _energy_points--;
    }
}