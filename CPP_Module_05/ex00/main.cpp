/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/03 16:00:56 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob(1, "bob");
        Bureaucrat steve(150, "steve");
        Bureaucrat bernard(0, "bernard");
        Bureaucrat andre(151, "andre");
    }
    catch (const GradeTooLowException& e)
    {
        std::cout  << "Grade too low, min. grade 150" <<std::endl;
    }
    catch (const GradeTooHighException& e)
    {
        std::cout  << "Grade too high, max. grade 1" <<std::endl;
    }


}