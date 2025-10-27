/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:55 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/26 21:02:48 by grib             ###   ########.fr       */
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
//STRUCTURES
// template <typename T>
// struct result{
//     T sorted;
//     T unsorted;
//     double execTime;
// };

// template <typename T>
// struct sqc{
//     std::list<typename T::iterator> seq;
//     int id_min;
//     int id_max;
//     int id_seq;
//     int id_rec;
//     bool full;
// };
//SKETCH

// template <typename T>
// std::vector<typename std::pair<T,T> >   pairing(std::vector<T> vec){
//     std::vector<T> pairVec;
//     int ip = 0;
//     for(typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); it++){
//         if(++ip % 2 == 0)
//             pairVec.push_back(std::pair<T,T>(*(--it), *it));
//     }
//     return (pairVec);
//     // if (++ip % 2 == 1)
//     //     pairVec.push_back(std::pair<T,T>(*(--it), NULL));

// }

// template <typename T>
// void swapExp(T c, int e){
//     int lmt = std::pow(2, e);
//     if (lmt == 2)
//     {
//         for(T::iterator it = c.begin(); it)
//     }
    
// }



//OUF CA FAIT MAL////////////////////////////////////////////////////////////////////////
// template <typename T>
// void vecIt(T& c, std::vector<typename T::iterator>& even, std::vector<typename T::iterator>& odd){
//     int i = 0;
//     for(typename T::iterator it = c.begin(); it != c.end(); ++it)
//     {
//         if(i % 2 == 0)
//             even.push_back(it);
//         else
//             odd.push_back(it);
//         i++;
//     }
//     // printCont(even);
//     // printCont(odd);
// }

// template <typename T>
// void swapRange(typename std::vector<typename T::iterator>::iterator& itev, typename std::vector<typename T::iterator>::iterator& itod, unsigned int exp){
//     int temp = 0;
//     unsigned int i = exp;
//     while(exp > 0)
//     {
//         temp = **itod;
//         **itod = **itev;
//         **itev = temp;
//         exp--;
//         itev--;
//         itod--;
//     }
//     while(exp != i)
//     {
//         exp++;
//         itev++;
//         itod++;
//     }
// }

// template <typename T>
// void swapE(std::vector<typename T::iterator>& even,std::vector<typename T::iterator>& odd, unsigned int exp){
//     typename std::vector<typename T::iterator>::iterator itev = even.begin();
//     typename std::vector<typename T::iterator>::iterator itod = odd.begin();
//     typename std::vector<typename T::iterator>::iterator iteve = even.end(); 
//     typename std::vector<typename T::iterator>::iterator itode = odd.end();
//     // int temp = 0;
//     // typename T::iterator temp;
//     // (void) exp;
//     // std::cout << exp << std::endl;
//     while(itev != iteve && itod != itode)
//     {
//         for (unsigned int i = 1; i < exp && itev != iteve && itod != itode; i++)
//         {
//             itev++;
//             itod++;
//         }
//         if(itev != iteve && itod != itode && **itev > **itod)
//         {
//             // std::cout << **itev << " "<< **itod << std::endl;
//             swapRange<T>(itev, itod, exp);
//             // temp = **itod;
//             // **itod = **itev;
//             // **itev = temp;
//         }
//         if (itev != iteve && itod != itode)
//         {
//             itod++;
//             itev++;
//         }
//     }
// }

// template <typename T>
// bool sortFJ(result<T>& r){
//     std::vector<typename T::iterator> even;
//     std::vector<typename T::iterator> odd;
    
//     // vecIt(r.sorted,even,odd);
    
//     for (unsigned int i = 1; i < (r.unsorted.size() / 2); i *= 2)
//     {
//         std::cout << "A" <<std::endl;
//         vecIt(r.sorted,even,odd);
//         printCont(even);
//         printCont(odd);
//         swapE<T>(even,odd,i);
//         even.clear();
//         odd.clear();
//     }


//     // std::vector<typename std::pair<T,T> > v = pairing(r.unsorted);
//     return (false);
// }
//DEBUG

// template <typename T>
// void printCont(T& c){
//     for(typename T::iterator it = c.begin(); it != c.end(); it++)
//         std::cout << " " << *(*it);
//     std::cout << std::endl;
// }

// template <typename T>
// void printStruct(sqc<T> u){
//     std::cout << "Sequence: ";
//     printCont(u.seq);
//     std::cout << "Full: " << u.full << std::endl;
//     std::cout << "Id min: " << u.id_min<< std::endl;
//     std::cout << "Id max: " << u.id_max << std::endl;
//     std::cout << "Index vector: " << u.id_seq << std::endl;
//     std::cout << "Recursive: " << u.id_rec << std::endl << std::endl;
// }

// template <typename T>
// void printLstStruct(std::list<sqc<T> > v){
//     for(typename std::list<sqc<T> >::iterator it = v.begin(); it != v.end(); it++)
//         printStruct(*it);
// }

//PARSING
// bool isArgValid(char* str, long int& value){
//     char *end = NULL;
//     errno = 0;
//     value = strtol(str,&end,10);
//     if (str == end || errno == ERANGE || *end != '\0' || value < 0 || value > __INT_MAX__ )
//     {
//         std::cout << "Error: Invalid argument format" <<std::endl;
//         return (false);
//     }
//     return (true);
// }

// template <typename T>
// bool    parseArgs(result<T>& r, int argc, char **argv){
//     long int value = 0;
//     if (argc < 2)
//     {
//         std::cout << "Error: Invalid number of arguments" << std::endl;
//         return true;
//     }
//     for (int i = 1; i < argc; i++)
//     {
//         if(isArgValid(argv[i], value))
//             r.unsorted.push_back(static_cast<int>(value));
//         else
//             return (true);
//     }
//     r.sorted = r.unsorted;
//     return false; 
// }

//INIT_VEC_SEQ
// template <typename T>
// std::list<typename T::iterator>    initSeq(sqc<T>& u, typename T::iterator& it, typename T::iterator end, unsigned int idx_rec){
//     std::list<typename T::iterator> lstIt;

//     for (unsigned int i = 0; i < idx_rec && it != end; i++)
//     {
//         lstIt.push_back(it);
//         it++;
//     }
//     if (lstIt.size() != idx_rec) //secure not full, envoie struct
//         u.full = false;
//     else
//         u.full = true;
//     return (lstIt);
// }

// template <typename T>
// sqc<T> initStructSeq(typename T::iterator& it, typename T::iterator end, int n_seq, int idx_rec){
//     sqc<T> u;
 
//     u.seq = initSeq<T>(u, it, end, idx_rec);
//     u.id_seq = n_seq;
//     u.id_rec = idx_rec;
//     if (n_seq % 2 == 0){
//         u.id_max = n_seq / 2;
//         u.id_min = 0;
//     }
//     else{
//         u.id_min = (n_seq + 1) / 2;
//         u.id_max = 0;
//     }
//     return (u);
// }

// template <typename T>
// std::list<sqc<T> > initLstStructSeq(result<T>& r, int idx_rec){//RETURN REF?
//     std::list<sqc<T> > lst;
//     int n_seq = 1;

//     for(typename T::iterator it = r.sorted.begin(); it != r.sorted.end(); )//IT = IT ATTENTION A LA BOUCLE INITSEQ
//     {
//         lst.push_back(initStructSeq<T>(it, r.sorted.end(), n_seq, idx_rec));
//         n_seq++;
//     }
//     return (lst);
// }

//UTILS
// template <typename T>
// typename std::list<T>::iterator incrIT(typename std::list<T>::iterator it, unsigned int n){
//     for (unsigned int i = 0;i < n;i++)
//         it++;
//     return (it);
// }

// //SORTING
// template <typename T>
// std::list<sqc<T> >   mergeFJ(std::list<sqc<T> > l){
//     std::list<sqc<T> > main;
//     std::list<sqc<T> > pend;
//     typename std::list<sqc<T> >::iterator it = l.begin();
//     main.push_back(*it);
//     while(++it != l.end())
//     {
//         if (it->id_max > 0 && it->full == true)//Verif full true
//             main.push_back(*it);
//         else
//             pend.push_back(*it);
//     }

//     std::cout << "main:";
//     printLstStruct(main);
//     std::cout << "pend:";
//     printLstStruct(pend);
//     return (main);//
// }

// template <typename T>
// void swapRange(std::list<typename T::iterator>& v1, std::list<typename T::iterator>& v2){
//     typename std::list<typename T::iterator>::iterator it1 = v1.begin();
//     typename std::list<typename T::iterator>::iterator it2 = v2.begin();
//     while(it1 != v1.end() && it2 != v2.end())
//     {
//         std::iter_swap(*it1,*it2);
//         it1++;
//         it2++;
//     }
// }

// template <typename T>
// void    sortPairs(std::list<sqc<T> >& pairing){
//     typename std::list<sqc<T> >::iterator it1 = pairing.begin();
//     typename std::list<sqc<T> >::iterator it2 = incrIT<sqc<T> >(it1,1);
//     while(it1 != pairing.end() && it2 != pairing.end()){
//         if(*(it1->seq.back()) > *(it2->seq.back()) && it2->full == true ){//ATTENTION POTENTIELLEMENT IT2 N'EXISTE PAS
//              swapRange<T>(it1->seq, it2->seq);
//         }
//         it1 = incrIT<sqc<T> >(it1,2);
//         if (it1 != pairing.end())
//             it2 = incrIT<sqc<T> >(it2,2);
//     }
// }

// template <typename T>
// bool sortFJ(result<T>& r,unsigned int idx_rec){
//     std::list<sqc<T> > pairing = initLstStructSeq(r, idx_rec);
//     sortPairs<T>(pairing);
//     // printLstStruct(pairing);
//     idx_rec *= 2;
//     if(idx_rec < r.sorted.size() / 2)
//         sortFJ(r,idx_rec);
//     mergeFJ(pairing);
//     // std::cout << *(++(r.sorted.rbegin()))<< std::endl;
//     // r.sorted.insert(++(r.sorted.begin()), (r.advance((r.sorted.rbegin(),3)).base(),((r.sorted.rbegin()) + 1).base());

//     return (false);
// }

//MAIN
// template<typename V, typename L>
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
    if (vec.isSorted())
        std::cout << "SORTED: TRUE" << std::endl;
    else
        std::cout << "SORTED: FALSE" << std::endl;
    PmergeMe<std::list> list(argc,argv);
    if (list.isSorted())
        std::cout << "SORTED: TRUE" << std::endl;
    else
        std::cout << "SORTED: FALSE" << std::endl;

    printFJ(vec,list);

    // PmergeMe<std::deque > deque(argc,argv);

}

/*Ford-Johnson algorithm 
-1er:Trier par paire
-
-
-
-


-Jacobsthal:0,1,n= n-1 + 2(n-2)(1 + (2*0)= 1), (1 + (2*1) = 3, (3+(2*1) = 5),(5+(2*3) = 11));
array[0] = 0;
array[1] = 1;


for (int i = 2; i < lim ; i++)
array[i] = array(i - 1) + (2 * array[i - 2]);

For calculate Jnum at index i: J[i] = (2expi - (-1)expi) / 3; pour i =5 array[5] = 2exp5(32) - (-1)exp5(-1) = 33 / 3 = 11;

<pair>
*/

/*
C MARRANT HEIN LE TYPAGE DYNAMIQUE RECURSIF?

template <int Depth>
struct NestedPair {
    typedef std::pair<
        typename NestedPair<Depth - 1>::type,
        typename NestedPair<Depth - 1>::type
    > type;
};

template <>
struct NestedPair<0> {
    typedef std::pair<int, int> type;
};

// Pour accéder à la paire terminale à gauche
template <int Depth, typename PairType>
std::pair<int, int>& get_left_leaf(PairType& p) {
    return get_left_leaf<Depth - 1>(p.first);
}

template <typename PairType>
std::pair<int, int>& get_left_leaf<0>(PairType& p) {
    return p; // on est au fond
}

#include <iostream>
#include <utility>

template <int Depth>
struct NestedPair {
    typedef std::pair<
        typename NestedPair<Depth - 1>::type,
        typename NestedPair<Depth - 1>::type
    > type;
};

template <>
struct NestedPair<0> {
    typedef std::pair<int, int> type;
};

template <int Depth, typename PairType>
std::pair<int, int>& get_left_leaf(PairType& p) {
    return get_left_leaf<Depth - 1>(p.first);
}

template <typename PairType>
std::pair<int, int>& get_left_leaf<0>(PairType& p) {
    return p;
}

int main() {
    const int Depth = 3;
    NestedPair<Depth>::type np;

    // Accès à la paire la plus à gauche
    std::pair<int, int>& leaf = get_left_leaf<Depth>(np);

    leaf.first = 42;
    leaf.second = 99;

    std::cout << "leaf = (" << leaf.first << ", " << leaf.second << ")\n";
}

*/