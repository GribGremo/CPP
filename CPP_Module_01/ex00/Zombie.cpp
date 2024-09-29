/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:03:11 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/19 13:24:45 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

    ////////////CONSTRUCTORS////////////
    Zombie::Zombie() : _name(""){
        announce();
    }
    Zombie::Zombie(std::string name) : _name(name){
        announce();
    }
    Zombie::~Zombie(void){
        std::cout << "*Zombie " << _name << " took an arrow in the knee, then died*" << std::endl;
    }
    
    ////////////FUNCTIONS////////////
    void Zombie::announce( void ){
        std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    } 

