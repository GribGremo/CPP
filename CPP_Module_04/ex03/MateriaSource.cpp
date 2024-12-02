/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:42 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/30 14:54:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#define ORANGE "\033[38;5;166m"
#define RESET "\033[0m"

//CONSTRUCTORS//DESTRUCTOR
MateriaSource::MateriaSource(){
    std::cerr << ORANGE << "MateriaSource default constructor called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& src){
    std::cerr << ORANGE << "MateriaSource copy constructor called" << RESET << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (src.sources[i] != NULL)
            sources[i] = src.sources[i]->clone();
        else
            sources[i] = NULL;
    }
}
MateriaSource::~MateriaSource(){
    std::cerr << ORANGE << "MateriaSource destructor called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] != NULL)
            delete sources[i];
    }
}

//OPERATORS
MateriaSource& MateriaSource::operator=(const MateriaSource& src){
    std::cerr << ORANGE << "MateriaSource equal operator called" << RESET << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (sources[i] != NULL)
                delete sources[i];
        }
        for(int i = 0; i < 4; i++)
        {
            if (src.sources[i] != NULL)
                sources[i] = src.sources[i]->clone();
            else
                sources[i] = NULL;
        }
    }
    return (*this);
}

//FUNCTIONS

void MateriaSource::learnMateria(AMateria* m){// Est-ce qu'on doit free la materia passer en entree
    if (m == NULL)
    {
        std::cout << ORANGE << "Entry 'm' is NULL, no actions made on materia source" << RESET << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] == NULL){
            sources[i] = m->clone();
            std::cout << ORANGE << "Materia " << sources[i]->getType() << " learned." << RESET << std::endl;
            return ;
        }
    }
    std::cout << ORANGE << "No more slots on Materia Source" << RESET << std::endl;

}
AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] != NULL && sources[i]->getType() == type)
        {
            std::cout << ORANGE << "Materia " << sources[i]->getType() << " created." << RESET << std::endl;
            AMateria* temp = sources[i]->clone();
            return (temp);
        }
    }
    std::cout << ORANGE << "Can't find Materia of type " << type << " in materia source." << RESET << std::endl;
    return (NULL);
}