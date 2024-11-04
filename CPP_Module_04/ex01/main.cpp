/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 18:06:47 by sylabbe          ###   ########.fr       */
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
    {
        array_animal[i] = new Dog();
        array_animal[i]->setIdea("Give me the ball *bark*",0);
    }
    for(int i = array_size/2; i < array_size; i++)
    {
        array_animal[i] = new Cat();
        array_animal[i]->setIdea("Feed me human *meow*",0);
    }
    array_animal[2]->setIdea("ERROR",0);

    std::cout << std::endl << "ARRAY_ANIMAL RENDER" << std::endl <<std::endl;
    for(int i = 0; i < array_size; i++)
    {
        std::cout << "Type: " << array_animal[i]->getType() << std::endl;
        array_animal[i]->makeSound();
        std::cout << array_animal[i]->getIdea(0) << std::endl;
        delete array_animal[i];
        std::cout << std::endl;
    }

    Dog a;
    a.setIdea("TEST1",0);
    Dog b(a);
    std::cout << "A" << a.getIdea(0)<<a.getType()<<std::endl;
    std::cout << "B" << b.getIdea(0)<<b.getType()<<std::endl;
    a.~Dog();
    // std::cout << "A" << a.getIdea(0)<<a.getType()<<std::endl;
    std::cout << "B" << b.getIdea(0)<<b.getType()<<std::endl;
    return 0;
}