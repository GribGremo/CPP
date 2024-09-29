/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:27:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/28 16:56:00 by sylabbe          ###   ########.fr       */
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

    HumanA ted(ref_sword, "Ted");
    HumanB bob("Bob");
    bob.setWeapon(ptr_machine_gun);
    HumanB bruce;

    ted.attack();
    sword.setType("wooden sword");
    bob.attack();
    machine_gun.setType("M61 Vulcan");
    bruce.attack();

    ted.attack();
    bob.attack();
    bruce.attack();

}