/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:27:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 15:37:08 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon sword("Zengetsu");
    Weapon &ref_sword = sword;
    Weapon machine_gun("Big Bertha");
    Weapon *ptr_machine_gun = &machine_gun;
    Weapon none;
    Weapon* ptr_none = &none;

    HumanA ted(ref_sword, "Ted");
    HumanB bob("Bob");
    bob.setWeapon(ptr_machine_gun);
    HumanB bruce;

    std::cout<<std::endl<<"CASE 1: FIRST WEAPON SET_UP"<<std::endl;
    std::cout<< "SWORD: " << sword.getType() <<std::endl;
    std::cout<< "MACHINE_GUN: " << machine_gun.getType() <<std::endl;


    ted.attack();
    sword.setType("wooden sword");
    bob.attack();
    machine_gun.setType("M61 Vulcan");
    bruce.attack();
    bruce.setWeapon(ptr_none);

    std::cout<<std::endl<<"CASE 2: SECOND WEAPON SET_UP"<<std::endl;
    std::cout<< "SWORD: " << sword.getType() <<std::endl;
    std::cout<< "MACHINE_GUN: " << machine_gun.getType() <<std::endl;
    std::cout<< "NONE: " << none.getType() <<std::endl;

    ted.attack();
    bob.attack();
    bruce.attack();
    std::cout<<std::endl;

}