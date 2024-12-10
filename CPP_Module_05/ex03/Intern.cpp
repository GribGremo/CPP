/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:27:01 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/10 16:19:59 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#define BRIGHT_ORANGE "\033[38;5;208m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR
Intern::Intern(){
    std::cout << BRIGHT_ORANGE << "Intern default constructor called" << RESET << std::endl;
    array[0]= "ShrubberyCreationForm";
    array[1]= "RobotomyRequestForm";
    array[2]= "PresidentialPardonForm";
}
Intern::Intern(const Intern& src){
    std::cout << BRIGHT_ORANGE << "Intern copy constructor called" << RESET << std::endl;
    (void)src;
}
Intern::~Intern(){
    std::cout << BRIGHT_ORANGE << "Intern destructor called" << RESET << std::endl;
}

//OPERATORS
Intern& Intern::operator=(const Intern& src){
    std::cout << BRIGHT_ORANGE << "Intern assignment operator called" << RESET << std::endl;
    (void)src;
    return (*this);
}

//METHODS
AForm* Intern::makeForm(const std::string& formname, const std::string& target){
    int i = 0;
    AForm* form = NULL;
    for (i = 0; i < 3; i++)
    {
        if (formname == array[i])
            break;
    }
    switch (i)
    {
    case 0:
        form = new ShrubberyCreationForm(formname, target);
        std::cout << BRIGHT_ORANGE << "Intern creates " << formname << RESET << std::endl;
        break;
    case 1:
        form = new RobotomyRequestForm(formname, target);
        std::cout << BRIGHT_ORANGE << "Intern creates " << formname << RESET << std::endl;
        break;
    case 2:
        form = new PresidentialPardonForm(formname, target);
        std::cout << BRIGHT_ORANGE << "Intern creates " << formname << RESET << std::endl;
        break;
    default:
        std::cout << RED << "Form " << formname << " does not exists, can't create one." << RESET << std::endl;
        break;
    }
    return (form);
}