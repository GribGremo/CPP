/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/05 11:17:23 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "A_Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int array_size = 6;
    // A_Animal a; // We cant instantiate Animal object anymore GG WP
    A_Animal *array_animal[array_size];
    
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
    
    std::cout << std::endl << "COPY TEST RENDER" << std::endl <<std::endl;
    Dog* a = new Dog();
    a->setIdea("TEST1",0);
    Dog* b = new Dog(*a);
    std::cout << "A" << a->getIdea(0)<<a->getType()<<std::endl;
    std::cout << "B" << b->getIdea(0)<<b->getType()<<std::endl;
    delete a;
    // std::cout << "A" << a->getIdea(0)<<a->getType()<<std::endl; // Delete so unhappy
    std::cout << "B" << b->getIdea(0)<<b->getType()<<std::endl; //delete but don't care, because deep copy
    delete b;
    return 0;
}