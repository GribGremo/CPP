/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:26:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/30 09:45:00 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:

    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap& src);
    ~DiamondTrap();

    DiamondTrap& operator=(DiamondTrap& src);

    void whoAmI();
    void attack(const std::string& target);

    private:
    std::string name;
};

#endif