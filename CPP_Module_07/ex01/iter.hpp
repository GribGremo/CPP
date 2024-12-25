/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:02:46 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/25 23:42:12 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename A, typename L, typename F>
void    iter(A& address, const L& length, F fn){
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