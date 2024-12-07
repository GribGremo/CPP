/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:13 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/07 16:30:12 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR
Bureaucrat::Bureaucrat(): _name("Drudge"), _grade(150){
    std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name), _grade(src._grade){
    std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
}
Bureaucrat::Bureaucrat(const int grade, const std::string& name): _name(name), _grade(grade){
    std::cout << GREEN << "Bureaucrat custom constructor called" << RESET << std::endl;
    checkGrade(this->_grade);
}

Bureaucrat::~Bureaucrat(){
    std::cout << GREEN << "Bureaucrat destructor called" << RESET << std::endl;
}

//OPERATORS
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src){
    std::cout << GREEN << "Bureaucrat assigment operator called" << RESET << std::endl;
    const_cast<std::string&>(this->_name) = src._name;//TO SEE
    this->_grade = src._grade;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src){
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return (out);
}

//GETTERS/SETTERS
 int Bureaucrat::getGrade() const{
    return (this->_grade);
}
 std::string Bureaucrat::getName() const{
    return (this->_name);
}

//METHODS
void Bureaucrat::incGrade(){
    try{
        checkGrade(this->_grade - 1);
    }
    catch(const Bureaucrat::GradeTooHighException& e){
        throw ;
    }
    this->_grade--;
}
void Bureaucrat::decGrade(){
    try{
        checkGrade(this->_grade + 1);
    }
    catch(const Bureaucrat::GradeTooLowException& e){
        throw ;
    }
    this->_grade++;
}

void Bureaucrat::checkGrade( int grade )const{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form& fm){
    try{
        fm.beSigned(*this);
    }
    catch(Form::GradeTooLowException& e){
        std::cout << this->_name << " couldn't sign " << fm.getName() << " because " << e.what() << std::endl;
    }
    std::cout << this->_name << " signed " << fm.getName() << std::endl;
}