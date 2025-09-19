/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:05 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/19 16:33:24 by sylabbe          ###   ########.fr       */
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
    //Declaration variables
    Span test = Span(10);
    std::vector<int> vec;
    std::vector<int> vec2;
    srand (time(NULL));

    genVec(vec,4,100);
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end(); 

    genVec(vec2,7,100);
    std::vector<int>::iterator start2 = vec2.begin();
    std::vector<int>::iterator end2 = vec2.end(); 

    //Test 1
    fillT_s(start,end,test);
    test.printContainer();
    printSpan(test);
    std::cout << std::endl;
    
    fillT_s(start2,end2,test);
    test.printContainer();
    printSpan(test);

}