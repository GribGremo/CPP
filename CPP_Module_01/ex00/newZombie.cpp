/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:03:05 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/19 12:56:47 by sylabbe          ###   ########.fr       */
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
        return (NULL);//dans catch?
    }