/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 15:29:38 by sylabbe          ###   ########.fr       */
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

    std::cout << "~~~~~~~~~~~~~ANIMAL OBJECT CASE~~~~~~~~~~~~~" << std::endl;
    Animal a;
    Cat s;
    Dog d;
    std::cout << std::endl;
    std::cout << "Type of animal: " << a.getType() << " : ";
    a.makeSound();
    std::cout << "Type of animal: " << s.getType() << " : ";
    s.makeSound();
    std::cout << "Type of animal: " << d.getType() << " : ";
    d.makeSound();
    std::cout << std::endl;

//Dynamic link(the pointer point to an object at the execution it saw that my object has vpointer and soit goes to vtable to decide which method use accordingly to the real type of my object even if the pointer is base type)

    std::cout << "~~~~~~~~~~~~~ANIMAL POINTER CASE~~~~~~~~~~~~~" << std::endl;
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << std::endl;
    std::cout << "Type of animal: " << meta->getType() << " : ";
    meta->makeSound();
    std::cout << "Type of animal: " << i->getType() << " : ";
    i->makeSound();
    std::cout << "Type of animal: " << j->getType() << " : ";
    j->makeSound();
    std::cout << std::endl;

//Static link (the pointer point to an object cat but it is decided at compilation so, he thinks this is really an animal and not a cat)
    
    std::cout << "~~~~~~~~~~~~~WRONG ANIMAL OBJECT CASE~~~~~~~~~~~~~" << std::endl;
    WrongAnimal w;
    WrongCat felix;
    std::cout << std::endl;

    std::cout << "Type of animal: " << w.getType() << " : ";
    w.makeSound();
    std::cout << "Type of animal: " << felix.getType() << " : ";
    felix.makeSound();
    std::cout << std::endl;
    
    std::cout << "~~~~~~~~~~~~~WRONG ANIMAL POINTER CASE~~~~~~~~~~~~~" << std::endl;
    const WrongAnimal* metax = new WrongAnimal();
    const WrongAnimal* x = new WrongCat();
    std::cout << std::endl;

    std::cout << "Type of animal: " << metax->getType() << " : ";
    metax->makeSound();
    std::cout << "Type of animal: " << x->getType() << " : ";
    x->makeSound();
    std::cout << RED << "Here we can see, if we use a Wrong animal pointer, even if it points to a Wrongcat, it will use Wrong animal makeSound method" << RESET<< std::endl;
    std::cout << std::endl;

    delete meta;
    delete i;
    delete j;
    delete metax;
    delete x;
    return 0;
}