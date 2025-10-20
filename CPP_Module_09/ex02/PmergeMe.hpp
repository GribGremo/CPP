/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:03 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/20 17:53:25 by sylabbe          ###   ########.fr       */
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
template <template <typename> class Container>
class PmergeMe{
    
    private:

    /*~~~~~~~~~~~~~~~~~~~~~TYPEDEF~~~~~~~~~~~~~~~~~~~~~*/
    
    
    typedef typename Container<int>::iterator   it_cont_int;
    typedef typename std::list<int>::iterator   it_lst_int;
    typedef typename std::list<sqc>::iterator   it_lst_sqc;
    
    /*~~~~~~~~~~~~~~~~~~~~~STRUCTURES~~~~~~~~~~~~~~~~~~~~~*/

    // template <typename Container>
    struct result{
        Container<int>  sorted;
        Container<int>  unsorted;
        double          execTime;
        std::string     containerType;
    };

    struct sqc{
        it_cont_int     first;
        it_cont_int     last;
        int             idSeq;
        int             i;
        bool            full;
    };
    
    struct pairer{
        Container<sqc>  min;
        Container<sqc>  max;
        int             seqLen;
    };
    

    /*~~~~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~~~~*/    
    
    //DEBUG
    void            printFL(sqc u);
    void            printCont(std::list<int>& c);
    void            printLstSqc(std::list<sqc> lst);
    void            printStruct(pairer pairing);

    //CHECKER TYPE
    void            checkContainerType(PmergeMe<T>&, std::string& containerType);
    void            checkContainerType(PmergeMe<std::vector<int> >&, std::string& containerType);
    void            checkContainerType(PmergeMe<std::list<int> >&, std::string& containerType);
    
    
    //UTILS
    std::list<int>  listSqcToListInt(std::list<sqc> lstSqc);
    it_lst_sqc      getItFromId(std::list<sqc>& lst, int id);
    it_lst_sqc      getItFromindex(std::list<sqc>& lst, int id);
    it_lst_sqc      getPrev(std::list<sqc>& lst, it_lst_sqc it);
    it_lst_sqc      getNext(std::list<sqc>& lst, it_lst_sqc it);
    
    //MERGE INSERT
    it_lst_sqc      binarySearch(std::list<sqc>& lst, it_lst_sqc start, it_lst_sqc end, int cmp);
    void            initIdList(std::list<sqc>& lst, it_lst_sqc& start, it_lst_sqc& end);
    void            execJS(std::list<sqc>& main,std::list<sqc>& pending,int idJS);
    void            setupJS(pairer& pairing, std::list<sqc>& main,std::list<sqc>& pending, std::list<sqc>& rest);
    void            insertRest(std::list<sqc>& main, std::list<sqc>& pending);
    std::list<int>  insertListFJ(pairer& pairing);
    
    //SORT PAIRS
    void            swapRange(sqc& u1, sqc& u2);
    void            sortPairs(pairer& pairing);
    
    //INIT PAIRER SEQUENCE
    sqc             initStructSeq(it_cont_int& it, it_cont_int end, int idSeq, int seqLen);
    pairer          initPairing(std::list<int>& v, int seqLen);
    
    //SORT
    void            timeSort(int argc , char **argv);
    void            sortFJ();
    std::list<int>  sortFJ_Container(std::list<int>& v, unsigned int seqLen);
    
    //PARSING
    bool            parseArgs(int argc, char **argv);
    bool            isArgValid(char* str, long int& value);
    
    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    
    
    PmergeMe();
    
    /*~~~~~~~~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~~~~~~~~*/    
    
    result _res;
    
    
    public:
    
    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    

    PmergeMe(int argc, char **argv);//OUBLIE PAS LA CANNONIQUE BOUFFON
    PmergeMe(const PmergeMe& src);
    ~PmergeMe();

    /*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~*/    
    PmergeMe operator=(const PmergeMe& src);
    //MAIN

    // void sortFJ<std::list<int> >(unsigned int seqLen);
    // void sortFJ(Container c, unsigned int seqLen);


    //PAIRINGVEC
    // void    initSeq(sqc<Container>& u, typename Container::iterator& it, typename Container::iterator end);
    // sqc<Container> initStructSeq(typename Container::iterator& it, typename Container::iterator end, int idSeq, int seqLen);
    // std::vector<sqc<std::vector<int> > > initPairing(int seqLen);
    
};
std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen);
void printCont(std::list<int>& c);

#include "PmergeMe.tpp"

#endif
