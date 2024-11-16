/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:01:53 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 12:55:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string str("Thomas");
    Zombie *one = newZombie(NULL);
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
    Zombie *four = newZombie(str);
    if(four == NULL)
    {
        std::cout << "Memory allocation issue";
        return (1);
    }
    randomChump("Douglas");
    randomChump("Steven");
    randomChump("");
    randomChump(NULL);
    
    delete(one);
    delete(two);
    delete(three);
    delete(four);
}

