/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:26:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/26 12:47:35 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, FragTrap
{
    public:

    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap& src);
    ~DiamondTrap();

    void whoAmI();
    
    private:
    std::string name = "_name";
};

#endif