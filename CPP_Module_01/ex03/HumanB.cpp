/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:26:22 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/28 16:55:06 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

////////////CONSTRUCTORS////////////
    HumanB::HumanB() :  _weapon(NULL), _name("Anonymous"){
        std::cout << "HumanB custom constructor called" <<std::endl;
    }
    HumanB::HumanB(std::string name) : _weapon(NULL), _name(name){
        std::cout << "HumanB custom constructor called" <<std::endl;
    }
    HumanB::~HumanB(void){
        std::cout << "HumanB default destructor called" <<std::endl;
    }
    
    ////////////FUNCTIONS////////////

    void HumanB::attack(void)const{
        if (_weapon)
            std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
        else
            std::cout << _name << " attacks with their hand" << std::endl;
    }

    void HumanB::setWeapon(Weapon *weapon){
        this->_weapon = weapon;
    }