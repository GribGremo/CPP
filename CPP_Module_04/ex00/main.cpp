/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 12:40:47 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
//Dynamic link(the pointer point to an object at the execution it saw that my object has vpointer and soit goes to vtable to decide which method use accordingly to the real type of my object even if the pointer is base type)
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
//Static link (the pointer point to an object cat but it is decided at compilation so, he thinks this is really an animal and not a cat)
    const WrongAnimal* metax = new WrongAnimal();
    const WrongAnimal* x = new WrongCat();
    std::cout << x->getType() << " " << std::endl;
    x->makeSound();
    metax->makeSound();

    return 0;
}