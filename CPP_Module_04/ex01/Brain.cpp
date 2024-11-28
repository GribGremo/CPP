/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:46:55 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 16:35:52 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#define BRIGHT_YELLOW  "\033[93m"
#define RESET "\033[0m"


Brain::Brain(){
    std::cout << BRIGHT_YELLOW << "Brain default constructor called" << RESET << std::endl;
}
Brain::Brain(const Brain& src){
    std::cout << BRIGHT_YELLOW<< "Brain copy constructor called" << RESET<< std::endl;
    *this = src;
}
Brain::~Brain(){
    std::cout << BRIGHT_YELLOW<< "Brain destructor called" << RESET<< std::endl;
}

Brain& Brain::operator=(const Brain& src){
    std::cout << BRIGHT_YELLOW<< "Brain equal operator called" << RESET<< std::endl;
    for(int i = 0; i < 100; i++)
        _ideas[i]=src._ideas[i];
    return (*this);
}