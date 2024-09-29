/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:01:53 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/19 13:26:44 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *one = newZombie("Baptiste");
    if(one == NULL)
    {
        std::cout << "Memory allocation issue";
        return (1);
    }
    Zombie *two = newZombie("Quentin");
    if(two == NULL)
    {
        std::cout << "Memory allocation issue";
        return (1);
    }
    Zombie *three = newZombie("");
    if(three == NULL)
    {
        std::cout << "Memory allocation issue";
        return (1);
    }
    randomChump("Douglas");
    randomChump("Steven");
    randomChump("");
    
    delete(one);
    delete(two);
    delete(three);
}

