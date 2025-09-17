/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:59:31 by grib              #+#    #+#             */
/*   Updated: 2025/09/17 11:01:25 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "test.hpp"
int main() {    
    Array<int> intm;
    Array<int> inta;
    Array<int> intp;
    const Array<int> cons(5);
    
    try{
        Array<int> a(4);
        Array<int> b(5);
        Array<int> c(6);

        intm = a;
        inta = b;
        intp = c;
        std::cout << "~~~~~~~~~~~PRINT ARRAY~~~~~~~~~~~" <<std::endl;
    
        intm.printArray(); // ALL SET UP 0; 4,5,6CELLS
        inta.printArray();
        intp.printArray();

        std::cout << "~~~~~~~~~~~INIT CELLS INTA~~~~~~~~~~~" <<std::endl;

        try{
            int j = 5;
            for (int i = 0; i < 7; i++){
                std::cout << "Init cell " << i << ": ";
                inta[i] = j;
                std::cout << inta[i] << std::endl;
                j--;
            }
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "~~~~~~~~~~~INIT CELLS INTM~~~~~~~~~~~" <<std::endl;

        try{
            for (int i = 0; i < 7; i++){
                std::cout << "Init cell " << i << ": ";
                intm[i] = 8;
                std::cout << intm[i] << std::endl;
            }
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "~~~~~~~~~~~INIT CELLS INTP~~~~~~~~~~~" <<std::endl;

        try{
            for (int i = 0; i < 7; i++){
                std::cout << "Init cell " << i << ": ";
                intp[i] = 100;
                std::cout << intp[i] << std::endl;
            }
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "~~~~~~~~~~~PRINT ARRAY MODIFY~~~~~~~~~~~" <<std::endl;
        std::cout << "Size: " << intm.size() << std::endl;
        intm.printArray();//SET UP 8,4CELLS
        std::cout << "Size: " << inta.size() << std::endl;
        inta.printArray();//SET UP 54321,5 CELLS
        std::cout << "Size: " << intp.size() << std::endl;
        intp.printArray();//SET UP 100, 6CELLS
        std::cout << "Size: " << cons.size() << std::endl;
        cons.printArray();
        std::cout << "~~~~~~~~~~~ASSIGNATION/COPY CELL MOD~~~~~~~~~~~" <<std::endl;
        std::cout << std::endl;
    
        intm = inta;
        intp = inta;
        Array<int> intcpy(inta);
        try{
            intm[4] = 20;
            intp[0] = intm[4];
            intcpy[4] = 12;
            intcpy[3] = intm[4] + intp[0];
            intcpy[2] = intm[4] + cons[0] + 1 + cons[4];

            intcpy[12] = 4;//INVALID WILL BE CATCH
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
        }

        std::cout << "~~~~~~~~~~~PRINT ARRAY MODIFY~~~~~~~~~~~" <<std::endl;
        std::cout << "Size: " << intm.size() << std::endl;
        intm.printArray();
        std::cout << "Size: " <<inta.size() << std::endl;
        inta.printArray();
        std::cout << "Size: " <<intp.size() << std::endl;
        intp.printArray();   
        std::cout << "Size: " <<intcpy.size() << std::endl;
        intcpy.printArray();


        //INIT STRINGS
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
    
        stra.printArray();
    }
    catch(...){
        std::cout << "AN ERROR OCCURED" << std::endl;
    }
}
