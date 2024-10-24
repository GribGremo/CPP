/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/24 15:40:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//CONSTRUCTORS

ClapTrap::ClapTrap(): _name("Bryan"),_hit_points(10),_energy_points(10),_attack_dmg(0){
    std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string& name):_name(name),_hit_points(10),_energy_points(10),_attack_dmg(0){
    std::cout << "ClapTrap default constructor called" << std::endl;
    _name = name;
}
ClapTrap::ClapTrap(ClapTrap& src):_name(src._name),_hit_points(src._hit_points),_energy_points(src._energy_points),_attack_dmg(src._attack_dmg){
    std::cout << "ClapTrap custom constructor called" << std::endl;
}
ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_dmg) : _name(name),_hit_points(hit_points),_energy_points(energy_points),_attack_dmg(attack_dmg){
    std::cout << "ClapTrap derived custom constructor called" << std::endl;
}

//OPERATORS

ClapTrap& ClapTrap::operator=(ClapTrap& src){
    _name = src._name;
    _hit_points = src._hit_points;
    _energy_points = src._energy_points;
    _attack_dmg = src._attack_dmg;
    return (*this);
}
//SETTERS/GETTERS

std::string ClapTrap::getName(){
    return (_name);
}
int ClapTrap::getAttackDmg(){
    return (_attack_dmg);
}



//FUNCTIONS

void ClapTrap::attack(const std::string& target){
    if(_energy_points <= 0 || _hit_points <=0)
        std::cout << "What did you expect, Clap " << _name << " is cooked, he won't make more damages now." << std::endl;
    else
    {
        std::cout << "KAMEHAAAAA.... hum kidding, Clap " << _name << " make "<< _attack_dmg << " damages to " << target << std::endl;
        _energy_points--;
    }
}
void ClapTrap::takeDamage(unsigned int amount){
    if (_hit_points <= 0 || _energy_points <= 0)
        std::cout << "*No sound from Clap " << _name << ", he is already dowm and a monster keep beating him*" << std::endl;
    else
    {
        _hit_points -= amount;
        if(_hit_points < 0)
            _hit_points = 0;
        if(_hit_points > 0)
            std::cout << "*Plong..Crouic..* Clap " << _name << " took " << amount << " damages, still standing on his... whatever." << std::endl;
        else
            std::cout << "*Plong..Crouic..* Clap " << _name << " took " << amount << " damages, he is done." << std::endl;
    }
    
}
void ClapTrap::beRepaired(unsigned int amount){
    if(_energy_points <= 0 || _hit_points <=0)
        std::cout << "Well this time it's over, no more repairs, Clap " << _name << " is f*** up." << std::endl;
    else
    {
        if (amount == 0)
            std::cout << "Well, Clap " << _name << " is not even good at mechanics, he repairs nothing." << std::endl;
        else
            std::cout << "Clap " << _name << " tried his best to keep accomplishing his duty, he repairs by " << amount << " points." << std::endl;
        _energy_points--;
    }
}