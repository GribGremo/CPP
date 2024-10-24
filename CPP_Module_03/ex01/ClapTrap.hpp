/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/24 15:40:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class ClapTrap{
    public:
    ClapTrap();
    ClapTrap(std::string& name);
    ClapTrap(ClapTrap& src);
    ~ClapTrap();

    ClapTrap& operator=(ClapTrap& src);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName();
    int getAttackDmg();


    protected:
    ClapTrap(std::string name, int hit_points, int energy_points, int attack_dmg);

    
    private:
    std::string _name;
    int _hit_points;
    int _energy_points;
    int _attack_dmg;
};
#endif