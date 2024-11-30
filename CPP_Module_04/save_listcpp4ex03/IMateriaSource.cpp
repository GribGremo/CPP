/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:49 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/30 14:39:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#define BRIGHT_ORANGE "\033[38;5;208m"
#define RESET "\033[0m"


IMateriaSource::~IMateriaSource(){
    std::cerr << BRIGHT_ORANGE << "IMateriaSource destructor called" << RESET << std::endl;
}

