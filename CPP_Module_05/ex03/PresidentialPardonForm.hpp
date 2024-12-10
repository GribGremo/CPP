/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:30 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/10 16:16:12 by sylabbe          ###   ########.fr       */
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
    PresidentialPardonForm(const std::string& formname, const std::string& target);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

    std::string getTarget();
    
    void execute(Bureaucrat const & executor) const;
    void executePresidentialPardon() const;
    void checkGranted(Bureaucrat const & executor) const;
    void checkSigned() const;
    void pform();

    private:

    std::string _target;
};

#endif