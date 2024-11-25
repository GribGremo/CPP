/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:09 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/25 10:22:17 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::string name1 = "toto";
    ClapTrap toto(name1);
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.attack("papillon");
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.takeDamage(5);
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.beRepaired(0);
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.beRepaired(5);
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.takeDamage(10);
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.beRepaired(10);
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.attack("chenille");
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    toto.takeDamage(5);
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    ClapTrap cpy = toto;
    std::cout <<toto.getName() << ": Attack "<< toto.getAttackdmg()<< " Energy "<<toto.getEnergypoints()<< " Health "<<toto.getHitpoints() << std::endl;
    cpy.attack("toto");
}