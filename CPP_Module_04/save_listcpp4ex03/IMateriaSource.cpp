/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:49 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/29 12:15:43 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#define BRIGHT_ORANGE "\033[38;5;208m"
#define RESET "\033[0m"

//CONSTRUCTORS//DESTRUCTOR
IMateriaSource::IMateriaSource(){
    std::cerr << BRIGHT_ORANGE << "IMateriaSource default constructor called" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
}
IMateriaSource::IMateriaSource(const IMateriaSource& src){
    std::cerr << BRIGHT_ORANGE << "IMateriaSource copy constructor called" << RESET << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (src.sources[i] != NULL)
            sources[i] = src.sources[i]->clone();
        else
            sources[i] = NULL;
    }
}
IMateriaSource::~IMateriaSource(){
    std::cerr << BRIGHT_ORANGE << "IMateriaSource destructor called" << RESET << std::endl;
    // for (int i = 0; i < 4; i++) DEJA FREE DANS DESTRUCTOR MATERIA SOURCE?
    // {
    //     if (sources[i] != NULL)
    //         delete sources[i];
    // }
}

//OPERATORS
IMateriaSource& IMateriaSource::operator=(const IMateriaSource& src){
    std::cerr << BRIGHT_ORANGE << "IMateriaSource equal operator called" << RESET << std::endl;
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