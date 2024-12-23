/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:37:38 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/08 11:41:46 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form{
    public:

    class GradeTooHighException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Grade too high";
        }
    };
    
    class GradeTooLowException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Grade too low";
        }
    };

    Form();
    Form(const Form& src);
    Form(std::string& name, int grade_to_sign, int grade_to_execute);
    ~Form();

    Form&       operator=(const Form& src);

    std::string getName();
    bool        getSignedBool();
    int         getGradeToSign();
    int         getGradeToExecute();

    void        beSigned(Bureaucrat& br);
    void        checkGrade( int grade )const;

    private:

    const std::string   _name;
    bool                _signed_bool;
    const int           _grade_to_sign;
    const int           _grade_to_execute;

};

std::ostream& operator<<(std::ostream& out, Form& src);

#endif