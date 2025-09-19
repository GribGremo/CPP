/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:05 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/18 23:23:56 by grib             ###   ########.fr       */
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
std::vector<int>& genVec(std::vector<int>& vec, unsigned int n){
    
    for(unsigned int i = 0; i < n; i++){
        vec.push_back(rand() % UINT_MAX);
    }
    return (vec);
}

int main(){
    Span test = Span(10);//VERIFIER IL FAUT LIMITE AVEC FILLT
    std::vector<int> vec;
    std::vector<int> vec2;
    srand (time(NULL));

    genVec(vec,10);
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end(); 
    test.fillT(start,end);
    
    genVec(vec2,10);
    std::vector<int>::iterator start2 = vec2.begin();
    std::vector<int>::iterator end2 = vec2.end(); 
    test.fillT(start2,end2);

    // test.addNumber(-64);
    // test.addNumber(-63);
    // test.addNumber(-80);
    // test.addNumber(-800);
    // test.addNumber(-1890);

    // try{
    //     for (int i = 0; i < 5; i++)
    //         test.addNumber(i);
    // }
    // catch(std::exception& e){
    //     std::cout << "Max size of container: No more slot" << std::endl;
    // }
    for (std::multiset<int>::iterator it = test.getT().begin(); it != test.getT().end(); it++)
        std::cout << *it << std::endl;
    try{
        std::cout << "Longest Span: " << test.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << test.shortestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Not enough value to calculate Span" << std::endl;
    }
}