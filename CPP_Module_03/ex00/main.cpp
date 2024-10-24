/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:09 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/23 21:47:31 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::string name = "toto";
    ClapTrap toto(name);
    toto.attack("papillon");
    toto.takeDamage(5);
    toto.beRepaired(0);
    toto.beRepaired(5);
    toto.takeDamage(10);
    toto.beRepaired(10);
    toto.attack("chenille");
    toto.takeDamage(5);
}