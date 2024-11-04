/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:21:00 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/03 08:12:55 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
    type = "WrongCat";
    std::cout << "WrongCat default contructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& src): WrongAnimal(){
    this->type = src.type;
    std::cout << "WrongCat copy contructor called" << std::endl;
}
WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src){
    this->type = src.type;
    std::cout << "WrongCat equal operator called" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "Hi-Han" << std::endl;
}