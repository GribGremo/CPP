/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:36 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/08 12:26:45 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    

    private:

    std::string _target;


};

#endif