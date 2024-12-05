/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/05 13:15:32 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception> 


class Bureaucrat
{

    public:

    class GradeTooHighException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Invalid grade: Grade too high, max. grade 1";
        }
    };
    
    class GradeTooLowException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Invalid grade: Grade too low, min. grade 150";
        }
    };

    Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat(const int grade, const std::string& name);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& src);

    int getGrade() const ;
    std::string getName() const;
    void checkGrade()const;

    void incGrade() ;//inverse grade 1 top
    void decGrade() ;


    private:
    const std::string _name;
    int _grade; 

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif