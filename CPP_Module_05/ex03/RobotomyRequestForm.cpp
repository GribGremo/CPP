/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/10 16:17:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

# include <iostream>
# include <cstdlib>
#include <ctime> 

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
# define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy_request_form", 72, 45), _target("defaultTarget") {
    std::cout << BLUE << "RobotomyRequestForm default constructor called" << RESET << std::endl;
    srand(static_cast<unsigned int>(time(NULL))); 
    /* Here we initialise the seed used by rand for this object, to avoid multiple call to time that returns the
    same seed for each seconds, if i call the function too fast same seed, same results, else same seed but each 
    call to rand make it progress in that sequence*/
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm(src), _target(src._target){
    std::cout << BLUE << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robotomy_request_form", 72, 45), _target(target){
    std::cout << BLUE << "RobotomyRequestForm custom constructor called" << RESET << std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& formname, const std::string& target): AForm(formname, 72, 45), _target(target){
    std::cout << BLUE << "RobotomyRequestForm custom constructor called" << RESET << std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
}
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << BLUE << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

//OPERATORS

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
    std::cout << BLUE << "RobotomyRequestForm assignment operator called" << RESET << std::endl;
    if (this != &src) {
        AForm::operator=(src); 
        _target = src._target;
    }
    return (*this);
}

//SETTERS/GETTERS

std::string RobotomyRequestForm::getTarget(){
    return (this->_target);
}

//METHODS

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    (void)executor;
    checkSigned();
    checkGranted(executor);
    executeRobotomy();
}

void RobotomyRequestForm::checkSigned() const{
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
        std::cout << BLUE<< "*Mechanic's sound* *scream* Robotomy " << GREEN << "success" << BLUE << " on " << this->_target << RESET << std::endl;
    else    
        std::cout << BLUE<< "Robotomy " << RED << "failure" << BLUE << " on " << this->_target << RESET << std::endl;
}

void RobotomyRequestForm::pform(){
    std::cout << BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
    std::cout << BLUE << "Form " << this->getName() << RESET << std::endl;
    std::cout << BLUE << "Grade to sign: " << this->getGradeToSign() << RESET << std::endl;
    std::cout << BLUE << "Grade to execute: " << this->getGradeToExecute() << RESET << std::endl;
    std::cout << BLUE << "Target: " << this->getTarget() << RESET << std::endl;
    if (this->getSignedBool() == true)
        std::cout << BLUE << "Signature status: " << GREEN << "SIGNED" << RESET << std::endl;
    else
        std::cout << BLUE << "Signature status: " << RED << "UNSIGNED" << RESET << std::endl;
    std::cout << BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
}