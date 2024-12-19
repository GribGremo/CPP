/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:29:51 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/19 18:54:34 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int maintest();
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    maintest();
    // if (argc == 2)
    // {
    //     std::string entry = argv[1];
    //     ScalarConverter::convert(entry);

    // }
    // else
    // std::cout << "Invalid number of arguments" << std::endl;
}

 int maintest()
 {
    ScalarConverter::convert("42");
    std::cout <<std::endl;
    ScalarConverter::convert("-42");
    std::cout <<std::endl;

    ScalarConverter::convert("3.14");
    std::cout <<std::endl;

    ScalarConverter::convert("-3.14");
    std::cout <<std::endl;

    ScalarConverter::convert("1.0f");
    std::cout <<std::endl;

    ScalarConverter::convert("-1.0f");
    std::cout <<std::endl;

    ScalarConverter::convert("inf");
    std::cout <<std::endl;

    ScalarConverter::convert("-inf");
    std::cout <<std::endl;

    ScalarConverter::convert("inff");
    std::cout <<std::endl;

    ScalarConverter::convert("-inff");
    std::cout <<std::endl;

    ScalarConverter::convert("nan");
    std::cout <<std::endl;

    ScalarConverter::convert("nanf");
    std::cout <<std::endl;

    ScalarConverter::convert("abc");
    std::cout <<std::endl;

    ScalarConverter::convert("3.14abc");
    std::cout <<std::endl;

    ScalarConverter::convert("123f.456");
    std::cout <<std::endl;

    ScalarConverter::convert("--42");
    std::cout <<std::endl;

    ScalarConverter::convert("+-42");
    std::cout <<std::endl;

    ScalarConverter::convert(".123");
    std::cout <<std::endl;

    ScalarConverter::convert("123.");
    std::cout <<std::endl;

    ScalarConverter::convert(".");
    std::cout <<std::endl;

    ScalarConverter::convert("f");
    std::cout <<std::endl;

    ScalarConverter::convert("3.4028235e39f");
    std::cout <<std::endl;

    ScalarConverter::convert("1.7976931348623157e309");
    std::cout <<std::endl;

    ScalarConverter::convert("+0");
    std::cout <<std::endl;

    ScalarConverter::convert("-0");
    std::cout <<std::endl;

    ScalarConverter::convert("+inf");
    std::cout <<std::endl;

    ScalarConverter::convert("-infinity");
    std::cout <<std::endl;

    ScalarConverter::convert("NaN");
    std::cout <<std::endl;

    ScalarConverter::convert("NANf");
    std::cout <<std::endl;

    ScalarConverter::convert("   42   ");
    std::cout <<std::endl;
    
    ScalarConverter::convert("123.45abc");
    std::cout <<std::endl;

    ScalarConverter::convert("abc123.45");
    std::cout <<std::endl;

    ScalarConverter::convert("123e10");
    std::cout <<std::endl;

    ScalarConverter::convert("123e-10");
    std::cout <<std::endl;

    ScalarConverter::convert("123e+10");
    std::cout <<std::endl;

    ScalarConverter::convert("123e");
    std::cout <<std::endl;

    ScalarConverter::convert("42.5f");
    std::cout <<std::endl;

    // ScalarConverter::convert("0");
    // std::cout << std::endl;
    
    // ScalarConverter::convert("nan");
    // std::cout << std::endl;

    // ScalarConverter::convert("42.0f");
    // std::cout << std::endl;







    // std::string t1 = "a";
    // std::string t2 = "-2147483649";
    // std::string t3 = "179769313486231570000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0";
    // std::string t4 = "0.0f";

    // std::string t5 = "";

    // std::string t6 = "aa";

    // std::string t7  = ".00f"    ;
    // std::string t8  = "00.f"    ;
    // std::string t9  = "00f."    ;
    // std::string t10 = "00f."    ;
    // std::string t11 = "0.0ff"   ;
    // std::string t12 = "0..0f"   ;


    // std::string t13 = "00.";
    // std::string t14 = ".00";
    // std::string t15 = "0..0";

    // std::cout << "Base: " << t1 << std::endl;
    // ScalarConverter::convert(t1);
    // std::cout << std::endl;

    // std::cout << "Base: " << t2 << std::endl;
    // ScalarConverter::convert(t2);
    // std::cout << std::endl;

    // std::cout << "Base: " << t3 << std::endl;
    // ScalarConverter::convert(t3);
    // std::cout << std::endl;

    // std::cout << "Base: " << t4 << std::endl;
    // ScalarConverter::convert(t4);
    // std::cout << std::endl;

    // std::cout << "Base: " << t5 << std::endl;
    // ScalarConverter::convert(t5);
    // std::cout << std::endl;

    // std::cout << "Base: " << t6 << std::endl;
    // ScalarConverter::convert(t6);
    // std::cout << std::endl;

    // std::cout << "Base: " << t7 << std::endl;
    // ScalarConverter::convert(t7);
    // std::cout << std::endl;

    // std::cout << "Base: " << t8 << std::endl;
    // ScalarConverter::convert(t8);
    // std::cout << std::endl;

    // std::cout << "Base: " << t9 << std::endl;
    // ScalarConverter::convert(t9);
    // std::cout << std::endl;

    // std::cout << "Base: " << t10 << std::endl;
    // ScalarConverter::convert(t10);
    // std::cout << std::endl;

    // std::cout << "Base: " << t11 << std::endl;
    // ScalarConverter::convert(t11);
    // std::cout << std::endl;

    // std::cout << "Base: " << t12 << std::endl;
    // ScalarConverter::convert(t12);
    // std::cout << std::endl;

    // std::cout << "Base: " << t13 << std::endl;
    // ScalarConverter::convert(t13);
    // std::cout << std::endl;

    // std::cout << "Base: " << t14 << std::endl;
    // ScalarConverter::convert(t14);
    // std::cout << std::endl;

    // std::cout << "Base: " << t15 << std::endl;
    // ScalarConverter::convert(t15);
    
    return 0;
 }