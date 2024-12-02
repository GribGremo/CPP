/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/02 18:01:10 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
# include <string>

class Bureaucrat
{
    public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
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