/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:55 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/03 15:40:58 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <time.h>

#include <cstdlib>
#include <errno.h>
//temp
#include <unistd.h>
#include <iomanip>
#include <sys/time.h>
#include <cmath>

#include "PmergeMe.hpp"

void printFJ(PmergeMe<std::vector>& vec, PmergeMe<std::list>& lst){
    PmergeMe<std::vector>::result rVec = vec.getRes();
    PmergeMe<std::list>::result rLst = lst.getRes(); 

    std::cout << "Before:" ;
    vec.printCont(rVec.unsorted);

    std::cout << "After: ";
    vec.printCont(rVec.sorted);

    std::cout << "Time to process a range of " << rVec.unsorted.size() << " elements with " << rVec.containerType << " : " << rVec.execTime << " " << rVec.unitTime << std::endl;
    std::cout << "Time to process a range of " << rLst.unsorted.size() << " elements with " << rLst.containerType << " : " << rLst.execTime << " " << rLst.unitTime << std::endl;
}

int main(int argc, char **argv){

    PmergeMe<std::vector> vec(argc,argv);
    // if (vec.isSorted())
    //     std::cout << "SORTED: TRUE" << std::endl;
    // else
    //     std::cout << "SORTED: FALSE" << std::endl;
    PmergeMe<std::list> list(argc,argv);
    // if (list.isSorted())
    //     std::cout << "SORTED: TRUE" << std::endl;
    // else
    //     std::cout << "SORTED: FALSE" << std::endl;

    printFJ(vec,list);

    // PmergeMe<std::deque > deque(argc,argv);

}

