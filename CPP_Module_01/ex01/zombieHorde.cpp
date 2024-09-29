/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:36:27 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/19 16:56:39 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    if (name.empty())
        name = "Greg";
    if (N < 0){
        std::cout << "Invalid number of Zombies" << std::endl;
        return NULL;
    }
    Zombie *horde = new Zombie[N];
    
    for(int i = 0; i < N; i++)
    {
        horde[i].set_name(name);
        horde[i].announce();
    }
    return (horde);
}