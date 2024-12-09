/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:55:48 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/09 15:46:08 by sylabbe          ###   ########.fr       */
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

    class UngrantedException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Executor grade too low to execute form";
        }
    };
    
    class UnsignedFormException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Unsigned form, can't execute it";
        }
    };


    AForm();
    AForm(const AForm& src);
    AForm(const std::string& name, int grade_to_sign, int grade_to_execute);//Const std::string& allow me to send "defaultname" in derived even if seeking for a reference
    virtual             ~AForm();
    
    AForm&              operator=(const AForm& src);

    std::string         getName();
    bool                getSignedBool() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    void                beSigned(Bureaucrat& br);
    void                checkGrade( int grade )const;
    virtual void        execute(Bureaucrat const & executor) const = 0;

    protected:  

    std::string         setName(std::string& name);// On protected to limit access to derived methods
    bool                setSignedBool(bool b);
    int                 setGradeToSign(int gts);
    int                 setGradeToExecute(int gte);

    private:

    const std::string   _name;
    bool                _signed_bool;
    const int           _grade_to_sign;
    const int           _grade_to_execute;
};


#endif