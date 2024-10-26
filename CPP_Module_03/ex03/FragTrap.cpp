/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:58:21 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/25 21:06:45 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//CONSTRUCTORS

FragTrap::FragTrap() : ClapTrap("Bryan", 100, 100, 30){
    std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30){
    std::cout << "FragTrap custom constructor called" << std::endl;
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