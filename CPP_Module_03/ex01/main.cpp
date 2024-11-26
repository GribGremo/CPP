/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:09 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/26 15:55:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void main_test(ClapTrap* trap);


int main()
{
    ClapTrap ptr("Clap");
    ScavTrap ptr2("Scav");
    std::cout << std::endl;

    main_test(&ptr);
    std::cout <<std::endl<< ptr.getName() <<"'s Final Status" <<std::endl;
    std::cout <<ptr.getName() << " Attack: "<< ptr.getAttackdmg()<< " Energy: " <<ptr.getEnergypoints()<<" HP: "<<ptr.getHitpoints() << std::endl <<std::endl;

    main_test(&ptr2);
    std::cout << "Special function:" << std::endl;
    ptr2.guardGate();
    std::cout <<std::endl<< ptr.getName() <<"'s Final Status" <<std::endl;
    std::cout <<ptr2.getName() << " Attack: "<< ptr2.getAttackdmg()<< " Energy: " <<ptr2.getEnergypoints()<<" HP: "<<ptr2.getHitpoints() << std::endl<<std::endl;
}

void main_test(ClapTrap* trap)
{
    if (trap == NULL)
    {
        std::cout << "AHAH SUPER BLAGUE..." << std::endl;
        return ;
    }
    std::cout << "~~~~~~~~~~~~~~~" << trap->getName() << "'s history~~~~~~~~~~~~~~~" <<std::endl <<std::endl;
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->attack("papillon");
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->takeDamage(5);
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->beRepaired(0);
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->beRepaired(5);
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->takeDamage(10);
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->beRepaired(10);
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->attack("chenille");
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    trap->takeDamage(5);
    std::cout <<trap->getName() << " Attack: "<< trap->getAttackdmg()<< " Energy: " <<trap->getEnergypoints()<<" HP: "<<trap->getHitpoints() << std::endl;
    std::cout<<std::endl;
}