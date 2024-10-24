/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:08 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/24 16:48:36 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//CONSTRUCTORS

ScavTrap::ScavTrap() : ClapTrap("Bryan", 100, 50, 20){
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string& name) : ClapTrap(name, 100, 50, 20){
    std::cout << "ScavTrap custom constructor called" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap& src) : ClapTrap(src){
    std::cout << "ScavTrap constructor by copy called" << std::endl;
}
ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

//OPERATORS

// ScavTrap& ScavTrap::operator=(ScavTrap& src){
    
// }

//FUNCTIONS
void ScavTrap::guardGate(){
    std::cout << "Mwahaha, me the great " << this->getName() <<", i'm the cerberus of your hell, do not trespass me, or you're doomed" << std::endl;
}
void ScavTrap::attack(const std::string& target){
    std::cout << "Thank god i'm not as useless as my cousin. " << this->getName() << " dealt " << this->getAttackDmg() << " damages to " << target << std::endl;
}