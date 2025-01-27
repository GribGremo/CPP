/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:11 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/30 17:16:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ClapTrap;

class ScavTrap : public ClapTrap
{
    public:
	ScavTrap();
	ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& src);
	~ScavTrap();

    void guardGate();
    void attack(const std::string& target);
    
    ScavTrap& operator=(const ScavTrap& src);
};

#endif