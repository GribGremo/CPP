/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:25 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/17 16:41:00 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>

int main()
{
    std::vector<int> vec = {1,2,3};
    std::deque<int> dq = {4,5,6};
    std::list<int> lst = {7,8,9};

    printResult(vec,0);
    printResult(vec,1);
    printResult(vec,2);
    printResult(vec,3);
    printResult(vec,4);

    printResult(dq,3);
    printResult(dq,4);
    printResult(dq,5);
    printResult(dq,6);
    printResult(dq,7);

    printResult(lst,6);
    printResult(lst,7);
    printResult(lst,8);
    printResult(lst,9);
    printResult(lst,10);
}