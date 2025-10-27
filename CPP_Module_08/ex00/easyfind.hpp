/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:12 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/27 09:55:26 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& t, int n){
    return (std::find(t.begin(), t.end(), n)); 
}

template <typename T>
void printResult( T& c, int v){
    typename T::iterator it = easyfind(c,v);
    if( it != c.end())
        std::cout << "Find occurence of " << v << " at index " << std::distance(c.begin(), it) << std::endl;
    else
        std::cout << "No value " << v << " found" << std::endl;
}
