/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/03 09:09:19 by grib             ###   ########.fr       */
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
    Animal *array_animal_cpy[array_size];
    
    for(int i = 0; i < array_size / 2; i++)
        array_animal[i] = new Dog();
    for(int i = array_size/2; i < array_size; i++)
        array_animal[i] = new Cat();
    
    for(int i = 0; i < array_size; i++)
    {
        std::cout << "Type: " << array_animal[i]->getType() << std::endl;
        array_animal[i]->makeSound();
        array_animal_cpy[i]. = 
        delete array_animal[i];
    }
    return 0;
}