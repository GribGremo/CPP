/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:36:27 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 14:27:43 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    if (name.empty())
        name = "Greg";
    if (N <= 0){
        std::cout << "Invalid number of Zombies" << std::endl;
        return NULL;
    }
    
    Zombie* horde = NULL;
    try {
        horde = new Zombie[N];
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "bad_alloc caught: " << e.what() << std::endl;
        return NULL;
    }
    
    for(int i = 0; i < N; i++)
    {
        horde[i].set_name(name);
    }
    return (horde);
}

Zombie* zombieHorde( int N, const char* name ){
    if (name == NULL)
        return(zombieHorde(N, "Damien"));
    else{
        std::string str(name);
        return(zombieHorde(N, str));
    }
}