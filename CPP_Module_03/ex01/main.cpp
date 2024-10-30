/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:09 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/30 13:52:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::string name1 = "toto";
    ClapTrap toto(name1);
    toto.attack("papillon");
    toto.takeDamage(5);
    toto.beRepaired(0);
    toto.beRepaired(5);
    toto.takeDamage(10);
    toto.beRepaired(10);
    toto.attack("chenille");
    toto.takeDamage(5);
    std::cout << std::endl;

    std::string name2 = "titi";
    ScavTrap titi(name2);
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.attack("papillon");
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.takeDamage(5);
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.beRepaired(0);
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.beRepaired(5);
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.takeDamage(10);
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.beRepaired(10);
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.attack("chenille");
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.takeDamage(5);
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    titi.guardGate();
    std::cout <<titi.getName() << " Attack: "<< titi.getAttackdmg()<< " Energy: " <<titi.getEnergypoints()<<" HP: "<<titi.getHitpoints() << std::endl;
    ScavTrap cpy = titi;
    std::cout <<cpy.getName() << " Attack: "<< cpy.getAttackdmg()<< " Energy: " <<cpy.getEnergypoints()<<" HP: "<<cpy.getHitpoints() << std::endl;
    cpy.attack("titi");
}