/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:30 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/08 12:29:00 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    

    private:

    std::string _target;


};

#endif