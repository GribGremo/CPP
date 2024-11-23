/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:00 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/23 17:56:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    std::cout << std::endl;

    std::cout << "INCREMENTATION TESTS"<<std::endl;
    std::cout << "a before pre-incrementation:" <<std::endl;
    std::cout << a << std::endl;
    std::cout << "a during pre-incrementation:" <<std::endl;
    std::cout << ++a << std::endl;
    std::cout << "a after pre-incrementation:" <<std::endl;
    std::cout << a << std::endl;
    std::cout << "a during post-incrementation:" <<std::endl;
    std::cout << a++ << std::endl;
    std::cout << "a after post-incrementation:" <<std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl;

    std::cout << "DECREMENTATION TESTS"<<std::endl;
    std::cout << "a before pre-decrementation:" <<std::endl;
    std::cout << a << std::endl;
    std::cout << "a during pre-decrementation:" <<std::endl;
    std::cout << --a << std::endl;
    std::cout << "a after pre-decrementation:" <<std::endl;
    std::cout << a << std::endl;
    std::cout << "a during post-decrementation:" <<std::endl;
    std::cout << a-- << std::endl;
    std::cout << "a after post-decrementation:" <<std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl;

    std::cout << "OPERATION TESTS"<<std::endl;
    Fixed p1(5.05f);
    Fixed p2(2);
    Fixed res;
    std::cout << std::endl;

    res = p1 * p2;
    std::cout << "result of multiplaction:" <<std::endl;
    std::cout << p1 << " * " << p2 << " = "<< res << std::endl;
    std::cout << std::endl;

    res = p1 / p2;
    std::cout << "result of division:" <<std::endl;
    std::cout << p1 << " / " << p2 << " = "<<res << std::endl;
    std::cout << std::endl;

    res = p1 + p2;
    std::cout << "result of addition:" <<std::endl;
    std::cout << p1 << " + " << p2 << " = "<<res << std::endl;
    std::cout << std::endl;

    res = p1 - p2;
    std::cout << "result of substraction:" <<std::endl;
    std::cout << p1 << " - " << p2 << " = " <<res << std::endl;
    std::cout << std::endl;

    std::cout << "OPERATION TESTS"<<std::endl;
    std::cout << "result of max between a and res:" <<std::endl;
    std::cout << Fixed::max( a, res ) << std::endl;
    std::cout << std::endl;
    std::cout << "result of min between a and res:" <<std::endl;
    std::cout << Fixed::min( a, res ) << std::endl;
    std::cout << std::endl;

    return 0;
}