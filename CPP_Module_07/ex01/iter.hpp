/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:02:46 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/15 14:31:25 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename A, typename L, typename F>
void    iter(A* address, const L& length, F fn){
    if (address == NULL || length < 0)
    {
        std::cout << "Invalid arguments" << std::endl;
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

template<typename T>
void  printCell(const T& value){
    std::cout << value << std::endl;
}