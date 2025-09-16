/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:10:21 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/15 10:47:18 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
const T&   max(const T& x,const T& y){
    if (x > y)
        return (x);
    else if (x < y)
        return (y);
    else
        return (y);
}

template <typename T>
const T&   min(const T& x,const T& y){
    if (x > y)
        return (y);
    else if (x < y)
        return (x);
    else
        return (y);
}

template <typename T>
void   swap(T& x,T& y){
    T temp;
    temp = x;
    x = y;
    y = temp;
}