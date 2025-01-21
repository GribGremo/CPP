/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:25 by sylabbe           #+#    #+#             */
/*   Updated: 2025/01/21 16:43:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

int main()
{
    std::vector<int> vec = {1,2,3};
    std::deque<int> dq = {4,5,6};
    std::list<int> lst = {7,8,9};


    easyfind(vec,1);
    easyfind(dq,5);
    easyfind(lst,9);
    
    easyfind(vec,4);
    

}