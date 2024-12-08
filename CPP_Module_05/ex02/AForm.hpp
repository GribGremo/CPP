/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:55:48 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/08 13:29:49 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class AForm{
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


    AForm();
    AForm(const AForm& src);
    AForm(const std::string& name, int grade_to_sign, int grade_to_execute);//Const std::string& allow me to send "defaultname" in derived
    virtual ~AForm();
    
    AForm& operator=(const AForm& src);

    std::string getName();
    bool        getSignedBool();
    int         getGradeToSign();
    int         getGradeToExecute();

    void        beSigned(Bureaucrat& br);
    void        checkGrade( int grade )const;
    void        execute(Bureaucrat const & executor);

    private:

    const std::string   _name;
    bool                _signed_bool;
    const int           _grade_to_sign;
    const int           _grade_to_execute;
};


#endif