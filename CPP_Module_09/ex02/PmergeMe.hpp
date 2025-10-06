/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:03 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/05 09:51:05 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

template <typename Container>
struct result{
    Container sorted;
    Container unsorted;
    double execTime;
    std::string containerType;
};

template <typename Container>
struct sqc{
    typename Container::iterator first;
    typename Container::iterator last;
    int idMinPair;
    int idMaxPair;
    int idSeq;
    int seqLen;
    bool full;
};

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
    void sortFJ(std::vector<int> c);
    void sortFJ(std::list<int> c);

    //PAIRINGVEC
    void    initSeq(sqc<Container>& u, typename Container::iterator& it, typename Container::iterator end);
    sqc<Container> initStructSeq(typename Container::iterator& it, typename Container::iterator end, int idSeq, int seqLen);
    std::vector<sqc<std::vector<int> > > initPairing(int seqLen);
    
};


#include "PmergeMe.cpp"
#endif
