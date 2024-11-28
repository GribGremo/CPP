/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 16:50:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define RED     "\033[31m"
#define RESET   "\033[0m"

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

    std::cout << std::endl << "~~~~~~~~~ARRAY_ANIMAL RENDER~~~~~~~~~" << std::endl <<std::endl;
    for(int i = 0; i < array_size; i++)
    {
        std::cout << "Type: " << array_animal[i]->getType() << " : ";
        array_animal[i]->makeSound();
        std::cout << "Idea: " << array_animal[i]->getIdea(0) << std::endl;
        delete array_animal[i];
        std::cout << std::endl;
    }

    
    std::cout << std::endl << "~~~~~~~~~COPY TEST RENDER~~~~~~~~~" << std::endl <<std::endl;
    Dog* a = new Dog();
    a->setIdea("TEST1",0);
    Dog* b = new Dog(*a);
    std::cout << std::endl;
    std::cout << "Type: " << a->getType() << " : ";
    a->makeSound();
    std::cout << "Idea: " << a->getIdea(0) << std::endl;
    std::cout << "Type: " << b->getType() << " : ";
    b->makeSound();
    std::cout << "Idea: " << b->getIdea(0) << std::endl;
    std::cout << std::endl;

    delete a;
    std::cout << std::endl;

    // std::cout << "Type: " << a->getType() << " : ";
    // a->makeSound();
    // std::cout << "Idea: " << a->getIdea(0) << std::endl; A IS DELETE WARNING
    std::cout << "Type: " << b->getType() << " : ";
    b->makeSound();
    std::cout << "Idea: " << b->getIdea(0) << std::endl;
    std::cout << RED << "Here we can still use b which is a deep copy of a, even if a is deleted" << RESET << std::endl;
    std::cout << std::endl;
    delete b;
    return 0;
}