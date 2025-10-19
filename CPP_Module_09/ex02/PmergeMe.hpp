/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:03 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/19 17:33:21 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

// #include "sortVector.cpp"
// #include "sortList.cpp"


template <typename Container>
struct result{
    Container sorted;
    Container unsorted;
    double execTime;
    std::string containerType;
};

// template <typename Container>
// struct sqc{
//     typename Container::iterator first;
//     typename Container::iterator last;
//     int idMinPair;
//     int idMaxPair;
//     int idSeq;
//     int seqLen;
//     bool full;
// };

template <typename Container>
class PmergeMe{
    private:
    PmergeMe();
    
    result<Container> _res;
    
    public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();
    //MAIN
    bool parseArgs(int argc, char **argv);
    bool isArgValid(char* str, long int& value);
    void timeSort(int argc , char **argv);
    void sortFJ();
    // void sortFJ<std::list<int> >(unsigned int seqLen);
    // void sortFJ(Container c, unsigned int seqLen);


    //PAIRINGVEC
    // void    initSeq(sqc<Container>& u, typename Container::iterator& it, typename Container::iterator end);
    // sqc<Container> initStructSeq(typename Container::iterator& it, typename Container::iterator end, int idSeq, int seqLen);
    // std::vector<sqc<std::vector<int> > > initPairing(int seqLen);
    
};
std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen);
void printCont(std::list<int>& c);

// #include "test.hpp"
#include "PmergeMe.tpp"
#endif
