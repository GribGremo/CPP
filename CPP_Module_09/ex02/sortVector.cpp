/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:08 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/06 18:20:33 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "PmergeMe.hpp"
#include <vector>
#include <iostream>

struct sqc{
    std::vector<int>::iterator first;
    std::vector<int>::iterator last;
    int idMinPair;
    int idMaxPair;
    int idSeq;
    int seqLen;
    bool full;
};

//DEBUG

void printFL(std::vector<int>::iterator first, std::vector<int>::iterator last){
    while(first != last){
        std::cout << " " << *first;
        first++;
    }
    std::cout << " " << *first <<std::endl;
}

void printCont(std::vector<int>& c){
    for(std::vector<int>::iterator it = c.begin(); it != c.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
}

void printContIt(std::vector<std::vector<int>::iterator>& c){
    for(std::vector<std::vector<int>::iterator>::iterator it = c.begin(); it != c.end(); it++)
        std::cout << " " << *(*it);
    std::cout << std::endl;
}

void printStruct(sqc u){
    std::cout << "Sequence: ";
    printFL(u.first,u.last);
    std::cout << "Full: " << u.full << std::endl;
    std::cout << "Id min: " << u.idMinPair<< std::endl;
    std::cout << "Id max: " << u.idMaxPair << std::endl;
    std::cout << "Index vector: " << u.idSeq << std::endl;
    std::cout << "Recursive: " << u.seqLen << std::endl << std::endl;
}

void printVecStruct(std::vector<sqc> v){
    for(std::vector<sqc>::iterator it = v.begin(); it != v.end(); it++)
        printStruct(*it);
}



void sortFJ_Container(std::vector<int>& v, unsigned int seqLen);
void    initSeq(sqc& u, std::vector<int>::iterator& it, std::vector<int>::iterator end);
sqc initStructSeq(std::vector<int>::iterator& it, std::vector<int>::iterator end, int idSeq, int seqLen);
std::vector<sqc> initPairing(std::vector<int>& v, int seqLen);
void swapRange(sqc& u1, sqc& u2);
void    sortPairs(std::vector<sqc>& pairing);


void sortFJ_Container(std::vector<int>& v, unsigned int seqLen){
    std::vector<sqc> pairing = initPairing(v, seqLen);
    // printCont(v);
    printVecStruct(pairing);
    // sortPairs(pairing);
    // printLstStruct(pairing);
    seqLen *= 2;
    // if(seqLen < v.size() / 2)
    //     sortFJ_Container(v, seqLen);
}

//INIT_VEC_SEQ
void    initSeq(sqc& u, std::vector<int>::iterator& it, std::vector<int>::iterator end){
    int i = 0;
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

sqc initStructSeq(std::vector<int>::iterator& it, std::vector<int>::iterator end, int idSeq, int seqLen){
    sqc u;
 
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
    initSeq(u, it, end);
    return (u);
}

std::vector<sqc> initPairing(std::vector<int>& v, int seqLen){//RETURN REF?
    std::vector<sqc> vec;
    int idSeq = 1;

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); )//IT = IT ATTENTION A LA BOUCLE INITSEQ
    {
        vec.push_back(initStructSeq(it, v.end(), idSeq, seqLen));
        idSeq++;
    }
    return (vec);
}

//SORTPAIRS

void swapRange(sqc& u1, sqc& u2){
    std::vector<int>::iterator it1 = u1.first;
    std::vector<int>::iterator it2 = u2.first;
    while(it1 != u1.last && it2 != u2.last)
    {
        std::iter_swap(it1,it2);
        it1++;
        it2++;
    }
    if (it1 != u1.last && it2 != u2.last)
        std::iter_swap(it1,it2);//A voir secu
}

void    sortPairs(std::vector<sqc>& pairing){
    std::vector<sqc>::iterator it1 = pairing.begin();
    std::vector<sqc>::iterator it2 = it1 + 1;
    while(it1 != pairing.end() && it2 != pairing.end()){
        if(*(it1->last) > *(it2->last) && it2->full == true ){//ATTENTION POTENTIELLEMENT IT2 N'EXISTE PAS
            swapRange(*it1, *it2);
        }
        it1++;
        if (it1 != pairing.end())
            it2++;
    }
}//ATTENTION TU DEREFERENCES IT2->LAST, MAIS IL PEUT ETRE A END(), POTENTIELLEMENT REFAIRE TON LAST A -1
