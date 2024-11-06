/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:49 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/06 17:17:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

//CONSTRUCTORS//DESTRUCTOR
IMateriaSource::IMateriaSource(){
    std::cout << "IMateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
}
IMateriaSource::IMateriaSource(const IMateriaSource& src){
    std::cout << "IMateriaSource copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (src.sources[i] != NULL)
            sources[i] = src.sources[i]->clone();
        else
            sources[i] = NULL;
    }
}
IMateriaSource::~IMateriaSource(){
    std::cout << "IMateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] != NULL)
            delete sources[i];
    }
}

//OPERATORS
IMateriaSource& IMateriaSource::operator=(const IMateriaSource& src){
    std::cout << "IMateriaSource equal operator called" << std::endl;
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