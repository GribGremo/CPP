/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:46:55 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 14:57:28 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called" << std::endl;
}
Brain::Brain(const Brain& src){
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}
Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& src){
    std::cout << "Brain equal operator called" << std::endl;
    for(int i = 0; i < 100; i++)
        _ideas[i]=src._ideas[i];
    return (*this);
}