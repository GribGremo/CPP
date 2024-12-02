/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:13 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/02 17:59:37 by sylabbe          ###   ########.fr       */
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

}
void Bureaucrat::decGrade(){


}