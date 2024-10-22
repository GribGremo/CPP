/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:05 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/22 17:24:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//CONSTRUCTORS

Point::Point(): x(0), y(0){}
Point::Point(float x,float y):x(x), y(y){}
Point::Point(Point& org):x(org.x), y(org.y){}
Point::~Point(){}

//OPERATORS

Point& Point::operator=(Point& org){}

//GETTERS/SETTERS

Fixed Point::get_x(void) const{
    return(x);
}
Fixed Point::get_y(void) const{
    return(y);
}