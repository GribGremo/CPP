/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/08 12:51:24 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception> 

class AForm;
class Bureaucrat
{

    public:

    class GradeTooHighException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Grade too high, max. grade 1";
        }
    };
    
    class GradeTooLowException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Grade too low, min. grade 150";
        }
    };

    Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat(const int grade, const std::string& name);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& src);

    int getGrade() const ;
    std::string getName() const;

    void incGrade() ;
    void decGrade() ;
    void signForm(AForm& fm);
    void executeForm(AForm const & form);
    void checkGrade( int grade )const;


    private:
    const std::string _name;
    int _grade; 

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif