/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:04:24 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/02 16:37:44 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    /*SET UP CLASS OBJECT*/
    AMateria* ice = new Ice;
    AMateria* cure = new Cure;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(ice);
    src->learnMateria(cure);
    Character* me = new Character("me");
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    Character* bob = new Character("bob");

    std::cout << "~~~~~~~~~~~~~TEST1 : AMateria~~~~~~~~~~~~~" <<std::endl;
    std::cout << std::endl;

    AMateria* test = new Cure;
    std::cout << std::endl;

    std::cout << "Test type:" << test->getType() << std::endl;
    *test = *ice;
    std::cout << "Test type:" << test->getType() << std::endl;
    *test = *cure;
    std::cout << "Test type:" << test->getType() << std::endl;
    std::cout << "Here i try to use assignment operator of AMateria even if it is an abstract class, i decide to not change type of materia, it could make a cure be an ice"<< std::endl << std::endl;

    AMateria* cpyi = ice->clone(); 
    std::cout << "Test type:" << cpyi->getType() << std::endl;
    AMateria* cpyc = cure->clone(); 
    std::cout << "Test type:" << cpyc->getType() << std::endl << std::endl;

    delete cpyc;
    delete cpyi;
    delete test;
    
    std::cout <<std::endl << "~~~~~~~~~~~~~TEST2 : Materia use~~~~~~~~~~~~~" <<std::endl;
    std::cout << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    me->unequip(0);
    me->unequip(1);
    std::cout << std::endl;

    std::cout <<"Creation of a copy of a Materiasource" <<  std::endl<<  std::endl;
    IMateriaSource* cpyms(src);/////////
    
    std::cout << "Test of equip and use a materia via a materia created copy of a materia source" << std::endl;
    me->equip(cpyms->createMateria("ice"));
    me->use(0, *bob);
    std::cout<<std::endl;

    std::cout <<"Creation of a copy of a Character" <<  std::endl<<  std::endl;
    Character* cpych = new Character(*me);
    std::cout << std::endl;
   
    std::cout <<"Print me inventory" <<  std::endl;
    me->print_inventory();
    std::cout <<"Print copy of me inventory" <<  std::endl;
    cpych->print_inventory();

    std::cout << "Equip new materia to me and copyme" << std::endl;
    me->equip(cpyms->createMateria("ice"));
    cpych->equip(cpyms->createMateria("cure"));

    std::cout <<"Print me inventory" <<  std::endl;
    me->print_inventory();
    std::cout <<"Print copy of me inventory" <<  std::endl;
    cpych->print_inventory();

    std::cout << "Equip new materia to bob" << std::endl;
    bob->equip(cpyms->createMateria("cure"));
    std::cout <<"Print bob inventory" <<  std::endl;
    bob->print_inventory();
    std::cout << "bob copy copyme who was a copy of me" << std::endl;
    *bob = *cpych;
    std::cout <<"Print copyme inventory" <<  std::endl;
    cpych->print_inventory();
    std::cout <<"Print bob inventory" <<  std::endl;
    bob->print_inventory();
    std::cout << "Equip new materia to bob and copyme" << std::endl;
    bob->equip(cpyms->createMateria("ice"));
    cpych->equip(cpyms->createMateria("cure"));
    std::cout <<"Print copyme inventory" <<  std::endl;
    cpych->print_inventory();
    std::cout <<"Print bob inventory" <<  std::endl;
    bob->print_inventory();

    delete cpych;


    std::cout <<std::endl << "~~~~~~~~~~~~~TEST3 : Unequip~~~~~~~~~~~~~" <<std::endl;
    ICharacter* victim = new Character("victim");
    ICharacter* toto = new Character("toto");
    IMateriaSource* src3 = new MateriaSource();
    std::cout<< "No materia on ground" << std::endl;
    Character::ground->printList();

    AMateria* cantfind = src3->createMateria("ice");
    std::cout << "Attempt of finding ice in empty materia source: " << cantfind << std::endl;

    std::cout << "Attempt of adding materia to a materia source" << std::endl <<std::endl;
    src3->learnMateria(ice);
    src3->learnMateria(cure);
    src3->learnMateria(cure);
    src3->learnMateria(cure);
    src3->learnMateria(cure);
    std::cout <<std::endl;

    std::cout << "Create bunch of materias" << std::endl <<std::endl;
    AMateria* clone_ice1 = src3->createMateria("ice");
    AMateria* clone_ice2 = src3->createMateria("ice");
    AMateria* clone_ice3 = src3->createMateria("ice");
    AMateria* clone_cure1 = src3->createMateria("cure");
    AMateria* clone_cure2 = src3->createMateria("cure");
    std::cout <<std::endl;

    std::cout << "toto has no materia: try to use still" << std::endl <<std::endl;
    toto->use(0, *victim);
    toto->use(4, *victim);
    std::cout <<std::endl;

    std::cout << "Attempt of adding materia to toto" << std::endl <<std::endl;
    toto->equip(clone_ice1);
    toto->equip(clone_cure1);
    toto->equip(clone_ice2);
    toto->equip(clone_cure2);
    toto->equip(clone_ice3);
    std::cout << std::endl;

    std::cout << "Use of toto's materia" << std::endl <<std::endl;
    toto->use(0, *victim);
    toto->use(1, *victim);
    std::cout <<std::endl;


    toto->unequip(0);
    toto->equip(clone_ice3);
    toto->use(0, *victim);
    toto->unequip(0);
    toto->unequip(1);
    toto->unequip(2);
    toto->unequip(3);
    std::cout << std::endl;

    std::cout<< "Materia on ground" << std::endl;
    Character::ground->printList();
    std::cout << std::endl;

    std::cout << "Copy of ground" << std::endl;
    Ground_List cpy_ground(*Character::ground); //= *Character::ground;

    std::cout << "Equip and unequip one more materia" << std::endl;
    toto->equip(new Cure);
    toto->unequip(0);
    std::cout << std::endl;

    std::cout<< "Materia on ground plus one cure" << std::endl;
    Character::ground->printList();

    std::cout<< "No more materia on copyground, this copy has been made before adding one Cure to ground" << std::endl;
    cpy_ground.printList();

    std::cout<< "Transmit copyground to ground so without the last materia cure" << std::endl;

    *Character::ground = cpy_ground;

    Character::ground->printList();
    
    delete victim;
    delete toto;
    delete src3;

    /*DELETE CLASS OBJECT*/
    delete ice;
    delete cure;
    delete bob;
    delete me;
    delete src;
}