/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:00 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/24 16:10:49 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void print_color(Fixed msg, const char *clr);
void print_color(const std::string& msg, const char *clr);

int main( void ) {
    Fixed a;
    std::cout << std::endl;

    print_color("~~~~~~~~~~~SUBJECT TESTS~~~~~~~~~~~", GREEN);
    Fixed c;
    Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << c << std::endl;
    std::cout << ++c << std::endl;
    std::cout << c << std::endl;
    std::cout << c++ << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << Fixed::max( c, d ) << std::endl;
    std::cout << std::endl;

    print_color("~~~~~~~~~~~COMPARISON TESTS~~~~~~~~~~~", GREEN);
    Fixed e(4);
    Fixed f(5);
    Fixed g(5);
    print_color("superior to:", YELLOW);
    if (e > f)
        std::cout << MAGENTA << e << " > " << f << " = " << GREEN << "TRUE" << std::endl;
    else
        std::cout << MAGENTA << e << " > " << f << " = " << RED << "FALSE" << std::endl;
    print_color("inferior to:", YELLOW);   
    if (e < f)
        std::cout << MAGENTA << e << " < " << f << " = " << GREEN << "TRUE" << std::endl;
    else
        std::cout << MAGENTA << e << " < " << f << " = " << RED << "FALSE" << std::endl;
    print_color("superior or equal to:", YELLOW);
    if (e >= f)
        std::cout << MAGENTA << e << " >= " << f << " = " << GREEN << "TRUE" << std::endl;
    else
        std::cout << MAGENTA << e << " >= " << f << " = " << RED << "FALSE" << std::endl;
    print_color("inferior or equal to:", YELLOW);
    if (e <= f)
        std::cout << MAGENTA << e << " <= " << f << " = " << GREEN << "TRUE" << std::endl;
    else
        std::cout << MAGENTA << e << " <= " << f << " = " << RED << "FALSE" << std::endl;
    print_color("superior or equal to:", YELLOW);
    if (g >= f)
        std::cout << MAGENTA << g << " >= " << f << " = " << GREEN << "TRUE" << std::endl;
    else
        std::cout << MAGENTA << g << " >= " << f << " = " << RED << "FALSE" << std::endl;
    print_color("inferior or equal to:", YELLOW);
    if (g <= f)
        std::cout << MAGENTA << g << " <= " << f << " = " << GREEN << "TRUE" << std::endl;
    else
        std::cout << MAGENTA << g << " <= " << f << " = " << RED << "FALSE" << std::endl;
    std::cout << std::endl;

    print_color("~~~~~~~~~~~INCREMENTATION TESTS~~~~~~~~~~~", GREEN);
    print_color("a before pre-incrementation:", YELLOW);
    print_color(a, BLUE);
    std::cout << std::endl;

    print_color("a during pre-incrementation:", YELLOW);
    print_color(++a, BLUE);
    std::cout << std::endl;

    print_color("a after pre-incrementation:", YELLOW);
    print_color(a, BLUE);
    std::cout << std::endl;

    print_color("a during post-incrementation:", YELLOW);
    print_color(a++, BLUE);
    std::cout << std::endl;

    print_color("a after post-incrementation:", YELLOW);
    print_color(a, BLUE);
    std::cout << std::endl;

    print_color("~~~~~~~~~~~DECREMENTATION TESTS~~~~~~~~~~~", GREEN);
    print_color("a before pre-decrementation:", YELLOW);
    print_color(a, BLUE);
    std::cout << std::endl;

    print_color("a during pre-decrementation:", YELLOW);
    print_color(--a, BLUE);
    std::cout << std::endl;

    print_color("a after pre-decrementation:", YELLOW);
    print_color(a, BLUE);
    std::cout << std::endl;

    print_color("a during post-decrementation:", YELLOW);
    print_color(a--, BLUE);
    std::cout << std::endl;

    print_color("a after post-decrementation:", YELLOW);
    print_color(a, BLUE);
    std::cout << std::endl;

    print_color("~~~~~~~~~~~OPERATION TESTS~~~~~~~~~~~", GREEN);
    Fixed p1(5.05f);
    Fixed p2(2);
    Fixed res;
    std::cout << std::endl;

    res = p1 * p2;
    print_color("result of multiplaction:", YELLOW);
    std::cout << MAGENTA << p1 << " * " << p2 << " = "<< BLUE << res << RESET << std::endl;
    std::cout << std::endl;

    res = p1 / p2;
    print_color("result of division:", YELLOW);
    std::cout << MAGENTA << p1 << " / " << p2 << " = " << BLUE << res << RESET << std::endl;
    std::cout << std::endl;

    res = p1 + p2;
    print_color("result of addition:", YELLOW);
    std::cout << MAGENTA << p1 << " + " << p2 << " = "<< BLUE << res << RESET << std::endl;
    std::cout << std::endl;

    res = p1 - p2;
    print_color("result of substraction:", YELLOW);
    std::cout << MAGENTA << p1 << " - " << p2 << " = " << BLUE << res << RESET << std::endl;
    std::cout << std::endl;

    print_color("~~~~~~~~~~~MIN/MAX FUNCTIONS TEST~~~~~~~~~~~", GREEN);
    Fixed min(3);
    Fixed max(42.42f);
    print_color("result of max between a and res:", YELLOW);
    print_color(Fixed::max( min, max ), BLUE);
    std::cout << std::endl;

    print_color("result of min between a and res:", YELLOW);
    print_color(Fixed::min( min, max ), BLUE);
    std::cout << std::endl;

    return 0;
}

void print_color(Fixed msg, const char *clr)
{
    std::cout << clr << msg << RESET << std::endl;
    return ;
}
void print_color(const std::string& msg, const char *clr)
{
    std::cout << clr << msg << RESET << std::endl;
    return ;
}