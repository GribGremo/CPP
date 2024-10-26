/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:26:31 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/26 13:13:42 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Bryan",FragTrap::_hit_points,5,5), FragTrap(),ScavTrap(){

}
DiamondTrap::DiamondTrap(std::string name){

}
DiamondTrap::DiamondTrap(DiamondTrap& src){

}
DiamondTrap::~DiamondTrap(){

}

void DiamondTrap::whoAmI(){

}