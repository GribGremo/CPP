/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/22 17:24:33 by sylabbe          ###   ########.fr       */
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

#endif