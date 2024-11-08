/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:24 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/08 16:24:45 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "TEST1" <<std::endl;

    AMateria* empty = NULL;
    Ice* def = new Ice();
    AMateria* test = new Ice(*def);
    AMateria* cl = test->clone();
    std::cout << "clone: "<< cl->getType() << std::endl;
    std::cout << "empty: " <<empty->getType()<< std::endl;

    delete def;
    delete test;
    delete cl;


    std::cout <<std::endl << "TEST2" <<std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}