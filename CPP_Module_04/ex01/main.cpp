/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 15:29:07 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int array_size = 6;
    Animal *array_animal[array_size];

    for(int i = 0; i < array_size / 2; i++)
        array_animal[i] = new Dog();
    for(int i = 50; i < array_size; i++)
        array_animal[i] = new Cat();
    
    for(int i = 0; i < array_size; i++)
        delete[] array_animal[i];
    //     array_animal[i]->~Animal();
    return 0;
}