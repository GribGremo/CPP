/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:27 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/10 16:15:53 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
# include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN    "\033[36m"
# define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential_pardon_form", 25, 5), _target("defaultTarget") {
    std::cout << CYAN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src), _target(src._target){
    std::cout << CYAN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("Presidential_pardon_form", 25, 5), _target(target){
    std::cout << CYAN << "PresidentialPardonForm custom constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& formname, const std::string& target): AForm(formname, 25, 5), _target(target){
    std::cout << CYAN << "PresidentialPardonForm custom constructor called" << RESET << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << CYAN << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

//OPERATORS

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src){
    std::cout << CYAN << "PresidentialPardonForm assignment operator called" << RESET << std::endl;
    if (this != &src) {
        AForm::operator=(src); 
        _target = src._target;
    }
    return (*this);
}

//SETTERS/GETTERS

std::string PresidentialPardonForm::getTarget(){
    return (this->_target);
}

//METHODS

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    (void)executor;
    checkSigned();
    checkGranted(executor);
    executePresidentialPardon();
}

void PresidentialPardonForm::checkSigned() const{
    if (this->getSignedBool() == true)
        return ;
    else
        throw UnsignedFormException();
}

void PresidentialPardonForm::checkGranted(Bureaucrat const & executor) const {
    if (executor.getGrade() <= this->getGradeToExecute())
        return ;
    else    
        throw UngrantedException();
}

void PresidentialPardonForm::executePresidentialPardon() const{
    std::cout << CYAN << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std ::endl;
}

void PresidentialPardonForm::pform(){
    std::cout << CYAN << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
    std::cout << CYAN << "Form " << this->getName() << RESET << std::endl;
    std::cout << CYAN << "Grade to sign: " << this->getGradeToSign() << RESET << std::endl;
    std::cout << CYAN << "Grade to execute: " << this->getGradeToExecute() << RESET << std::endl;
    std::cout << CYAN << "Target: " << this->getTarget() << RESET << std::endl;
    if (this->getSignedBool() == true)
        std::cout << CYAN << "Signature status: " << GREEN << "SIGNED" << RESET << std::endl;
    else
        std::cout << CYAN << "Signature status: " << RED << "UNSIGNED" << RESET << std::endl;
    std::cout << CYAN << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
}