/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:42 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/08 12:44:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//CONSTRUCTORS//DESTRUCTOR
MateriaSource::MateriaSource(){
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& src){
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (src.sources[i] != NULL)
            sources[i] = src.sources[i]->clone();
        else
            sources[i] = NULL;
    }
}
MateriaSource::~MateriaSource(){
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] != NULL)
            delete sources[i];
    }
}

//OPERATORS
MateriaSource& MateriaSource::operator=(const MateriaSource& src){
    std::cout << "MateriaSource equal operator called" << std::endl;
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
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] == NULL){
            sources[i] = m;
            std::cout << "Materia " << sources[i]->getType() << " learned." << std::endl;
            return ;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] != NULL && sources[i]->getType() == type)
        {
            std::cout << "Materia " << sources[i]->getType() << " created." << std::endl;
            AMateria* temp = sources[i]->clone();
            return (temp);
        }
    }
    return (NULL);
}