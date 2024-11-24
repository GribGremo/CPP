/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:00 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/24 15:56:55 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

int main()
{
    std::cout << "~~~~~~~~~~~TEST_INSIDE~~~~~~~~~~~" << std::endl;
    Point a1(1,1);
    Point b1(1,4);
    Point c1(4,1);
    Point p1(2,2);
    if(bsp(a1,b1,c1,p1))
        std::cout << GREEN << "Point p is inside the triangle" << RESET <<std::endl;
    else
        std::cout << RED << "Point p is not inside the triangle" << RESET <<std::endl;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~TEST_OUTSIDE~~~~~~~~~~~" << std::endl;
    Point a(1,1);
    Point b(1,4);
    Point c(4,1);
    Point p(10,10);
    if(bsp(a,b,c,p))
        std::cout << GREEN << "Point p is inside the triangle" << RESET <<std::endl;
    else
        std::cout << RED << "Point p is not inside the triangle" << RESET <<std::endl;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~TEST_EDGE~~~~~~~~~~~" << std::endl;
    Point a2(1,1);
    Point b2(1,4);
    Point c2(4,1);
    Point p2(1,2);
    if(bsp(a2,b2,c2,p2))
        std::cout << GREEN << "Point p is inside the triangle" << RESET <<std::endl;
    else
        std::cout << RED << "Point p is not inside the triangle" << RESET <<std::endl;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~TEST_VERTEX~~~~~~~~~~~" << std::endl;
    Point a3(1,1);
    Point b3(1,4);
    Point c3(4,1);
    Point p3(1,1);
    if(bsp(a3,b3,c3,p3))
        std::cout << GREEN << "Point p is inside the triangle" << RESET <<std::endl;
    else
        std::cout << RED << "Point p is not inside the triangle" << RESET <<std::endl;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~TEST_NEGATIVE~~~~~~~~~~~" << std::endl;
    Point a4(-1,-1);
    Point b4(-1,-4);
    Point c4(-4,-1);
    Point p4(-2,-2);
    if(bsp(a4,b4,c4,p4))
        std::cout << GREEN << "Point p is inside the triangle" << RESET <<std::endl;
    else
        std::cout << RED << "Point p is not inside the triangle" << RESET <<std::endl;
    std::cout << std::endl;

        std::cout << "~~~~~~~~~~~TEST_FLOAT~~~~~~~~~~~" << std::endl;
    Point a5(-1.05f,-1.05f);
    Point b5(-1.05f,-4.05f);
    Point c5(-4.05f,-1.05f);
    Point p5(-2.05f,-2.05f);
    if(bsp(a5,b5,c5,p5))
        std::cout << GREEN << "Point p is inside the triangle" << RESET <<std::endl;
    else
        std::cout << RED << "Point p is not inside the triangle" << RESET <<std::endl;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~TEST_ZERO~~~~~~~~~~~" << std::endl;
    Point a6(0,0);
    Point b6(0,0);
    Point c6(0,0);
    Point p6(0,0);
    if(bsp(a6,b6,c6,p6))
        std::cout << GREEN << "Point p is inside the triangle" << RESET <<std::endl;
    else
        std::cout << RED << "Point p is not inside the triangle" << RESET <<std::endl;
    std::cout << std::endl;


}