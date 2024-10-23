/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/22 20:56:01 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
    public:
    Point();
    Point(float x,float y);
    Point(Point& org);
    Point& operator=(Point& org);
    ~Point();

    Fixed get_x(void) const;
    Fixed get_y(void) const;

    private:
        const Fixed x;
        const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif