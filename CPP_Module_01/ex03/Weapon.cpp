/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:28:41 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 15:27:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

 ////////////CONSTRUCTORS////////////
    Weapon::Weapon() : _type("Default"){
        std::cout << "Weapon default constructor called" <<std::endl;
    }
    Weapon::Weapon(const std::string& type) : _type(type){
        std::cout << "Weapon custom constructor called" <<std::endl;
    }
    Weapon::~Weapon(void){
        std::cout << "Weapon default destructor called" <<std::endl;
    }
    
////////////SETTERS////////////

    const   std::string&    Weapon::getType(void){
        const std::string &type = _type;
        return(type);
    }

    void    Weapon::setType(const std::string& type){
        _type = type;
    }