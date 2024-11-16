/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:35:29 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 14:32:23 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "CASE 1: NAME IS NULL"<<std::endl;
    Zombie *horde = zombieHorde( N, NULL);
    if(horde == NULL)
        return (1);
    for(int i = 0; i < N;i++)
        horde[i].announce();
    delete[] horde;
    std::cout << std::endl;
    
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "CASE 2: NAME IS EMPTY"<<std::endl;
    Zombie *horde2 = zombieHorde( N, "");
    if(horde2 == NULL)
        return (1);
    for(int i = 0; i < N;i++)
        horde2[i].announce();
    delete[] horde2;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "CASE 3: NAME IS DECLINED"<<std::endl;
    Zombie *horde3 = zombieHorde( N, "Jamal");
    if(horde3 == NULL)
        return (1);
    for(int i = 0; i < N;i++)
        horde3[i].announce();
    delete[] horde3;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "CASE 4: N IS INFERIOR TO ZERO"<<std::endl;
    Zombie *horde4 = zombieHorde( -10, "Jamal");
    if(horde4 == NULL)
        return (1);
    for(int i = 0; i < N;i++)
        horde4[i].announce();
    delete[] horde4;

}