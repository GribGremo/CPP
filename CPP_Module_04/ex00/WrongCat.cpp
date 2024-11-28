/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:21:00 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/28 14:23:28 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

WrongCat::WrongCat(){
    type = "WrongCat";
    std::cout << MAGENTA << "WrongCat default contructor called" << RESET << std::endl;
}
WrongCat::WrongCat(const WrongCat& src){
    this->type = src.type;
    std::cout << MAGENTA <<"WrongCat copy contructor called" << RESET<< std::endl;
}
WrongCat::~WrongCat(){
    std::cout << MAGENTA <<"WrongCat destructor called" << RESET<< std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src){
    this->type = src.type;
    std::cout << MAGENTA <<"WrongCat equal operator called" << RESET << std::endl;
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << MAGENTA <<"Hi-Han" << RESET << std::endl;
}