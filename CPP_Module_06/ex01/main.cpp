/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:29:29 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/25 18:11:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data* a = new Data;
    Data* b;
    uintptr_t res;

    a->c = 'a';
    a->i = 42;
    a->d = 21.0;
    a->f = 10.5f;
    
    std::cout << "Adress a point to: " << a <<std::endl;
    res = Serializer::serialize(a);
    std::cout << "Reinterpreted Data* (a) in format uintptr_t: " << res <<std::endl;
    b = Serializer::deserialize(res);
    std::cout << "Reinterpreted uintptr_t in format Data* (b): " << b << std::endl;

    std::cout << "Data->c: " << b->c << std::endl;
    std::cout << "Data->i: " << b->i << std::endl;
    std::cout << "Data->d: " << b->d << std::endl;
    std::cout << "Data->d: " << b->f << std::endl;
    delete a;
}