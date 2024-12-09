/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/09 17:21:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

# include <iostream>
# include <cstdlib>
#include <ctime> 

#define RED "\033[31m"
#define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy_request_form", 72, 45), _target("defaultTarget") {
    std::cout << MAGENTA << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm(src), _target(src._target){
    std::cout << MAGENTA << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robotomy_request_form", 72, 45), _target(target){
    std::cout << MAGENTA << "RobotomyRequestForm custom constructor called" << RESET << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << MAGENTA << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

//OPERATORS

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
    std::cout << MAGENTA << "RobotomyRequestForm assignment operator called" << RESET << std::endl;
    if (this != &src) {
        AForm::operator=(src); 
        _target = src._target;
    }
}

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm& src){
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

std::string RobotomyRequestForm::getTarget(){
    return (this->_target);
}

//METHODS

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    checkSigned(executor);
    checkGranted(executor);
    executeRobotomy();
}

void RobotomyRequestForm::checkSigned(Bureaucrat const & executor) const{
    if (this->getSignedBool() == true)
        return ;
    else    
        throw UnsignedFormException();
}


void RobotomyRequestForm::checkGranted(Bureaucrat const & executor) const {
    if (executor.getGrade() <= this->getGradeToExecute())
        return ;
    else    
        throw UngrantedException();
}

void RobotomyRequestForm::executeRobotomy() const{
    int r = rand();

    if (r % 2 == 1)
        std::cout << MAGENTA<< "*Mechanic's sound* *scream* Robotomy " << GREEN << "success" << MAGENTA << " on " << this->_target << RESET << std::endl;
    else    
        std::cout << MAGENTA<< "Robotomy " << RED << "failure" << MAGENTA << " on " << this->_target << RESET << std::endl;
}

