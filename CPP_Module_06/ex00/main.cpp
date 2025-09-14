/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:29:51 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/14 15:36:55 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <regex.h>

int maintest();
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // maintest();
    if (argc == 2)
    {
        std::string entry = argv[1];
        ScalarConverter::convert(entry);
    }
    else
    std::cout << "Invalid number of arguments" << std::endl;
}

//  int maintest()
//  {
//     std::cout << "Test: a" << std::endl;
//     ScalarConverter::convert("a");
//     std::cout <<std::endl;


//     std::cout << "Test: 42.5" << std::endl;
//     ScalarConverter::convert("42.5");
//     std::cout <<std::endl;

//     std::cout << "Test: 2147483648" << std::endl;
//     ScalarConverter::convert("2147483648");
//     std::cout <<std::endl;

//     std::cout << "Test: 1.7976931348623157e+309" << std::endl;
//     ScalarConverter::convert("1.7976931348623157e+309");
//     std::cout <<std::endl;

//     std::cout << "Test: 9999999999999999.0" << std::endl;
//     ScalarConverter::convert("9999999999999999.0");
//     std::cout <<std::endl;

//     std::cout << "Test: 9999999999999999999999999999999999999999999999999999" << std::endl;
//     ScalarConverter::convert("9999999999999999999999999999999999999999999999999999");
//     std::cout <<std::endl;

//     std::cout << "Test: -.0f" << std::endl;
//     ScalarConverter::convert("-.0f");
//     std::cout <<std::endl;

//     std::cout << "Test: 0f" << std::endl;
//     ScalarConverter::convert("0f");
//     std::cout <<std::endl;

//     std::cout << "Test: 42" << std::endl;
//     ScalarConverter::convert("42");
//     std::cout <<std::endl;
    
//     std::cout << "Test: -42" << std::endl;
//     ScalarConverter::convert("-42");
//     std::cout <<std::endl;

//     std::cout << "Test: 3.14" << std::endl;
//     ScalarConverter::convert("3.14");
//     std::cout <<std::endl;

//     std::cout << "Test: -3.14" << std::endl;
//     ScalarConverter::convert("-3.14");
//     std::cout <<std::endl;

//     std::cout << "Test: 1.0f" << std::endl;
//     ScalarConverter::convert("1.0f");
//     std::cout <<std::endl;

//     std::cout << "Test: -1.0f" << std::endl;
//     ScalarConverter::convert("-1.0f");
//     std::cout <<std::endl;

//     std::cout << "Test: inf" << std::endl;
//     ScalarConverter::convert("inf");
//     std::cout <<std::endl;

//     std::cout << "Test: -inf" << std::endl;
//     ScalarConverter::convert("-inf");
//     std::cout <<std::endl;

//     std::cout << "Test: inff" << std::endl;
//     ScalarConverter::convert("inff");
//     std::cout <<std::endl;

//     std::cout << "Test: -inff" << std::endl;
//     ScalarConverter::convert("-inff");
//     std::cout <<std::endl;

//     std::cout << "Test: nan" << std::endl;
//     ScalarConverter::convert("nan");
//     std::cout <<std::endl;

//     std::cout << "Test: nanf" << std::endl;
//     ScalarConverter::convert("nanf");
//     std::cout <<std::endl;

//     std::cout << "Test: .123" << std::endl;
//     ScalarConverter::convert(".123");
//     std::cout <<std::endl;

//     std::cout << "Test: 123." << std::endl;
//     ScalarConverter::convert("123.");
//     std::cout <<std::endl;

//     std::cout << "Test: ." << std::endl;
//     ScalarConverter::convert(".");
//     std::cout <<std::endl;

//     std::cout << "Test: f" << std::endl;
//     ScalarConverter::convert("f");
//     std::cout <<std::endl;

//     std::cout << "Test: 3.4028235e39f" << std::endl;
//     ScalarConverter::convert("3.4028235e39f");
//     std::cout <<std::endl;

//     std::cout << "Test: 1.7976931348623157e309" << std::endl;
//     ScalarConverter::convert("1.7976931348623157e309");
//     std::cout <<std::endl;

//     std::cout << "Test: +0" << std::endl;
//     ScalarConverter::convert("+0");
//     std::cout <<std::endl;

//     std::cout << "Test: -0" << std::endl;
//     ScalarConverter::convert("-0");
//     std::cout <<std::endl;

//     std::cout << "Test: +inf" << std::endl;
//     ScalarConverter::convert("+inf");
//     std::cout <<std::endl;

//     std::cout << "Test: -infinity" << std::endl;
//     ScalarConverter::convert("-infinity");
//     std::cout <<std::endl;

//     std::cout << "Test: NaN" << std::endl;
//     ScalarConverter::convert("NaN");
//     std::cout <<std::endl;

//     std::cout << "Test: NANF" << std::endl;
//     ScalarConverter::convert("NANf");
//     std::cout <<std::endl;

//     std::cout << "Test: 123e10" << std::endl;
//     ScalarConverter::convert("123e10");
//     std::cout <<std::endl;

//     std::cout << "Test: 123e-10" << std::endl;
//     ScalarConverter::convert("123e-10");
//     std::cout <<std::endl;

//     std::cout << "Test: 123e+10" << std::endl;
//     ScalarConverter::convert("123e+10");
//     std::cout <<std::endl;

//     std::cout << "Test: 42.5f" << std::endl;
//     ScalarConverter::convert("42.5f");
//     std::cout <<std::endl;

//     std::cout << "Test: 0" << std::endl;
//     ScalarConverter::convert("0");
//     std::cout << std::endl;
    
//     std::cout << "Test: nan" << std::endl;
//     ScalarConverter::convert("nan");
//     std::cout << std::endl;

//     std::cout << "Test: 42.0f" << std::endl;
//     ScalarConverter::convert("42.0f");
//     std::cout << std::endl;

//     std::cout << "Test: abc" << std::endl;
//     ScalarConverter::convert("abc");//
//     std::cout <<std::endl;

//     std::cout << "Test: 3.14abc" << std::endl;
//     ScalarConverter::convert("3.14abc");//
//     std::cout <<std::endl;
    
//     std::cout << "Test: 123f.456" << std::endl;
//     ScalarConverter::convert("123f.456");//
//     std::cout <<std::endl;

//     std::cout << "Test: --42" << std::endl;
//     ScalarConverter::convert("--42");//
//     std::cout <<std::endl;

//     std::cout << "Test: +-42" << std::endl;
//     ScalarConverter::convert("+-42");//
//     std::cout <<std::endl;

//     std::cout << "Test: 123e" << std::endl;
//     ScalarConverter::convert("123e");//
//     std::cout <<std::endl;

//     std::cout << "Test:    42   " << std::endl;
//     ScalarConverter::convert("   42   ");//
//     std::cout <<std::endl;
    
//     std::cout << "Test: 123.45abc" << std::endl;
//     ScalarConverter::convert("123.45abc");//
//     std::cout <<std::endl;

//     std::cout << "Test: abc123.45" << std::endl;
//     ScalarConverter::convert("abc123.45");//
//     std::cout <<std::endl;

//     return 0;
//  }