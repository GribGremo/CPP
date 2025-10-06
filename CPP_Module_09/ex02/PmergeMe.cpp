/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:00 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/05 10:02:07 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//CONSTRUCTORS/DESTRUCTOR
template <typename Container>
PmergeMe<Container>::PmergeMe(){std::cout << "Default constructor" <<std::endl;}

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv){
    std::cout << "Custom constructor" <<std::endl;
    timeSort(argc, argv);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(){std::cout << "Destructor" <<std::endl;}

//METHODS

template <typename Container>
void PmergeMe<Container>::timeSort(int argc , char **argv){
    timeval start;
    timeval end;

    gettimeofday(&start,NULL);
    usleep(100);
    if(parseArgs(argc, argv))
        return (true);
    sortFJ(r, 1);

    gettimeofday(&end,NULL);
    _res.execTime = (end.tv_sec - start.tv_sec) *1000000L + (end.tv_usec - start.tv_usec);
    return (false);
}

template <typename Container>
void PmergeMe<Container>::sortFJ(unsigned int seqLen){
    // std::cout << "Container Vector, good shit" << std::endl;
    _res.containerType = "std::vector<int>";
    std::vector<sqc<Container> > pairing = initPairing(idx_rec);
    sortPairs<T>(pairing);
    // printLstStruct(pairing);
    idx_rec *= 2;
    if(idx_rec < r.sorted.size() / 2)
        sortFJ(r,idx_rec);
}

template <typename Container>
void PmergeMe<Container>::sortFJ(std::list<int> c){
    // std::cout << "Container List, good shit" << std::endl;
    _res.containerType = "std::list<int>";
    (void)c;
}

//PARSING
template <typename Container>
bool PmergeMe<Container>::isArgValid(char* str, long int& value){
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

template <typename Container>
bool    PmergeMe<Container>::parseArgs(int argc, char **argv){
    long int value = 0;
    if (argc < 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return true;//EXCEPTION?
    }
    for (int i = 1; i < argc; i++)
    {
        if(isArgValid(argv[i], value))
            _res.unsorted.push_back(static_cast<int>(value));
        else
            return (true);
    }
    _res.sorted = _res.unsorted;
    return false; 
}

//INIT_VEC_SEQ
template <typename Container>
void    PmergeMe<Container>::initSeq(sqc<Container>& u, typename Container::iterator& it, typename Container::iterator end){
    unsigned int i = 0;
    u.first = it;
    while(i < u.seqLen && it != end){
        i++;
        it++;
    }
    u.last = it;
    if (it == end && i != u.seqLen) //secure not full, envoie struct
        u.full = false;
    else
        u.full = true;
}

template <typename Container>
sqc<Container> PmergeMe<Container>::initStructSeq(typename Container::iterator& it, typename Container::iterator end, int idSeq, int seqLen){
    sqc<Container> u;
 
    u.idSeq = idSeq;
    u.seqLen = seqLen;
    if (idSeq % 2 == 0){
        u.idMaxPair = idSeq / 2;
        u.idMinPair = 0;
    }
    else{
        u.idMinPair = (idSeq + 1) / 2;
        u.idMaxPair = 0;
    }
    u.seq = initSeq(u, it, end);
    return (u);
}

template <typename Container>
std::vector<sqc<std::vector<int> > > PmergeMe<Container>::initPairing(int seqLen){//RETURN REF?
    std::vector<sqc<Container> > vec;
    int idSeq = 1;

    for(typename Container::iterator it = res.sorted.begin(); it != res.sorted.end(); )//IT = IT ATTENTION A LA BOUCLE INITSEQ
    {
        vec.push_back(initStructSeq<T>(it, res.sorted.end(), idSeq, seqLen));
        idSeq++;
    }
    return (vec);
}

//SORTPAIRS

template <typename Container>
void swapRange(sqc<Container>& u1, sqc<Container>& u2){
    typename std::list<typename T::iterator>::iterator it1 = u1.first;
    typename std::list<typename T::iterator>::iterator it2 = u2.first;
    while(it1 != u1.last && it2 != u2.last)
    {
        std::iter_swap(*it1,*it2);
        it1++;
        it2++;
    }
    std::iter_swap(*it1,*it2);//A voir secu
}

template <typename Container>
void    sortPairs(std::vector<sqc<Container> >& pairing){
    typename std::vector<sqc<Container> >::iterator it1 = pairing.begin();
    typename std::vector<sqc<Container> >::iterator it2 = it1 + 1;
    while(it1 != pairing.end() && it2 != pairing.end()){
        if(*(it1->last) > *(it2->last) && it2->full == true ){//ATTENTION POTENTIELLEMENT IT2 N'EXISTE PAS
            swapRange<T>(it1->seq, it2->seq);
        }
        it1++;
        if (it1 != pairing.end())
            it2++;
    }
}
