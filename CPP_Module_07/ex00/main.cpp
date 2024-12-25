/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:10:23 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/25 22:49:58 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(){
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;





    // int a = 5;
    // int b = 3;
    // float c = 3.1f;
    // float d = 2.9f;
    // double e = 4.5;
    // double f = 7.8;

    // std::cout << "min int: " << min(a,b) <<std::endl;
    // std::cout << "min float: " << min(c,d) <<std::endl;
    // std::cout << "min double: " <<min(e,f) <<std::endl;

    // std::cout << "max int: " <<max(a,b) <<std::endl;
    // std::cout << "max float: " <<max(c,d) <<std::endl;
    // std::cout << "max double: " <<max(e,f) <<std::endl;

    // swap(a,b);
    // swap(c,d);
    // swap(e,f);

    // std::cout << "a: " << a <<std::endl;
    // std::cout << "b: " << b <<std::endl;
    // std::cout << "c: " << c <<std::endl;
    // std::cout << "d: " << d <<std::endl;
    // std::cout << "e: " << e <<std::endl;
    // std::cout << "f: " << f <<std::endl;
}