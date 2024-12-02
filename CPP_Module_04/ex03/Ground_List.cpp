/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground_List.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:19:41 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/29 12:16:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ground_List.hpp"
#include "Character.hpp"

#define GREY    "\033[38;5;242m"
#define RESET "\033[0m"

Ground_List::Ground_List():head(NULL){
    std::cerr << GREY << "Ground_List default constructor called" << RESET << std::endl;
}
Ground_List::Ground_List(const Ground_List& src){
    std::cerr << GREY << "Ground_List copy constructor called" << RESET << std::endl;
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
    std::cerr << GREY << "Ground_List destructor called" << RESET << std::endl;
    AMateria* temp;
    AMateria* head;

    temp = this->head;
    head = temp;
    while(head != NULL)
    {
        temp = head;
        head = temp->getNext();
        delete temp;
    }
}

Ground_List& Ground_List::operator=(const Ground_List& src){
    std::cerr << GREY << "Ground_List equal operator called" << RESET << std::endl;
    (void)src;
    AMateria* temp;
    AMateria* head;

    temp = this->head;
    head = temp;
    while(head != NULL)
    {
        temp = head;
        head = temp->getNext();
        delete temp;
    }
    this->head = NULL;

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
    std::cout << GREY << std::endl<< "MATERIA ON GROUND"<< RESET <<std::endl;
    if (temp == NULL)
    {
        std::cout << GREY <<std::endl << "none" << RESET <<std::endl<<std::endl;
        return ;
    }
    while(temp != NULL)
    {
        std::cout << GREY << std::endl << "-------------" << std::endl << "Materia " << i << std::endl << "Type: " << temp->getType() << RESET << std::endl;
        temp = temp->getNext();
        i++;
    }
    std::cout << std::endl;
}