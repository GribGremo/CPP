/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:37:36 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/07 16:28:47 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


#define YELLOW "\033[33m"
#define RESET "\033[0m"

//CONSTRUCTOR/DESTRUCTOR

Form::Form(): _name("Default_name"), _signed_bool(false), _grade_to_sign(150), _grade_to_execute(150){
    std::cout << YELLOW << "Form default constructor called" << RESET << std::endl;

}
Form::Form(const Form& src): _name(src._name), _signed_bool(src._signed_bool), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute){
    std::cout << YELLOW << "Form copy constructor called" << RESET << std::endl;
}
Form::Form(std::string& name, int grade_to_sign, int grade_to_execute): _name(name), _signed_bool(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute){
    std::cout << YELLOW << "Form custom constructor called" << RESET << std::endl;
    checkGrade(_grade_to_execute);
    checkGrade(_grade_to_sign);
}
Form::~Form(){
    std::cout << YELLOW << "Form destructor called" << RESET << std::endl;
}

//OPERATOR

Form&       Form::operator=(const Form& src){
    std::cout << YELLOW << "Form assignment operator called" << RESET << std::endl;
    const_cast<std::string&>(this->_name) = src._name;//Not sure if we are supposed to force the change of those const members
    this->_signed_bool = src._signed_bool;
    const_cast<int&>(this->_grade_to_sign) = src._grade_to_sign;//
    const_cast<int&>(this->_grade_to_execute) = src._grade_to_execute;//
}

//GETTERS/SETTERS

std::string Form::getName(){
    return (this->_name);
}
bool        Form::getSignedBool(){
    return (this->_signed_bool);
}
int   Form::getGradeToSign(){
    return (this->_grade_to_sign);
}
int   Form::getGradeToExecute(){
    return (this->_grade_to_execute);
}

//FUNCTIONS

void        Form::beSigned(Bureaucrat& br){
    if (br.getGrade() <= this->_grade_to_sign)
        this->_signed_bool = true;
    else
        throw(Form::GradeTooLowException());
}

void        Form::checkGrade( int grade )const{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}