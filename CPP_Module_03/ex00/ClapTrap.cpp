/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/25 13:40:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

//CONSTRUCTORS

ClapTrap::ClapTrap(): _name("Bryan"),_hit_points(10),_energy_points(10),_attack_dmg(0){
    std::cerr << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
}
ClapTrap::ClapTrap(const std::string& name):_name(name),_hit_points(10),_energy_points(10),_attack_dmg(0){
    std::cerr << GREEN << "ClapTrap custom constructor called" << RESET<< std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& src):_name(src._name),_hit_points(src._hit_points),_energy_points(src._energy_points),_attack_dmg(src._attack_dmg){
    std::cerr << GREEN << "ClapTrap copy constructor called" << RESET<< std::endl;
}
ClapTrap::~ClapTrap(){
    std::cerr << GREEN << "ClapTrap destructor called" << RESET<< std::endl;
}

//OPERATORS

ClapTrap& ClapTrap::operator=(const ClapTrap& src){
    _name = src._name;
    _hit_points = src._hit_points;
    _energy_points = src._energy_points;
    _attack_dmg = src._attack_dmg;
    return (*this);
}


//GETTERS/SETTERS

std::string ClapTrap::getName(){
    return(_name);
}
int ClapTrap::getHitpoints(){
    return(_hit_points);
}
int ClapTrap::getEnergypoints(){
    return (_energy_points);
}
int ClapTrap::getAttackdmg(){
    return (_attack_dmg);
}

void ClapTrap::setName(std::string name){
    _name = name;
}
void ClapTrap::setHitpoints(int hit_points){
    _hit_points = hit_points;
}
void ClapTrap::setEnergypoints(int energy_points){
    _energy_points= energy_points;
}
void ClapTrap::setAttackdmg(int attack_dmg){
    _attack_dmg = attack_dmg;
}

//FUNCTIONS

void ClapTrap::attack(const std::string& target){
    if(_energy_points <= 0 || _hit_points <=0)
        std::cout << GREEN<< "What did you expect, " << _name << " is cooked, he won't make more damages now."<< RESET << std::endl;
    else
    {
        std::cout << GREEN<< "KAMEHAAAAA.... hum kidding, " << _name << " make "<< _attack_dmg << " damages to " << target << RESET<< std::endl;
        _energy_points--;
    }
}
void ClapTrap::takeDamage(unsigned int amount){
    if (_hit_points <= 0 || _energy_points <= 0)
        std::cout<< GREEN << "*No sound from " << _name << ", he is already dowm and a monster keep beating him*" << RESET<< std::endl;
    else
    {
        _hit_points -= amount;
        if(_hit_points < 0)
            _hit_points = 0;
        if(_hit_points > 0)
            std::cout << GREEN<< "*Plong..Crouic..* " << _name << " took " << amount << " damages, still standing on his... whatever."<< RESET << std::endl;
        else
            std::cout << GREEN<< "*Plong..Crouic..* " << _name << " took " << amount << " damages, he is done." << RESET<< std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount){
    if(_energy_points <= 0 || _hit_points <=0)
        std::cout << GREEN<< "Well this time it's over, no more repairs, " << _name << " is f*** up." << RESET<< std::endl;
    else
    {
        if (amount == 0)
            std::cout << GREEN<< "Well, " << _name << " is not even good at mechanics, he repairs nothing." << RESET<< std::endl;
        else
            std::cout << GREEN<<  _name << " tried his best to keep accomplishing his duty, he repairs by " << amount << " points." << RESET<< std::endl;
        _energy_points--;
        _hit_points += amount;
    }
}