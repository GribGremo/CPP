/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:05:57 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/23 12:32:34 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Fixed triangle_area(Point const& a, Point const& b, Point const& c){
    Fixed rate(0.5f);

    Fixed area(rate * ((a.get_x() * (b.get_y() - c.get_y())) + (b.get_x() * (c.get_y() - a.get_y()) + (c.get_x() * (a.get_y() - b.get_y())))));
    if (area.toFloat() < 0)
        area.setRawBits(area.getRawBits() * -1);
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    
    Fixed rate(0.5f);
    Fixed abp(triangle_area(a,b,point));
    Fixed apc(triangle_area(a,c,point));
    Fixed pbc(triangle_area(c,b,point));
    Fixed abc(triangle_area(a,b,c));

    std::cout << "abc:" << abc.toFloat()<< "abp:" << abp.toFloat()<< "apc:" << apc.toFloat()<< "pbc:" << pbc.toFloat() << std::endl;
    if (abp.toFloat() == 0 || apc.toFloat() == 0 || pbc.toFloat() == 0 || abc.toFloat() == 0 || abc != abp + apc + pbc)
        return (false);
    else
        return (true);
}

