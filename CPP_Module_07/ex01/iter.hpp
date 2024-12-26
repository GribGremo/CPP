/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:02:46 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/26 10:58:36 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename A, typename L, typename F>
void    iter(A* address, const L& length, F fn){
    if (address == NULL)
    {
        std::cout << "address is NULL" << std::endl;
        return ;
    }
    for (L i = 0; i < length; i++){
        fn(address[i]);
    }
}

template<typename T>
void  incr(T& value){
    value++;
}

template<typename T>
void  square(T& value){
    value = value * value;
}