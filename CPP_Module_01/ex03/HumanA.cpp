/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:28:47 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/28 15:36:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

////////////CONSTRUCTORS////////////
    HumanA::HumanA(Weapon &weapon, std::string name) : _weapon(weapon), _name(name){
        std::cout << "HumanA custom constructor called" <<std::endl;
    }
    HumanA::~HumanA(void){
        std::cout << "HumanA default destructor called" <<std::endl;
    }
    
    ////////////FUNCTIONS////////////
    // void Weapon::announce( void ){
    //     std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    // } 

    ////////////SETTERS////////////
    void HumanA::attack(void)const{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
    }
