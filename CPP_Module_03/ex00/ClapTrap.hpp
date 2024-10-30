/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/30 13:05:20 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class ClapTrap{
    public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& src);
    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& src);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName();
    int getHitpoints();
    int getEnergypoints();
    int getAttackdmg();

    void setName(std::string name);
    void setHitpoints(int hit_points);
    void setEnergypoints(int energy_points);
    void setAttackdmg(int attack_dmg);

    private:
    std::string _name;
    int _hit_points;
    int _energy_points;
    int _attack_dmg;
};
#endif