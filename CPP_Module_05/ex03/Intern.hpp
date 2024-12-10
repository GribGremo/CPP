/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:26:49 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/10 15:50:09 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include "AForm.hpp"

class Intern
{
    public:

    Intern();
    Intern(const Intern& src);
    ~Intern();

    Intern& operator=(const Intern& src);

    AForm* makeForm(const std::string& formname, const std::string& target);

    private:

    std::string array[3];
};

#endif