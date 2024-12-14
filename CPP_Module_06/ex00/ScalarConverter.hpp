/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:31:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/14 10:11:47 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    public:

    static void convert(const std::string& str);

    private:

    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& src);


};


#endif