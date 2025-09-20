/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:05 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/19 21:32:30 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <climits>
/*OK subject is unclear, "a single number" might be interpreted as a unic number or one number only.
 The two iterators method seem after few research "impossible" to secure, you could have revert 1st an 2nd iterator or even have iterators from different container(not good)*/
std::vector<int>& genVec(std::vector<int>& vec, unsigned int n, unsigned int range){
    
    for(unsigned int i = 0; i < n; i++){
        vec.push_back(rand() % range);
    }
    return (vec);
}

void printSpan(Span& sp){
    try{
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Not enough value to calculate Span" << std::endl;
    }
    try{
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Not enough value to calculate Span" << std::endl;
    }
}
void fillT_s( std::vector<int>::iterator& start,  std::vector<int>::iterator& end, Span& sp){
    try{
        sp.fillT(start,end);
    }
    catch(std::exception& e){
        std::cout << "Cannot fill Span with entire range" << std::endl;
    }
}

int main(){

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    // Span test = Span(10);
    // std::vector<int> vec;
    // std::vector<int> vec2;
    // std::vector<int> vec3;

    // srand (time(NULL));

    // genVec(vec,0,100);
    // std::vector<int>::iterator start = vec.begin();
    // std::vector<int>::iterator end = vec.end(); 

    // genVec(vec2,5,100);
    // std::vector<int>::iterator start2 = vec2.begin();
    // std::vector<int>::iterator end2 = vec2.end(); 
    
    // genVec(vec3,15000,100);
    // std::vector<int>::iterator start3 = vec3.begin();
    // std::vector<int>::iterator end3 = vec3.end(); 

    // //Test 1
    // fillT_s(start,end,test);
    // test.printContainer();
    // printSpan(test);
    
    // std::cout << std::endl;
    
    // fillT_s(start2,end2,test);
    // test.printContainer();
    // printSpan(test);
        
    // std::cout << std::endl;
    
    // fillT_s(start3,end3,test);
    // test.printContainer();
    // printSpan(test);
}