/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:55 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/06 21:23:24 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "PmergeMe.hpp"

/*Print final result as requested by the subject
Optional:
    std::cout << "Number of comparisons: " << lst.getCountCmp() << " (list)"<< std::endl;
    std::cout << "Number of comparisons: " << vec.getCountCmp() << " (vector)"<< std::endl;
*/
void printFJ(PmergeMe<std::vector>& vec, PmergeMe<std::list>& lst){
    if (vec.empty() || lst.empty())
    {
        std::cout << "No result to print" <<std::endl;
        return ;
    }
    PmergeMe<std::vector>::result rVec = vec.getRes();
    PmergeMe<std::list>::result rLst = lst.getRes(); 
    std::cout << "Before:" ;
    vec.printCont(rVec.unsorted);

    std::cout << "After: ";
    vec.printCont(rVec.sorted);

    std::cout << "Time to process a range of " << rVec.unsorted.size() << " elements with " << rVec.containerType << " : " << rVec.execTime << " " << rVec.unitTime << std::endl;
    std::cout << "Time to process a range of " << rLst.unsorted.size() << " elements with " << rLst.containerType << " : " << rLst.execTime << " " << rLst.unitTime << std::endl;
    std::cout << "Number of comparisons: " << lst.getCountCmp() /*<< " (list)"*/<< std::endl;
    std::cout << "Number of comparisons: " << vec.getCountCmp() /*<< " (vector)"*/<< std::endl;
}

int main(int argc, char **argv){
    (void)argc;
    (void)argv;

    PmergeMe<std::vector> vec;
    PmergeMe<std::list> list;
    try {
        vec = PmergeMe<std::vector>(argc,argv);
        list = PmergeMe<std::list>(argc,argv);
    }
    catch(const std::exception& e)
    {
        return (1);
    }
    std::cout << "~~~~~~~~~~~~~~~Main Test~~~~~~~~~~~~~~~" <<std::endl;
    printFJ(vec,list);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~~~~~operator= Test~~~~~~~~~~~~~~~" <<std::endl;
    PmergeMe<std::vector> testVec = vec;
    PmergeMe<std::list> testLst = list;
    printFJ(testVec,testLst);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~~~~~copy constructor Test~~~~~~~~~~~~~~~" <<std::endl;
    PmergeMe<std::vector> testVec2(vec);
    PmergeMe<std::list> testLst2(list);
    printFJ(testVec2,testLst2);


}

