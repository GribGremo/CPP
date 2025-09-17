/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:48:22 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/13 13:58:50 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vect2.hpp"
// #include "log.hpp"

int main(){
    Vect2 v1;//0,0
    Vect2 v2(1,2);//1,2
    const Vect2 v3(v2);//1,2
    Vect2 v4 = v2;//1,2

    std::cout << "v1:" << v1 << std::endl;
    std::cout << "v2:" << v2 << std::endl;
    std::cout << "v3:" << v3 << std::endl;
    std::cout << "v4:" << v4 << std::endl;
    std::cout << v4++ << std::endl;//print 1,2
    std::cout << ++v4 << std::endl;
    std::cout << v4-- << std::endl;//print 3,4
    std::cout << --v4 << std::endl;

    v2 += v3;//2,4
    std::cout << v2 << std::endl;
    v1 -= v2;//-2,-4
    std::cout << v1 << std::endl;
    v2 = v3 + v3 * 2;//3,6
    std::cout << v2 << std::endl;
    v2 = 3 * v2;// 9,18
    std::cout << v2 << std::endl;
    v2 += v2 += v3;//20,40
    std::cout << v2 << std::endl;
    v2 *= 42;//-84,-168
    std::cout << v2 << std::endl;
    v1 = v1 - v1 + v1;
    std::cout << v1 << std::endl;

    std::cout << "v1:" << v1 << std::endl;
    std::cout << "v2:" << v2 << std::endl;
    std::cout << "-v2:" << -v2 << std::endl;
    std::cout << "v1[1]:" << v1[1] << std::endl;

    v1[1] = 12;

    std::cout << "v1[1]:" << v1[1] << std::endl;
    std::cout << "v3[1]:" << v3[1] << std::endl;
    std::cout << "v1==v3:" << (v1==v3) << std::endl;//Parentheses?
    std::cout << "v1==v1:" << (v1==v1) << std::endl;
    std::cout << "v1!=v3:" << (v1!=v3) << std::endl;
    std::cout << "v1!=v1:" << (v1!=v1) << std::endl;

}