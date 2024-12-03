/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/03 16:17:15 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception> 


class Bureaucrat
{
    class GradeTooHighException : public std::exception {
        private:
        std::string message;

        public:
        GradeTooHighException(const std::string& msg) : message(msg) {}// PAS NECESSAIRE

        virtual const char* what() const throw() {
            return message.c_str();
        }
    };
    
    class GradeTooLowException : public std::exception {
        private:
        std::string message;

        public:
        GradeTooLowException(const std::string& msg) : message(msg) {}

        virtual const char* what() const throw() {
            return message.c_str();
        }
    };

    public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat(const int grade, const std::string& name);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& src);

    int getGrade() const ;
    std::string getName() const;

    void incGrade() ;//inverse grade 1 top
    void decGrade() ;

    private:
    const std::string _name;
    int _grade; 

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif