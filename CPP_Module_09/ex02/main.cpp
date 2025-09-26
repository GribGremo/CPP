/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:55 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/26 16:31:00 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <time.h>

#include <cstdlib>
#include <errno.h>
//temp
#include <unistd.h>
#include <iomanip>
#include <sys/time.h>
#include <cmath>
//STRUCTURES
template <typename T>
struct result{
    T sorted;
    T unsorted;
    double execTime;
};

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

//DEBUG

template <typename T>
void printCont(T& c){
    for(typename T::iterator it = c.begin(); it != c.end(); it++)
        std::cout << " " << *(*it);
    std::cout << std::endl;
}

//PARSING
bool isArgValid(char* str, long int& value){
    char *end = NULL;
    errno = 0;
    value = strtol(str,&end,10);
    if (str == end || errno == ERANGE || *end != '\0' || value < 0 || value > __INT_MAX__ )
    {
        std::cout << "Error: Invalid argument format" <<std::endl;
        return (false);
    }
    return (true);
}

template <typename T>
bool    parseArgs(result<T>& r, int argc, char **argv){
    long int value = 0;
    if (argc < 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return true;
    }
    for (int i = 1; i < argc; i++)
    {
        if(isArgValid(argv[i], value))
            r.unsorted.push_back(static_cast<int>(value));
        else
            return (true);
    }
    r.sorted = r.unsorted;
    return false; 
}

//SORTING
template <typename T>
void vecIt(T& c, std::vector<typename T::iterator>& even, std::vector<typename T::iterator>& odd){
    int i = 0;
    for(typename T::iterator it = c.begin(); it != c.end(); ++it)
    {
        if(i % 2 == 0)
            even.push_back(it);
        else
            odd.push_back(it);
        i++;
    }
    // printCont(even);
    // printCont(odd);
}

template <typename T>
void swapE(std::vector<typename T::iterator>& even,std::vector<typename T::iterator>& odd, unsigned int exp){
    typename std::vector<typename T::iterator>::iterator itev = even.begin();
    typename std::vector<typename T::iterator>::iterator itod = odd.begin();
    typename std::vector<typename T::iterator>::iterator iteve = even.end(); 
    typename std::vector<typename T::iterator>::iterator itode = odd.end();
    int temp = 0;
    (void) exp;
    std::cout << exp << std::endl;
    while(itev != iteve && itod != itode)
    {
        if(**itev > **itod)
        {
            temp = **itod;
            **itod = **itev;
            **itev = temp;
        }
        itev++;
        itod++;
    }
}

template <typename T>
bool sortFJ(result<T>& r){
    std::vector<typename T::iterator> even;
    std::vector<typename T::iterator> odd;
    
    vecIt(r.sorted,even,odd);
    
    // printCont(even);
    // printCont(odd);
    
    for (unsigned int i = 2; i / 2 < even.size(); i = pow(i,2))
        swapE<T>(even,odd,i);

    // printCont(even);
    // printCont(odd);

    // std::vector<typename std::pair<T,T> > v = pairing(r.unsorted);
    return (false);
}

//MAIN
template<typename V, typename L>
void printFJ(result<V>& rVec, result<L>& rLst){
    std::cout << "Before:" ;
    // printCont(rVec.unsorted);
    for(typename V::iterator it = rVec.unsorted.begin(); it != rVec.unsorted.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    std::cout << "After: ";
    for(typename V::iterator it = rVec.sorted.begin(); it != rVec.sorted.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    std::cout << "Time to process a range of " << rVec.unsorted.size() << " elements with " << "A VOIR CONTAINER TYPE" << " : " << rVec.execTime << " UNITE DE TEMPS"<< std::endl;
    std::cout << "Time to process a range of " << rLst.unsorted.size() << " elements with " << "A VOIR CONTAINER TYPE" << " : " << rLst.execTime << " UNITE DE TEMPS"<< std::endl;
}

template <typename T>
bool timeSort(result<T>& r, int argc, char **argv){
    timeval start;
    timeval end;

    gettimeofday(&start,NULL);
    usleep(100);
    if(parseArgs(r,argc, argv))
        return (true);
    sortFJ(r);

    gettimeofday(&end,NULL);
    r.execTime = (end.tv_sec - start.tv_sec) *1000000L + (end.tv_usec - start.tv_usec);
    return (false);
}

int main(int argc, char **argv){
    result<std::vector<int> > rVec;
    result<std::list<int> > rLst;

    if(timeSort(rVec, argc, argv))
        return 1;
    if (timeSort(rLst, argc, argv))
        return 1;
    
    printFJ(rVec,rLst);
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