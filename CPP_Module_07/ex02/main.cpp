/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:59:31 by grib              #+#    #+#             */
/*   Updated: 2025/01/21 14:50:28 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> intm(4);
    Array<int> inta(5);
    Array<int> intp(6);

    std::cout << "~~~~~~~~~~~PRINT DEFAULT ARRAY~~~~~~~~~~~" <<std::endl;
    inta.print_cell(inta,0);
    inta.print_cell(inta,1);
    inta.print_cell(inta,2);
    inta.print_cell(inta,3);
    inta.print_cell(inta,4);
    inta.print_cell(inta,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT MODIFY ARRAY~~~~~~~~~~~" <<std::endl;
    inta[0] = 5; 
    inta[1] = 4; 
    inta[2] = 3; 
    inta[3] = 2; 
    inta[4] = 1; 

    inta.print_cell(inta,0);
    inta.print_cell(inta,1);
    inta.print_cell(inta,2);
    inta.print_cell(inta,3);
    inta.print_cell(inta,4);
    inta.print_cell(inta,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT 4CELLS ARRAY~~~~~~~~~~~" <<std::endl;
    intm.print_cell(intm,0);
    intm.print_cell(intm,1);
    intm.print_cell(intm,2);
    intm.print_cell(intm,3);
    intm.print_cell(intm,4);
    intm.print_cell(intm,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT 6CELLS ARRAY~~~~~~~~~~~" <<std::endl;

    intp.print_cell(intp,0);
    intp.print_cell(intp,1);
    intp.print_cell(intp,2);
    intp.print_cell(intp,3);
    intp.print_cell(intp,4);
    intp.print_cell(intp,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~ASSIGNATION TO BASE ARRAY FOR 4CELLS AND 6CELLS~~~~~~~~~~~" <<std::endl;
    std::cout << std::endl;

    
    intm = inta;
    intp = inta;
    Array<int> intcpy(inta);

    std::cout << "~~~~~~~~~~~PRINT 4CELLS ARRAY~~~~~~~~~~~" <<std::endl;
    intm.print_cell(intm,0);
    intm.print_cell(intm,1);
    intm.print_cell(intm,2);
    intm.print_cell(intm,3);
    intm.print_cell(intm,4);
    intm.print_cell(intm,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT 6CELLS ARRAY~~~~~~~~~~~" <<std::endl;
    intp.print_cell(intp,0);
    intp.print_cell(intp,1);
    intp.print_cell(intp,2);
    intp.print_cell(intp,3);
    intp.print_cell(intp,4);
    intp.print_cell(intp,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT COPY ARRAY~~~~~~~~~~~" <<std::endl;
    intcpy.print_cell(intcpy,0);
    intcpy.print_cell(intcpy,1);
    intcpy.print_cell(intcpy,2);
    intcpy.print_cell(intcpy,3);
    intcpy.print_cell(intcpy,4);
    intcpy.print_cell(intcpy,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT BASE ARRAY~~~~~~~~~~~" <<std::endl;
    inta.print_cell(inta,0);
    inta.print_cell(inta,1);
    inta.print_cell(inta,2);
    inta.print_cell(inta,3);
    inta.print_cell(inta,4);
    inta.print_cell(inta,5);
    std::cout << std::endl;

    std::string str1("one");
    std::string str2("two");
    std::string str3("three");
    std::string str4("four");
    std::string str5("five");

    std::cout << "~~~~~~~~~~~CREATION STRING ARRAY~~~~~~~~~~~" <<std::endl;


    Array<std::string> stra(5);

    stra[0] = str1;
    stra[1] = str2;
    stra[2] = str3;
    stra[3] = str4;
    stra[4] = str5;


    std::cout << "~~~~~~~~~~~PRINT STRING ARRAY~~~~~~~~~~~" <<std::endl;

    stra.print_cell(stra,0);
    stra.print_cell(stra,1);
    stra.print_cell(stra,2);
    stra.print_cell(stra,3);
    stra.print_cell(stra,4);
    stra.print_cell(stra,5);
}
