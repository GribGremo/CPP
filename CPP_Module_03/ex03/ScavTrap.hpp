/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:11 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/31 09:44:47 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ClapTrap;

class ScavTrap : virtual public ClapTrap
{
    public:
	ScavTrap();
	ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& src);
	~ScavTrap();

    ScavTrap& operator=(const ScavTrap& src);

    void guardGate();
    void attack(const std::string& target);
};

#endif