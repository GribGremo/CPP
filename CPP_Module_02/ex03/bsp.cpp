/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:05:57 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/22 21:26:59 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){
    
    Fixed rate(0.5f);
    Fixed abp(rate * ((a.get_x() * (b.get_y() - point.get_y())) + (b.get_x() * (a.get_y() - point.get_y()) + (point.get_x() * (a.get_y() - b.get_y())))));    
    Fixed apc(rate * ((a.get_x() * (point.get_y() - c.get_y())) + (point.get_x() * (a.get_y() - c.get_y()) + (c.get_x() * (a.get_y() - point.get_y())))));    
    Fixed pbc(rate * ((point.get_x() * (b.get_y() - c.get_y())) + (b.get_x() * (point.get_y() - c.get_y()) + (c.get_x() * (point.get_y() - b.get_y())))));        
    Fixed abc(rate * ((a.get_x() * (b.get_y() - c.get_y())) + (b.get_x() * (a.get_y() - c.get_y()) + (c.get_x() * (a.get_y() - b.get_y())))));
    if (abp.toFloat() < 0)
        abp.setRawBits(abp.getRawBits() * -1);
    if (apc.toFloat() < 0)
        apc.setRawBits(apc.getRawBits() * -1);
    if (pbc.toFloat() < 0)
        pbc.setRawBits(pbc.getRawBits() * -1);
    if (abc.toFloat() < 0)
        abc.setRawBits(abc.getRawBits() * -1);
    if (abp.toFloat() == 0)
        return (false);
    if (apc.toFloat() == 0)
        return (false);
    if (pbc.toFloat() == 0)
        return (false);
    if (abc.toFloat() == 0)
        return (false);
    std::cout << abc.toFloat();
    if (abc != abp + apc + pbc)
        return (false);
    else
        return (true);
}

// Fixed triangle_area(Point& const a, Point& const b, Point& const c){
//     Fixed rate(0.5f);
//     Fixed area(rate * ((a.get_x() * (b.get_y() - c.get_y())) + (b.get_x() * (a.get_y() - c.get_y()) + (c.get_x() * (a.get_y() - b.get_y())))));
//     return (area);
// }