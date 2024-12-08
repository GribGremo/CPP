/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:39 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/08 12:56:37 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("defaultName", 145, 137), _target("defaultTarget") {
    std::cout << MAGENTA << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src., 145, 137), _target(target){// Comment atteindre les arguments prives AForm?
    std::cout << MAGENTA << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target, const std::string& name): AForm(name, 145, 137), _target(target){
    std::cout << MAGENTA << "ShrubberyCreationForm custom constructor called" << RESET << std::endl;

}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << MAGENTA << "ShrubberyCreationForm destructor called" << RESET << std::endl;

}

//OPERATORS

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
    std::cout << MAGENTA << "ShrubberyCreationForm assignment operator called" << RESET << std::endl;

}

//METHODS

void createShrubbery(){

}