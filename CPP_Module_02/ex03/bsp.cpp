/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:05:57 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/22 17:35:30 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed total(triangle_area(a,b,c));
    if()
}

Fixed& triangle_area(Point const a, Point const b, Point const c){
    Fixed rate(0.5f);
    Fixed area(rate * ((a.get_x() * (b.get_y() - c.get_y())) + (b.get_x() * (a.get_y() - c.get_y()) + (c.get_x() * (a.get_y() - b.get_y())))));
    return (area);
}