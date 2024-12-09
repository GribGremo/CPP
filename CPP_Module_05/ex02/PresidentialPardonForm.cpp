/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:27 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/09 17:25:34 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
# include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential_pardon_form", 25, 5), _target("defaultTarget") {
    std::cout << MAGENTA << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src), _target(src._target){
    std::cout << MAGENTA << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("Presidential_pardon_form", 25, 5), _target(target){
    std::cout << MAGENTA << "PresidentialPardonForm custom constructor called" << RESET << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << MAGENTA << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

//OPERATORS

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src){
    std::cout << MAGENTA << "PresidentialPardonForm assignment operator called" << RESET << std::endl;
    if (this != &src) {
        AForm::operator=(src); 
        _target = src._target;
    }
}

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm& src){
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

std::string PresidentialPardonForm::getTarget(){
    return (this->_target);
}

//METHODS

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    checkSigned(executor);
    checkGranted(executor);
    executePresidentialPardon();
}

void PresidentialPardonForm::checkSigned(Bureaucrat const & executor) const{
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
    std::cout << MAGENTA << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std ::endl;
}