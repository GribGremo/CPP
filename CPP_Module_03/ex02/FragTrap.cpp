/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:58:21 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/30 15:51:50 by sylabbe          ###   ########.fr       */
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
FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap custom constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_dmg = 30;
}
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src){
    std::cout << "FragTrap constructor by copy called" << std::endl;
}
FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

//OPERATORS

FragTrap& FragTrap::operator=(const FragTrap& src){
    _attack_dmg = src._attack_dmg;
    _energy_points = src._energy_points;
    _hit_points = src._hit_points;
    _name = src._name;
    return (*this);
}

//FUNCTIONS

void FragTrap::highFivesGuys(void){
    if (_hit_points <=0 || _energy_points <= 0)
        std::cout << _name << "is too tired to be friendly. " << std::endl;
    else
    {
        std::cout << "Hey Guys!!! friendly! "<< this->_name << " requested a friendly gesture, not sure anyone is in the mood." << std::endl;
        _energy_points--;
    }
}