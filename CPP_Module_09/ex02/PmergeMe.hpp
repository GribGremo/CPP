/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:03 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/23 20:15:37 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <iostream>
#include <vector>
#include <list>
#include <cmath>


// template <typename Container>
// template <template <typename,typename> class Container>//A voir T=int
template <template <typename,typename> class Container>
class PmergeMe{
    
    private:

    /*~~~~~~~~~~~~~~~~~~~~~TYPEDEF~~~~~~~~~~~~~~~~~~~~~*/
    
    // typedef Container<int,std::allocator<int> >            cont_int;
    // typedef typename Container<int,std::allocator<int> >::iterator  it_cont_int;
    // typedef typename std::list<int>::iterator                       it_lst_int;
    
    /*~~~~~~~~~~~~~~~~~~~~~STRUCTURES~~~~~~~~~~~~~~~~~~~~~*/
    
    // template <typename Container>
    struct result{
        Container<int, std::allocator<int> >    sorted;
        Container<int, std::allocator<int> >    unsorted;
        double                                  execTime;
        std::string                             containerType;
    };
    
    struct sqc{
        typename Container<int, std::allocator<int> >::iterator     first;
        typename Container<int, std::allocator<int> >::iterator     last;
        int             idSeq;
        int             i;
        bool            full;
    };
    // typedef Container<sqc,std::allocator<sqc> >            cont_sqc;
    // typedef typename Container<sqc,std::allocator<sqc> >::iterator  it_cont_sqc;
    // typedef typename std::list<sqc>::iterator                       it_lst_sqc;
    
    struct pairer{
        Container<sqc,std::allocator<sqc> >        min;
        Container<sqc,std::allocator<sqc> >        max;
        int             seqLen;
    };
    

    /*~~~~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~~~~*/    
    
    //DEBUG
    void            printFL(sqc u);
    void            printCont(Container<int,std::allocator<int> >& c);
    void            printLstSqc(std::list<sqc> lst);
    void            printStruct(pairer pairing);

    //CHECKER TYPE
    // void            checkContainerType(PmergeMe<Container>&, std::string& containerType);
    // void            checkContainerType(PmergeMe<std::vector>&, std::string& containerType);
    // void            checkContainerType(PmergeMe<std::list>&, std::string& containerType);
    
    
    //UTILS
    Container<int,std::allocator<int> >                     listSqcToListInt(Container<sqc,std::allocator<sqc> > lstSqc);
    typename Container<sqc,std::allocator<sqc> >::iterator  getItFromId(Container<sqc,std::allocator<sqc> >& lst, int id);
    typename Container<sqc,std::allocator<sqc> >::iterator  getItFromindex(Container<sqc,std::allocator<sqc> >& lst, int id);
    typename Container<sqc,std::allocator<sqc> >::iterator  getPrev(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator it);
    typename Container<sqc,std::allocator<sqc> >::iterator  getNext(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator it);
    
    //MERGE INSERT
    typename Container<sqc,std::allocator<sqc> >::iterator  binarySearch(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator start, typename Container<sqc,std::allocator<sqc> >::iterator end, int cmp);
    void                                                    initIdList(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator& start, typename Container<sqc,std::allocator<sqc> >::iterator& end);
    void                                                    execJS(Container<sqc,std::allocator<sqc> >& main,Container<sqc,std::allocator<sqc> >& pending,int idJS);
    void                                                    setupJS(pairer& pairing, Container<sqc,std::allocator<sqc> >& main,Container<sqc,std::allocator<sqc> >& pending, Container<sqc,std::allocator<sqc> >& rest);
    void                                                    insertRest(Container<sqc,std::allocator<sqc> >& main, Container<sqc,std::allocator<sqc> >& pending);
    Container<int,std::allocator<int> >                     insertListFJ(pairer& pairing);
    
    //SORT PAIRS
    void        swapRange(sqc& u1, sqc& u2);
    void        sortPairs(pairer& pairing);
    
    //INIT PAIRER SEQUENCE
    sqc         initStructSeq(typename Container<int,std::allocator<int> >::iterator& it, typename Container<int,std::allocator<int> >::iterator end, int idSeq, int seqLen);
    pairer      initPairing(Container<int,std::allocator<int> >& v, int seqLen);
    
    //SORT
    void        timeSort(int argc , char **argv);
    void        sortFJ();
    Container<int,std::allocator<int> >    sortFJ_Container(Container<int,std::allocator<int> >& v, unsigned int seqLen);
    
    //PARSING
    bool        parseArgs(int argc, char **argv);
    bool        isArgValid(char* str, long int& value);
    
    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    
    
    PmergeMe();
    
    /*~~~~~~~~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~~~~~~~~*/    
    
    result _res;
    pairer _pairing;
    
    public:
    
    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    

    PmergeMe(int argc, char **argv);//OUBLIE PAS LA CANNONIQUE BOUFFON
    PmergeMe(const PmergeMe<Container>& src);
    ~PmergeMe();

    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    
    PmergeMe operator=(const PmergeMe<Container>& src);
    //MAIN

    // void sortFJ<std::list<int> >(unsigned int seqLen);
    // void sortFJ(Container c, unsigned int seqLen);


    //PAIRINGVEC
    // void    initSeq(sqc<Container>& u, typename Container::iterator& it, typename Container::iterator end);
    // sqc<Container> initStructSeq(typename Container::iterator& it, typename Container::iterator end, int idSeq, int seqLen);
    // std::vector<sqc<std::vector<int> > > initPairing(int seqLen);
    
};
// std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen);
// void printCont(std::list<int>& c);

#include "PmergeMe.tpp"

#endif

// gcc -fsanitize=address -fno-omit-frame-pointer -O0 -g3 -ggdb3 ft_split.cpp -o split
// gdb ./split
// run (apres segfault)
// bt
