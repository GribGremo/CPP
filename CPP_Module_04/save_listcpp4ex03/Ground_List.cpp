/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground_List.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:19:41 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/12 16:16:33 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ground_List.hpp"
#include "Character.hpp"

Ground_List::Ground_List():head(NULL){
    std::cout << "Ground_List default constructor called" << std::endl;

}
Ground_List::Ground_List(const Ground_List& src):head(NULL){
    std::cout << "Ground_List copy constructor called" << std::endl;
    (void)src;
}
Ground_List::~Ground_List(){
    std::cout << "Ground_List destructor called" << std::endl;
    AMateria* temp;
    AMateria* head;

    temp = Character::ground->head;
    head = temp;
    while(head != NULL)
    {
        temp = head;
        head = temp->getNext();
        delete temp;
    }
}

Ground_List& Ground_List::operator=(const Ground_List& src){
    std::cout << "Ground_List equal operator called" << std::endl;
    (void)src;
    // AMateria* temp;
    // AMateria* cpy = NULL;
    // AMateria* head_cpy = src.head;

    // temp = src.head;
    // if (this != &src)
    // {
    //     while(temp != NULL)
    //     {

    //     }
    // }
    return(*this);
}

void Ground_List::push(AMateria* m){
    AMateria* temp;
    temp = Character::ground->head;
    if (temp != NULL)
    {
        while (temp != NULL)
            temp = temp->getNext();
        temp->setNext(m);
    }
    else
        Character::ground->head = m;
}

void Ground_List::printList(){

}