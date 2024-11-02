/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:09 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/31 11:15:23 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
    titi.attack("papillon");
    titi.takeDamage(5);
    titi.beRepaired(0);
    titi.beRepaired(5);
    titi.takeDamage(10);
    titi.beRepaired(10);
    titi.attack("chenille");
    titi.takeDamage(5);
    titi.guardGate();

    std::cout << std::endl;
    std::string name3 = "tutu";
    FragTrap tutu(name3);
    tutu.attack("papillon");
    tutu.takeDamage(5);
    tutu.beRepaired(0);
    tutu.beRepaired(5);
    tutu.takeDamage(10);
    tutu.beRepaired(10);
    tutu.attack("chenille");
    tutu.takeDamage(5);
    tutu.highFivesGuys();

    std::cout << std::endl;
    std::string name4 = "tete";
    DiamondTrap tete(name4);
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.attack("papillon");
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.takeDamage(5);
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.beRepaired(0);
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.beRepaired(5);
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.takeDamage(10);
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.beRepaired(10);
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.attack("chenille");
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.takeDamage(5);
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.highFivesGuys();
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    tete.whoAmI();
    std::cout <<tete.getName() << " Attack: "<< tete.getAttackdmg()<< " Energy: " <<tete.getEnergypoints()<<" HP: "<<tete.getHitpoints() << std::endl;
    DiamondTrap cpy = tete;
    std::cout <<cpy.getName() << " Attack: "<< cpy.getAttackdmg()<< " Energy: " <<cpy.getEnergypoints()<<" HP: "<<cpy.getHitpoints() << std::endl;
    cpy.attack("tete");
}