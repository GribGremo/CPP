/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:28:41 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/28 11:04:09 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

 ////////////CONSTRUCTORS////////////
    Weapon::Weapon() : _type(""){
        std::cout << "Weapon default constructor called" <<std::endl;
    }
    Weapon::Weapon(std::string type) : _type(type){
        std::cout << "Weapon custom constructor called" <<std::endl;
    }
    Weapon::~Weapon(void){
        std::cout << "Weapon default destructor called" <<std::endl;
    }
    
    ////////////FUNCTIONS////////////
    // void Weapon::announce( void ){
    //     std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    // } 

    ////////////SETTERS////////////

    const   std::string    &Weapon::getType(void){
        const std::string &type = _type;
        return(type);
    }

    void    Weapon::setType(std::string type){
        _type = type;
    }