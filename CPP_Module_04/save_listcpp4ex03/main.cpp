/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:24 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/12 15:30:04 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "TEST1" <<std::endl;

    Ice* def = new Ice();
    AMateria* test = new Ice(*def);
    std::cout << std::endl;
    AMateria* cl = test->clone();
    delete test;
    std::cout << "clone: "<< cl->getType() << std::endl;

    delete def;
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

    std::cout <<std::endl << "TEST3" <<std::endl;
    ICharacter* victim = new Character("victim");
    ICharacter* toto = new Character("toto");
    IMateriaSource* src3 = new MateriaSource();
    src3->learnMateria(new Ice());
    src3->learnMateria(new Cure());
    AMateria* clone_ice1 = src3->createMateria("ice");
    AMateria* clone_ice2 = src3->createMateria("ice");
    AMateria* clone_ice3 = src3->createMateria("ice");
    AMateria* clone_cure1 = src3->createMateria("cure");
    AMateria* clone_cure2 = src3->createMateria("cure");



    toto->use(0, *victim);
    toto->use(4, *victim);
    toto->equip(clone_ice1);
    toto->equip(clone_cure1);
    toto->equip(clone_ice2);
    toto->equip(clone_cure2);
    toto->equip(clone_ice3);
    toto->use(0, *victim);
    toto->use(1, *victim);
    toto->unequip(0);
    toto->equip(clone_ice3);
    toto->use(0, *victim);

    delete clone_ice1;
    delete victim;
    delete toto;
    delete src3;

}