/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:03:05 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 12:53:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    if(name.empty())
        name = "Greg";
    try
    {
        Zombie *zmb = new Zombie(name);
        return (zmb);
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught:" << ba.what() << std::endl;
    }
    return (NULL);
}

Zombie* newZombie( const char* name ){
    if (name == NULL)
        return (newZombie("Valentin"));
    else
    {
        std::string str(name);
        return (newZombie(str));
    }
}
