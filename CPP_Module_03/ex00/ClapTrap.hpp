/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/23 16:59:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class ClapTrap{
    public:
    ClapTrap();
    ClapTrap(ClapTrap& src);
    ~ClapTrap();

    ClapTrap& operator=(ClapTrap& src);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    private:
    std::string _name;
    int _hit_points = 10;
    int _energy_points = 10;
    int _attack_dmg = 0;
};
#endif