/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:03:08 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 12:55:29 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name ){
    if(name.empty())
        name = "Tolkien";
    Zombie zmb(name);
}

void randomChump( const char* name ){
    if (name == NULL)
        return (randomChump("Brigitte"));
    else
    {
        std::string str(name);
        return (randomChump(str));
    }
}
