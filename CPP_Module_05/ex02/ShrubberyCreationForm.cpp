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
#include "Bureaucrat.hpp"

# include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery_creation_form", 145, 137), _target("defaultTarget") {
    std::cout << MAGENTA << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src), _target(src._target){
    std::cout << MAGENTA << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("Shrubbery_creation_form", 145, 137), _target(target){
    std::cout << MAGENTA << "ShrubberyCreationForm custom constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << MAGENTA << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

//OPERATORS

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
    std::cout << MAGENTA << "ShrubberyCreationForm assignment operator called" << RESET << std::endl;
    if (this != &src) {
        AForm::operator=(src); 
        _target = src._target;
    }
}

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm& src){
    out << MAGENTA << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
    out << MAGENTA << "Form " << src.getName() << RESET << std::endl;
    out << MAGENTA << "Grade to sign: " << src.getGradeToSign() << RESET << std::endl;
    out << MAGENTA << "Grade to execute: " << src.getGradeToExecute() << RESET << std::endl;
    out << MAGENTA << "Target: " << src.getTarget() << RESET << std::endl;
    if (src.getSignedBool() == true)
        out << MAGENTA << "Signature status: " << GREEN << "SIGNED" << RESET << std::endl;
    else
        out << MAGENTA << "Signature status: " << RED << "UNSIGNED" << RESET << std::endl;
    out << MAGENTA << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
    return (out);
}

//SETTERS/GETTERS

std::string ShrubberyCreationForm::getTarget(){
    return (this->_target);
}


//METHODS

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    checkSigned(executor);
    checkGranted(executor);
    executeShrubbery();
}

void ShrubberyCreationForm::checkSigned(Bureaucrat const & executor) const{
    if (this->getSignedBool() == true)
        return ;
    else    
        throw UnsignedFormException();
}

void ShrubberyCreationForm::checkGranted(Bureaucrat const & executor) const {
    if (executor.getGrade() <= this->getGradeToExecute())
        return ;
    else    
        throw UngrantedException();
}

void ShrubberyCreationForm::executeShrubbery() const{
    std::ofstream ofs(this->_target.c_str());

    if (!ofs.is_open())
    {
        std::cerr << MAGENTA << "Cannot open file " << "\"" + _target + "\"" << RESET << std::endl;
        std::cerr << strerror(errno) << std::endl;
        return ;
    }
    ofs << MAGENTA << "               ,@@@@@@@, \
       ,,,.   ,@@@@@@/@@,  .oo8888o. \
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o \
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' \
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' \
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' \
   `&%\\ ` /%&'    |.|        \\ '|8' \
       |o|        | |         | | \
       |.|        | |         | | \
    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << RESET << std::endl;

}

