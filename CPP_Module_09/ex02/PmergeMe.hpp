/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:03 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/05 13:43:19 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

template <template <typename,typename> class Container>
class PmergeMe{
    
    private:

    /*~~~~~~~~~~~~~~~~~~~~~TYPEDEF~~~~~~~~~~~~~~~~~~~~~*/
    
    // typedef Container<int,std::allocator<int> >            cont_int;
    typedef typename Container<int,std::allocator<int> >::iterator  it_cont_int;
    // typedef typename std::list<int>::iterator                       it_lst_int;
    
    /*~~~~~~~~~~~~~~~~~~~~~STRUCTURES~~~~~~~~~~~~~~~~~~~~~*/

    public:

    struct result{
        bool                                                        empty;
        Container<int, std::allocator<int> >                        sorted;
        Container<int, std::allocator<int> >                        unsorted;
        double                                                      execTime;
        std::string                                                 containerType;
        std::string                                                 unitTime;
    };
    

    private:
    
    struct sqc{
        typename Container<int,std::allocator<int> >::iterator     first;
        typename Container<int,std::allocator<int> >::iterator     last;
        int                                                         idSeq;
        int                                                         i;
        bool                                                        full;
    };
    
    struct pairer{
        Container<sqc,std::allocator<sqc> >                         min;
        Container<sqc,std::allocator<sqc> >                         max;
        int                                                         seqLen;
    };
    
    struct CmpStruct {
        PmergeMe* parent;
        CmpStruct(PmergeMe* src);
        bool operator()(const sqc& s, int value);
    };


    /*~~~~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~~~~*/
    public:

    bool            empty();
    bool            isSorted();
    void            printCont(Container<int,std::allocator<int> >& c);

    private:

    //CHECKER TYPE
    void            checkContainerType(std::string& containerType);
    
    //UTILS
    Container<int,std::allocator<int> >                     cSqcTocInt(Container<sqc,std::allocator<sqc> > lstSqc);
    typename Container<sqc,std::allocator<sqc> >::iterator  getItFromId(Container<sqc,std::allocator<sqc> >& lst, int id);
    typename Container<sqc,std::allocator<sqc> >::iterator  getItFromindex(Container<sqc,std::allocator<sqc> >& lst, int id);
    typename Container<sqc,std::allocator<sqc> >::iterator  getPrev(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator it);
    typename Container<sqc,std::allocator<sqc> >::iterator  getNext(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator it);
    
    //MERGE INSERT
    typename Container<sqc,std::allocator<sqc> >::iterator  binarySearch(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator start, typename Container<sqc,std::allocator<sqc> >::iterator end, int cmp);
    void                                                    initIdList(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator& start, typename Container<sqc,std::allocator<sqc> >::iterator& end);
    void                                                    execJS(Container<sqc,std::allocator<sqc> >& main,Container<sqc,std::allocator<sqc> >& pending,int idJS);
    void                                                    setupJS(pairer& pairing, Container<sqc,std::allocator<sqc> >& main,Container<sqc,std::allocator<sqc> >& pending, Container<sqc,std::allocator<sqc> >& rest);
    void                     insertFJ(pairer& pairing);
    
    //SORT PAIRS
    void        swapRange(sqc& u1, sqc& u2);
    void        sortPairs(pairer& pairing);
    
    //INIT PAIRER SEQUENCE
    sqc         initStructSeq(typename Container<int,std::allocator<int> >::iterator& it, typename Container<int,std::allocator<int> >::iterator end, int idSeq, int seqLen);
    pairer      initPairing(Container<int,std::allocator<int> >& v, int seqLen);
    
    //
    void        timeSort(int argc , char **argv);
    void        sortFJ(unsigned int seqLen);
    
    //PARSING
    bool        isArgValid(char* str, long int& value);
    void        parseArgs(int argc, char **argv);
    

    
    /*~~~~~~~~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~~~~~~~~*/    
    private:

    result  _res;
    pairer  _pairing;
    int     _countCmp;

    
    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    
    public:

    PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe<Container>& src);
    ~PmergeMe();

    /*~~~~~~~~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~~~~~~~~*/
    public:

    PmergeMe        operator=(const PmergeMe<Container>& src);


    /*~~~~~~~~~~~~~~~~~~~~~GETTERS~~~~~~~~~~~~~~~~~~~~~*/    
    public:

    const result&   getRes();
    const int&      getCountCmp();

};

#include "PmergeMe.tpp"

#endif
