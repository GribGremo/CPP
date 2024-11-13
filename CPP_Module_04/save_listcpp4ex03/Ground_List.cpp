/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground_List.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:19:41 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/13 15:36:33 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ground_List.hpp"
#include "Character.hpp"

Ground_List::Ground_List():head(NULL){
    std::cout << "Ground_List default constructor called" << std::endl;

}
Ground_List::Ground_List(const Ground_List& src){
    std::cout << "Ground_List copy constructor called" << std::endl;
    (void)src;
    AMateria* tempsrc = src.head;
    this->head = tempsrc->clone();
    AMateria* clone = this->head;
    
    while(tempsrc != NULL)
    {
        tempsrc = tempsrc->getNext();
        if (tempsrc != NULL)
        {
            clone->setNext(tempsrc->clone());
        }
        else
            clone->setNext(NULL);
        clone = clone->getNext();
    }
}
Ground_List::~Ground_List(){
    std::cout << "Ground_List destructor called" << std::endl;
    AMateria* temp;
    AMateria* head;

    temp = this->head;//Character::ground->head;
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
    temp = this->head;
    if (temp != NULL)
    {
        while (temp->getNext() != NULL)
            temp = temp->getNext();
        temp->setNext(m);
    }
    else
        this->head = m;
}

void Ground_List::printList(){
    AMateria *temp = this->head;
    int i = 1;
    std::cout << std::endl<< "MATERIA ON GROUND"<<std::endl;
    if (temp == NULL)
    {
        std::cout <<std::endl << "none" <<std::endl<<std::endl;
        return ;
    }
    while(temp != NULL)
    {
        std::cout << std::endl << "-------------" << std::endl << "Materia " << i << std::endl << "Type: " << temp->getType() << std::endl;
        temp = temp->getNext();
        i++;
    }
    std::cout << std::endl;
}