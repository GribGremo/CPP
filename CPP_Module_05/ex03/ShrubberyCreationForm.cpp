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
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& formname, const std::string& target): AForm(formname, 145, 137), _target(target){
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
    return (*this);
}


//SETTERS/GETTERS

std::string ShrubberyCreationForm::getTarget(){
    return (this->_target);
}


//METHODS

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    (void)executor;
    checkSigned();
    checkGranted(executor);
    executeShrubbery();
}

void ShrubberyCreationForm::checkSigned() const{
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
    std::string filename = this->_target + "_shrubbery";
    std::ofstream ofs(filename.c_str());

    if (!ofs.is_open())
    {
        std::cerr << RED << "Cannot open file " << "\"" + _target + "\": " << strerror(errno) << RESET << std::endl;
        return ;
    }
    ofs << MAGENTA << "               ,@@@@@@@," << std::endl;
    ofs << MAGENTA << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    ofs << MAGENTA << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    ofs << MAGENTA << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    ofs << MAGENTA << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    ofs << MAGENTA << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    ofs << MAGENTA << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    ofs << MAGENTA << "       |o|        | |         | |" << std::endl;
    ofs << MAGENTA << "       |.|        | |         | |" << std::endl;
    ofs << MAGENTA << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << RESET << std::endl;
    std::cout << MAGENTA << "File " << filename << " successfully created" << RESET << std::endl;
    ofs.close();
}

void ShrubberyCreationForm::pform(){
    std::cout << MAGENTA << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
    std::cout << MAGENTA << "Form " << this->getName() << RESET << std::endl;
    std::cout << MAGENTA << "Grade to sign: " << this->getGradeToSign() << RESET << std::endl;
    std::cout << MAGENTA << "Grade to execute: " << this->getGradeToExecute() << RESET << std::endl;
    std::cout << MAGENTA << "Target: " << this->getTarget() << RESET << std::endl;
    if (this->getSignedBool() == true)
        std::cout << MAGENTA << "Signature status: " << GREEN << "SIGNED" << RESET << std::endl;
    else
        std::cout << MAGENTA << "Signature status: " << RED << "UNSIGNED" << RESET << std::endl;
    std::cout << MAGENTA << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
}