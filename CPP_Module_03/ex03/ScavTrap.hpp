/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:11 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/26 13:09:39 by sylabbe          ###   ########.fr       */
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
	ScavTrap(std::string& name);
    ScavTrap(ScavTrap& src);
	~ScavTrap();

    void guardGate();
    void attack(const std::string& target);

    ScavTrap& operator=(ScavTrap& src);

    private:
    

};

#endif