/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:03 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/30 18:57:24 by grib             ###   ########.fr       */
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
    // typedef typename Container<int,std::allocator<int> >::iterator  it_cont_int;
    // typedef typename std::list<int>::iterator                       it_lst_int;
    
    /*~~~~~~~~~~~~~~~~~~~~~STRUCTURES~~~~~~~~~~~~~~~~~~~~~*/

    public:

    struct result{
        Container<int, std::allocator<int> >                        sorted;
        Container<int, std::allocator<int> >                        unsorted;
        double                                                      execTime;
        std::string                                                 containerType;
        std::string                                                 unitTime;
    };
    

    private:
    
    struct sqc{
        typename Container<int, std::allocator<int> >::iterator     first;
        typename Container<int, std::allocator<int> >::iterator     last;
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
        bool operator()(const sqc& s, int value) const {
            return *(s.last) < value;
        }
    };


    /*~~~~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~~~~*/    

    //DEBUG
    void            printFL(sqc u);
    void            printLstSqc(Container<sqc,std::allocator<sqc> > lst);
    void            printStruct(pairer pairing);

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
    Container<int,std::allocator<int> >                     insertFJ(pairer& pairing);
    
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

    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe<Container>& src);
    ~PmergeMe();

    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    
    PmergeMe operator=(const PmergeMe<Container>& src);

    /*~~~~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~~~~*/    

    bool            isSorted();
    void            printCont(Container<int,std::allocator<int> >& c);

    /*~~~~~~~~~~~~~~~~~~~~~GETTERS~~~~~~~~~~~~~~~~~~~~~*/    

    const result&   getRes();
};

#include "PmergeMe.tpp"

#endif

/*
Entier:11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

SortPair:2 11 0 17 8 16 6 15 3 10 1 21 9 18 14 19 5 12 4 20 7 13
Max:11 17 16 15 10 21 18 19 12 20 13
Min:1  0  8  6  3  1  9  14 5  4  7

SortPair:11 17 15 16 10 21 18 19 12 20 13
Max:17 16 21 19 20
Min:11 15 10 18 12 13

SortPair:16 17 19 21 20
Max:17 21
Min:16 19 20

SortPair:17 21
Max:21
Min:17

SortPair:21

17 21 //On recupere la paire min, puis pas d'insert deja trie


16 17 19 21 20 //Pareil mais pas trie, du coup insert

[16 17 21]    //Min 1 + Max ON A INDEXE NOS PAIRS A1,B1...ON VA UTILISER JS NUMBER 3,5,11... mais ici pas plus que donc...
      19 20 //Reste des min

[16 17 20] 21
         19

16 17 19 20 21

15 16 11 17 18 19 12 20 13
 1  1  2   3
[15 16 17] 19 |  20    // 18 et 19 sont paires je sais deja que 19 plus grand que 18 et je sais aussi que 20 plus grand 19
      11 18   | 12 13
      2  3   JS3
[15 16] 17 18 | 19 20 // Je sais que 11 plus petit que 17 parce que c'est ma pair et qu'on est trie
       11     |   12 13
              |
11 15 16 17 18| 19 20 // Ici plus pour JS3 mais il me reste min4 et min5, le prochain JS number c'est 5
              |   12 13
[11 15 16 17 18 19 20]
                  12 13 |
                        JS5 Bref vous avez compris
*/