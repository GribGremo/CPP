/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:25 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/27 09:56:34 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>

int main()
{
    std::vector<int> vec;
    for (int i = 1; i <= 3;i++)
        vec.push_back(i);
    std::deque<int> dq;
    for (int i = 4; i <= 6;i++)
        dq.push_back(i);
    std::list<int> lst;
    for (int i = 7; i <= 9;i++)
        lst.push_back(i);
    
    std::cout << "TEST VECTOR:" << std::endl;
    printResult(vec,0);
    printResult(vec,1);
    printResult(vec,2);
    printResult(vec,3);
    printResult(vec,4);
    std::cout << std::endl;

    std::cout << "TEST DEQUE:" << std::endl;
    printResult(dq,3);
    printResult(dq,4);
    printResult(dq,5);
    printResult(dq,6);
    printResult(dq,7);
    std::cout << std::endl;

    std::cout << "TEST LIST:" << std::endl;
    printResult(lst,6);
    printResult(lst,7);
    printResult(lst,8);
    printResult(lst,9);
    printResult(lst,10);
}