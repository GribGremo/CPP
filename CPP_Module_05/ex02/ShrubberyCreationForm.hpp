/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:43 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/08 12:54:57 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

    std::string getTarget();

    void execute(Bureaucrat const & executor) const;
    void executeShrubbery() const;
    void checkGranted(Bureaucrat const & executor) const;
    void checkSigned(Bureaucrat const & executor) const;

    private:

    std::string _target;


};

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm& src);

#endif