/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:24 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/30 15:58:49 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "~~~~~~~~~~~~~TEST1 : AMateria~~~~~~~~~~~~~" <<std::endl;

    AMateria* ice = new Ice;
    AMateria* cure = new Cure;
    AMateria* test = new Cure;

    std::cout << "Test type:" << test->getType() << std::endl;
    *test = *ice;
    std::cout << "Test type:" << test->getType() << std::endl;
    *test = *cure;
    std::cout << "Test type:" << test->getType() << std::endl << std::endl;

    AMateria* cpyi(ice); 
    std::cout << "Test type:" << cpyi->getType() << std::endl;
    AMateria* cpyc(cure); 
    std::cout << "Test type:" << cpyc->getType() << std::endl << std::endl;



    std::cout << "~~~~~~~~~~~~~TEST1 : Materia clone~~~~~~~~~~~~~" <<std::endl;

    Ice* def = new Ice();
    AMateria* test1 = new Ice(*def);
    std::cout << std::endl;

    AMateria* cl = test1->clone();
    delete test1;
    std::cout << "clone: "<< cl->getType() << std::endl;

    delete def;
    delete cl;


    std::cout <<std::endl << "~~~~~~~~~~~~~TEST2 : Materia use~~~~~~~~~~~~~" <<std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character* me = new Character("me");
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    Character* bob = new Character("bob");
    
    std::cout << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(1);
    std::cout << std::endl;

    IMateriaSource* cpyms(src);/////////
    std::cout << std::endl;

    me->equip(cpyms->createMateria("ice"));
    me->use(0, *bob);

    Character* cpych = new Character(*me);
    me->print_inventory();
    cpych->print_inventory();
    me->equip(cpyms->createMateria("ice"));
    cpych->equip(cpyms->createMateria("cure"));
    me->print_inventory();
    cpych->print_inventory();
    bob->equip(cpyms->createMateria("cure"));
    bob->print_inventory();
    *bob = *cpych;
    cpych->print_inventory();
    bob->print_inventory();
    bob->equip(cpyms->createMateria("ice"));
    cpych->equip(cpyms->createMateria("cure"));
    cpych->print_inventory();
    bob->print_inventory();

    delete cpych;
    delete bob;
    delete me;
    delete src;

    std::cout <<std::endl << "~~~~~~~~~~~~~TEST3 : Unequip~~~~~~~~~~~~~" <<std::endl;
    ICharacter* victim = new Character("victim");
    ICharacter* toto = new Character("toto");
    IMateriaSource* src3 = new MateriaSource();
    std::cout<< "No materia on ground" << std::endl;
    Character::ground->printList();

    AMateria* cantfind = src3->createMateria("ice");
    std::cout << "Attempt of finding ice in empty materia source: " << cantfind << std::endl;

    src3->learnMateria(new Ice());
    src3->learnMateria(new Cure());
    src3->learnMateria(new Cure());
    src3->learnMateria(new Cure());
    AMateria* cu =  new Cure();
    src3->learnMateria(cu);

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
    toto->unequip(0);
    toto->unequip(1);
    toto->unequip(2);
    toto->unequip(3);

    std::cout<< "Materia on ground" << std::endl;
    Character::ground->printList();
    Ground_List cpy_ground(*Character::ground); //= *Character::ground;
    toto->equip(new Cure);
    toto->unequip(0);

    std::cout<< "Materia on ground plus one cure" << std::endl;
    Character::ground->printList();

    std::cout<< "No more materia on copyground, this copy has been made before adding one Cure to ground" << std::endl;
    cpy_ground.printList();

    std::cout<< "Transmit copyground to ground so without the last materia cure" << std::endl;

    *Character::ground = cpy_ground;

    Character::ground->printList();
    
    delete cu;
    delete victim;
    delete toto;
    delete src3;
}