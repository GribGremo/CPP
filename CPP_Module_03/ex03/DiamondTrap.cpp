/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:26:31 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/31 10:09:14 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//CONSTRUCTORS

DiamondTrap::DiamondTrap(): ClapTrap(),ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "_name";
    ClapTrap::_name = "Default_clap_name";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_dmg = ScavTrap::_attack_dmg;
}
DiamondTrap::DiamondTrap( const std::string name): ClapTrap(),ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap custom constructor called" << std::endl;
    this->name = "_name";
    ClapTrap::_name = name + "_clap_name";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_dmg = ScavTrap::_attack_dmg;
}
DiamondTrap::DiamondTrap(const DiamondTrap& src){
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    this->name = "_name";
    *this = src;
}
DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called" << std::endl;
}

//OPERATORS
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src){
    this->name = "_name";
    ClapTrap::_name = src.ClapTrap::_name;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    this->_attack_dmg = src._attack_dmg;
    return (*this);
}

//FUNCTIONS

void DiamondTrap::whoAmI(){
    if (_energy_points <=0 || _hit_points <= 0)
        std::cout <<  this->name << " and " << this->_name << ", none of them could answer that question anymore." << std::endl;
    else 
    {
        std::cout << "Whhooo...oo aammmm iiiIII ?!? " << this->name << " or " << this->_name << "? Whoo..'s my mommyyyy?" << std::endl;
        _energy_points--;
    }
}

void DiamondTrap::attack(const std::string& target){    
    ScavTrap::attack(target);
}
