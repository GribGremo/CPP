/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/23 17:43:33 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//CONSTRUCTORS

ClapTrap::ClapTrap(){
    std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap& src){
    std::cout << "ClapTrap custom constructor called" << std::endl;

}
ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;

}

//OPERATORS

ClapTrap& ClapTrap::operator=(ClapTrap& src){

}

//FUNCTIONS

void ClapTrap::attack(const std::string& target){
    std::cout << "*Vlan...Zooom..Zbriitt* Clap is not made for battle, 0 damages dealt" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
    _hit_points -= amount;
    if(_hit_points < 0)
        _hit_points = 0;
    if(_hit_points > 0 && _energy_points > 0)
        std::cout << "*Plong..Crouic..* Clap took " << amount << " damages" << std::endl;
    else if()
        std::cout << "*Plong..Crouic..* Clap took " << amount << " damages, he is done" << std::endl;
    
}
void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap constructor called" << std::endl;
}