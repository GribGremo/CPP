/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:49 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/31 09:27:45 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


//~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~
RPN::RPN(){}

RPN::RPN(const RPN& src): _numbers(src._numbers), _str(src._str){}

RPN::RPN(const std::string str): _str(str){
    execRPN();
}

RPN::~RPN(){}

//~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~
RPN& RPN::operator=(const RPN& src){
    if(this == &src)
        return (*this);
    _numbers = src._numbers;
    return (*this);
}

//~~~~~~~~~~~~~~UTILS~~~~~~~~~~~~~~

template <typename T>
void clearStack(std::stack<T>& st){
    while(!st.empty())
        st.pop();
}

//~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~

bool RPN::handleError(int idx, const std::string& reason){
    std::string errMess;
    std::string error = "Error";
    std::string sep = ": ";
    size_t n = 0;

    if (idx >= 0)
        n = error.size() + 2 * sep.size() + reason.size() + idx;
    else
        n = -1;
    errMess = error + sep + reason + sep + _str;
    for(size_t i = 0; i < errMess.size(); i++)
    {
        if(i == n)
            std::cerr <<  "\033[31m" << errMess[i] << "\033[0m";
        else
            std::cerr << errMess[i];
    }
    std::cerr << std::endl;
    clearStack(_numbers);
    _str.erase();
    return (false);
}

bool RPN::parseLine(){
    for (size_t i = 0; i != _str.size();i++){
        if (i % 2 == 1 && (_str[i] != ' ' || i + 1 == _str.size()))
            return handleError(i,"Invalid format received");//return (false);
        else if (i % 2 == 0 && !isdigit(_str[i]) && _str[i] != '+' && _str[i] != '-' && _str[i] != '*' && _str[i] != '/')
            return handleError(i,"Invalid format received");//return (false);
    }
    return (true);
}

bool RPN::operate(char c, int i)
{
    int two = _numbers.top();
    _numbers.pop();
    int one = _numbers.top();
    _numbers.pop();

    long int res = 0;
    if (c == '+')
        res = one + two;
    else if (c == '*')
        res = one * two;
    else if (c == '-')
        res = one - two;
    else if (c == '/')
    {
        if (two == 0)
            return handleError(i,"Division by zero");//return (false);
        res = one / two;
    }
    if (res < INT_MIN || res > INT_MAX)
        return handleError(-1,"Overflow");//return (false);
    _numbers.push(res);
    return (true);
}

bool RPN::execRPN(){
    std::string c;
    if (!parseLine())
        return (false);
    for (size_t i = 0; i < _str.size();i += 2){
        if (_str[i] == '+' || _str[i] == '-' || _str[i] == '*' || _str[i] == '/')
        {
            if (_numbers.size() < 2)
                return handleError(i,"Missing number to operate");//std::cerr << "ERROR" << std::endl;
            if (!operate(_str[i], i))
                return (false);
        }
        else if (isdigit(_str[i]))
        {
            c = _str[i];
            _numbers.push(strtol(c.c_str(),NULL,10));//A voir
        }
    }
    if (_numbers.size() != 1)
        return handleError(-1,"Invalid format received");
    return (true);
}

void RPN::printResult(){
    if (_numbers.size() == 1)
        std::cout << "Result: " << _numbers.top() <<std::endl;
    else
        std::cout << "No result available" << std::endl;
}
