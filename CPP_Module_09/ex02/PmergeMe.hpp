/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:03 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/05 14:42:18 by sylabbe          ###   ########.fr       */
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
#include <errno.h>


template <template <typename,typename> class Container>
class PmergeMe{
    
    /*~~~~~~~~~~~~~~~~~~~~~TYPEDEF~~~~~~~~~~~~~~~~~~~~~*/
    private:
    
    typedef Container<int,std::allocator<int> >                     cont_int;
    typedef typename Container<int,std::allocator<int> >::iterator  it_cont_int;
    
    /*~~~~~~~~~~~~~~~~~~~~~STRUCTURES~~~~~~~~~~~~~~~~~~~~~*/

    public:

    struct result{
        bool        empty;
        cont_int    sorted;
        cont_int    unsorted;
        double      execTime;
        std::string containerType;
        std::string unitTime;
    };
    

    private:
    
    struct sqc{
        it_cont_int first;
        it_cont_int last;
        int         idSeq;
        int         i;
        bool        full;
    };
    typedef Container<sqc,std::allocator<sqc> >                     cont_seq;
    typedef typename Container<sqc,std::allocator<sqc> >::iterator  it_cont_seq;

    
    struct pairer{
        cont_seq    min;
        cont_seq    max;
        int         seqLen;
    };
    
    struct CmpStruct {
        PmergeMe*   parent;

        CmpStruct(PmergeMe* src);
        bool        operator()(const sqc& s, int value);
    };


    /*~~~~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~~~~*/
    public:

    bool            empty();
    bool            isSorted();
    void            printCont(cont_int& c);

    private:

    //CHECKER TYPE
    void            checkContainerType(std::string& containerType);
    
    //UTILS
    cont_int        cSqcTocInt(cont_seq lstSqc);
    it_cont_seq     getItFromId(cont_seq& lst, int id);
    it_cont_seq     getItFromindex(cont_seq& lst, int id);
    it_cont_seq     getPrev(cont_seq& lst, it_cont_seq it);
    it_cont_seq     getNext(cont_seq& lst, it_cont_seq it);
    
    //MERGE INSERT
    it_cont_seq     binarySearch(cont_seq& lst, it_cont_seq start, it_cont_seq end, int cmp);
    void            initIdList(cont_seq& lst, it_cont_seq& start, it_cont_seq& end);
    void            execJS(cont_seq& main,cont_seq& pending,int idJS);
    void            setupJS(pairer& pairing, cont_seq& main,cont_seq& pending, cont_seq& rest);
    void            insertFJ(pairer& pairing);
    
    //SORT PAIRS
    void            swapRange(sqc& u1, sqc& u2);
    void            sortPairs(pairer& pairing);
    
    //INIT PAIRER SEQUENCE
    sqc             initStructSeq(it_cont_int& it, it_cont_int end, int idSeq, int seqLen);
    pairer          initPairing(cont_int& v, int seqLen);
    
    //MAIN
    void            timeSort(int argc , char **argv);
    void            sortFJ(unsigned int seqLen);
    
    //PARSING
    bool            isArgValid(char* str, long int& value);
    void            parseArgs(int argc, char **argv);
    
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
