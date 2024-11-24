/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:05 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/24 14:49:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//CONSTRUCTORS

Point::Point(): x(0), y(0){
    std::cerr << "Point default constructor called" << std::endl;
}
Point::Point(float x,float y):x(x), y(y){
    std::cerr << "Point custom constructor called" << std::endl;
}
Point::Point(Point& org):x(org.x), y(org.y){
    std::cerr << "Point copy constructor called" << std::endl;
}
Point::~Point(){
    std::cerr << "Point destructor called" << std::endl;
}

//OPERATORS

Point& Point::operator=(Point& org){
    std::cerr << "Point assigment operator called" << std::endl;
    (void) org;
    return (*this);
}

//GETTERS/SETTERS

Fixed Point::get_x(void) const{
    return(x);
}
Fixed Point::get_y(void) const{
    return(y);
}