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
    ShrubberyCreationForm(const std::string& target, const std::string& name);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    void createShrubbery();
    

    private:

    std::string _target;


};

#endif