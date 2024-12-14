/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:29:51 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/14 14:34:17 by sylabbe          ###   ########.fr       */
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
    std::string t1 = "a";
    std::string t2 = "0";
    std::string t3 = "0.0";
    std::string t4 = "0.0f";

    std::string t5 = "";

    std::string t6 = "aa";

    std::string t7 = ".00f";
    std::string t8 = "00.f";
    std::string t9 = "00f.";
    std::string t10 = "00f.";
    std::string t11 = "0.0ff";
    std::string t12 = "0..0f";


    std::string t13 = "00.";
    std::string t14 = ".00";
    std::string t15 = "0..0";

    std::cout << t1 << std::endl;
    ScalarConverter::convert(t1);
    std::cout << t2 << std::endl;
    ScalarConverter::convert(t2);
    std::cout << t3 << std::endl;
    ScalarConverter::convert(t3);
    std::cout << t4 << std::endl;
    ScalarConverter::convert(t4);
    std::cout << t5 << std::endl;
    ScalarConverter::convert(t5);
    std::cout << t6 << std::endl;
    ScalarConverter::convert(t6);
    std::cout << t7 << std::endl;
    ScalarConverter::convert(t7);
    std::cout << t8 << std::endl;
    ScalarConverter::convert(t8);
    std::cout << t9 << std::endl;
    ScalarConverter::convert(t9);
    std::cout << t10 << std::endl;
    ScalarConverter::convert(t10);
    std::cout << t11 << std::endl;
    ScalarConverter::convert(t11);
    std::cout << t12 << std::endl;
    ScalarConverter::convert(t11);
    std::cout << t13 << std::endl;
    ScalarConverter::convert(t11);
    std::cout << t14 << std::endl;
    ScalarConverter::convert(t11);
    std::cout << t15 << std::endl;
    ScalarConverter::convert(t11);
    
    return 0;
 }