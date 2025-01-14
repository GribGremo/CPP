/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:59:31 by grib              #+#    #+#             */
/*   Updated: 2025/01/14 19:49:45 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void print_cell(Array<int>& a, int i);
void print_cell(Array<std::string>& a, int i);

int main() {
    // int * a = new int();
    // *a = 1;
    // std::cout << *a <<std::endl;
    Array<int> intm(4);
    Array<int> inta(5);
    Array<int> intp(6);

    std::cout << "~~~~~~~~~~~PRINT DEFAULT ARRAY~~~~~~~~~~~" <<std::endl;
    print_cell(inta,0);
    print_cell(inta,1);
    print_cell(inta,2);
    print_cell(inta,3);
    print_cell(inta,4);
    print_cell(inta,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT MODIFY ARRAY~~~~~~~~~~~" <<std::endl;
    inta[0] = 5; 
    inta[1] = 4; 
    inta[2] = 3; 
    inta[3] = 2; 
    inta[4] = 1; 

    print_cell(inta,0);
    print_cell(inta,1);
    print_cell(inta,2);
    print_cell(inta,3);
    print_cell(inta,4);
    print_cell(inta,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT 4CELLS ARRAY~~~~~~~~~~~" <<std::endl;
    print_cell(intm,0);
    print_cell(intm,1);
    print_cell(intm,2);
    print_cell(intm,3);
    print_cell(intm,4);
    print_cell(intm,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT 6CELLS ARRAY~~~~~~~~~~~" <<std::endl;

    print_cell(intp,0);
    print_cell(intp,1);
    print_cell(intp,2);
    print_cell(intp,3);
    print_cell(intp,4);
    print_cell(intp,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~ASSIGNATION TO BASE ARRAY FOR 4CELLS AND 6CELLS~~~~~~~~~~~" <<std::endl;
    std::cout << std::endl;

    
    intm = inta;
    intp = inta;
    Array<int> intcpy(inta);

    std::cout << "~~~~~~~~~~~PRINT 4CELLS ARRAY~~~~~~~~~~~" <<std::endl;
    print_cell(intm,0);
    print_cell(intm,1);
    print_cell(intm,2);
    print_cell(intm,3);
    print_cell(intm,4);
    print_cell(intm,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT 6CELLS ARRAY~~~~~~~~~~~" <<std::endl;
    print_cell(intp,0);
    print_cell(intp,1);
    print_cell(intp,2);
    print_cell(intp,3);
    print_cell(intp,4);
    print_cell(intp,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT COPY ARRAY~~~~~~~~~~~" <<std::endl;
    print_cell(intcpy,0);
    print_cell(intcpy,1);
    print_cell(intcpy,2);
    print_cell(intcpy,3);
    print_cell(intcpy,4);
    print_cell(intcpy,5);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~PRINT BASE ARRAY~~~~~~~~~~~" <<std::endl;
    print_cell(inta,0);
    print_cell(inta,1);
    print_cell(inta,2);
    print_cell(inta,3);
    print_cell(inta,4);
    print_cell(inta,5);
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

    print_cell(stra,0);
    print_cell(stra,1);
    print_cell(stra,2);
    print_cell(stra,3);
    print_cell(stra,4);
    print_cell(stra,5);
}

void print_cell(Array<int>& a, int i){
    try{
        std::cout << a[i] << std::endl;
    }
    catch(const std::exception&){
        std::cout << "Invalid index" << std::endl;
    }
}

void mod_cell(Array<int>& a, int i, int x){
    try{
        a[i] = x;
    }
    catch(const std::exception&){
        std::cout << "Invalid index" << std::endl;
    }
}

void print_cell(Array<std::string>& a, int i){
    try{
        std::cout << a[i] << std::endl;
    }
    catch(const std::exception&){
        std::cout << "Invalid index" << std::endl;
    }
}
