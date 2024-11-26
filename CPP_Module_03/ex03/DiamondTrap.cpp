/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:26:31 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/26 13:34:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

//CONSTRUCTORS

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap() {
    std::cout << CYAN <<"DiamondTrap default constructor called" <<RESET<< std::endl;
    this->name = "_name";
    ClapTrap::_name = "Default_clap_name";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_dmg = 30;
}
DiamondTrap::DiamondTrap( const std::string name): ScavTrap(), FragTrap() {
    std::cout << CYAN <<"DiamondTrap custom constructor called" <<RESET<< std::endl;
    this->name = "_name";
    ClapTrap::_name = name + "_clap_name";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_dmg = 30;
}
DiamondTrap::DiamondTrap(const DiamondTrap& src){
    std::cout << CYAN <<"DiamondTrap copy constructor called" <<RESET<< std::endl;
    this->name = "_name";
    *this = src;
}
DiamondTrap::~DiamondTrap(){
    std::cout << CYAN <<"DiamondTrap destructor called" <<RESET<< std::endl;
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
        std::cout << CYAN << this->name << " and " << this->_name << ", none of them could answer that question anymore." <<RESET<< std::endl;
    else 
    {
        std::cout << CYAN <<"Whhooo...oo aammmm iiiIII ?!? " << this->name << " or " << this->_name << "? Whoo..'s my mommyyyy?" <<RESET<< std::endl;
        _energy_points--;
    }
}

void DiamondTrap::attack(const std::string& target){    
    ScavTrap::attack(target);
}
