/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:52 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/31 08:56:10 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <climits>
#include <iostream>
#include <stack>

#ifndef RPN_HPP
#define RPN_HPP

class RPN
{
    //~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~
    public:
    RPN();
    RPN(const RPN& src);
    RPN(const std::string str);
    ~RPN();

    //~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~
    public:
    RPN& operator=(const RPN& src);

    //~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~
    private:
    std::stack<int> _numbers;
    std::string _str;

    //~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~
    private:

    bool handleError(int idx, const std::string& reason);
    bool parseLine();
    bool operate(char c, int i);
    bool execRPN();

    public:
    void printResult();

};

#endif