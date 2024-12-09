/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:56:05 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/09 15:34:58 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
# include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define RED "\033[31m"

//CONSTRUCTOR/DESTRUCTOR

AForm::AForm(): _name("Default_name"), _signed_bool(false), _grade_to_sign(150), _grade_to_execute(150){
    std::cout << YELLOW << "AForm default constructor called" << RESET << std::endl;
}
AForm::AForm(const AForm& src): _name(src._name), _signed_bool(src._signed_bool), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute){
    std::cout << YELLOW << "AForm copy constructor called" << RESET << std::endl;
}
AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute): _name(name), _signed_bool(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute){
    std::cout << YELLOW << "AForm custom constructor called" << RESET << std::endl;
    checkGrade(_grade_to_execute);
    checkGrade(_grade_to_sign);
}
AForm::~AForm(){
    std::cout << YELLOW << "AForm destructor called" << RESET << std::endl;
}

//OPERATOR

AForm&       AForm::operator=(const AForm& src){
    std::cout << YELLOW << "AForm assignment operator called" << RESET << std::endl;
    const_cast<std::string&>(this->_name) = src._name;//Not sure if we are supposed to force the change of those const members
    this->_signed_bool = src._signed_bool;
    const_cast<int&>(this->_grade_to_sign) = src._grade_to_sign;//
    const_cast<int&>(this->_grade_to_execute) = src._grade_to_execute;//
    return (*this);
}


std::ostream& operator<<(std::ostream& out, AForm& src){
    out << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
    out << YELLOW << "Form " << src.getName() << RESET << std::endl;
    out << YELLOW << "Grade to sign: " << src.getGradeToSign() << RESET << std::endl;
    out << YELLOW << "Grade to execute: " << src.getGradeToExecute() << RESET << std::endl;
    if (src.getSignedBool() == true)
        out << YELLOW << "Signature status: " << GREEN << "SIGNED" << RESET << std::endl;
    else
        out << YELLOW << "Signature status: " << RED << "UNSIGNED" << RESET << std::endl;
    out << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;
    return (out);
}

//GETTERS/SETTERS

std::string AForm::getName(){
    return (this->_name);
}
bool        AForm::getSignedBool() const{
    return (this->_signed_bool);
}
int         AForm::getGradeToSign() const{
    return (this->_grade_to_sign);
}
int         AForm::getGradeToExecute() const{
    return (this->_grade_to_execute);
}

std::string AForm::setName(std::string& name){
    const_cast<std::string&>(this->_name) = name;
}
bool        AForm::setSignedBool(bool b){
    this->_signed_bool = b;
}
int         AForm::setGradeToSign(int gts){
    const_cast<int&>(this->_grade_to_sign) = gts;
}
int         AForm::setGradeToExecute(int gte){
    const_cast<int&>(this->_grade_to_execute) = gte;
}

//FUNCTIONS

void        AForm::beSigned(Bureaucrat& br){
    if (br.getGrade() <= this->_grade_to_sign)
        this->_signed_bool = true;
    else
        throw(AForm::GradeTooLowException());
}

void        AForm::checkGrade( int grade )const{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}