/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:10:21 by sylabbe           #+#    #+#             */
/*   Updated: 2025/01/21 14:34:22 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
const T&   max(const T& x,const T& y){
    return (x > y ? x : y);
}

template <typename T>
const T&   min(const T& x,const T& y){
    return (x < y ? x : y);
}

template <typename T>
void   swap(T& x,T& y){
    T temp;
    temp = x;
    x = y;
    y = temp;
}