/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:13 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/03 15:58:55 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

//CONSTRUCTORS/DESTRUCTOR
Bureaucrat::Bureaucrat(){
    std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& src){
    std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
}
Bureaucrat::Bureaucrat(const int grade, const std::string& name): _grade(grade), _name(name){
    std::cout << GREEN << "Bureaucrat custom constructor called" << RESET << std::endl;
    // try
    // {
        if (_grade < 1)
            throw GradeTooHighException("Grade too high, max. grade 1");
        else if (_grade > 150)
            throw GradeTooLowException("Grade too low, min. grade 150");
    // }
    // catch (const GradeTooLowException& e)
    // {
    //     std::cout << GREEN << "Grade too low, min. grade 150" <<std::endl;
    // }
    // catch (const GradeTooHighException& e)
    // {
    //     std::cout << GREEN << "Grade too high, max. grade 1" <<std::endl;
    // }
}

Bureaucrat::~Bureaucrat(){
    std::cout << GREEN << "Bureaucrat destructor called" << RESET << std::endl;
}

//OPERATORS
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src){
    std::cout << GREEN << "Bureaucrat assigment operator called" << RESET << std::endl;
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
    this->_grade--;
    if (_grade < 1)
        throw GradeTooHighException("Grade too high, max. grade 1");
    else if (_grade > 150)
        throw GradeTooLowException("Grade too low, min. grade 150");
}
void Bureaucrat::decGrade(){
    this->_grade++;
    if (_grade < 1)
        throw GradeTooHighException("Grade too high, max. grade 1");
    else if (_grade > 150)
        throw GradeTooLowException("Grade too low, min. grade 150");
}