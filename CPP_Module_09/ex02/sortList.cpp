#include <list>
#include <iostream>

struct pairer{
    std::list<sqc> min;
    std::list<sqc> max;
    int seqLen;
};

struct sqc{
    std::list<int>::iterator first;
    std::list<int>::iterator last;
    int idSeq;
    bool full;
};

//DEBUG

void printFL(std::list<int>::iterator first, std::list<int>::iterator last){
    while(first != last){
        std::cout << " " << *first;
        first++;
    }
    std::cout << " " << *first <<std::endl;
}

void printCont(std::list<int>& c){
    for(std::list<int>::iterator it = c.begin(); it != c.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
}

void printContIt(std::list<std::list<int>::iterator>& c){
    for(std::list<std::list<int>::iterator>::iterator it = c.begin(); it != c.end(); it++)
        std::cout << " " << *(*it);
    std::cout << std::endl;
}

void printStruct(sqc u){
    std::cout << "Sequence: ";
    printFL(u.first,u.last);
    std::cout << "Full: " << u.full << std::endl;
    std::cout << "Id min: " << u.idMinPair<< std::endl;
    std::cout << "Id max: " << u.idMaxPair << std::endl;
    std::cout << "Index list: " << u.idSeq << std::endl;
    std::cout << "Recursive: " << u.seqLen << std::endl << std::endl;
}

void printVecStruct(std::list<sqc> v){
    for(std::list<sqc>::iterator it = v.begin(); it != v.end(); it++)
        printStruct(*it);
}



void sortFJ_Container(std::list<int>& v, unsigned int seqLen);
void    initSeq(sqc& u, std::list<int>::iterator& it, std::list<int>::iterator end);
sqc initStructSeq(std::list<int>::iterator& it, std::list<int>::iterator end, int idSeq, int seqLen);
pairer initPairing(std::list<int>& v, int seqLen);
void swapRange(sqc& u1, sqc& u2);
void    sortPairs(std::list<sqc>& pairing);


void sortFJ_Container(std::list<int>& v, unsigned int seqLen){
    pairer pairing = initPairing(v,seqLen);
    // printCont(v);
    printVecStruct(pairing);
    // sortPairs(pairing);
    // printLstStruct(pairing);
    seqLen *= 2;
    // if(seqLen < v.size() / 2)
    //     sortFJ_Container(v, seqLen);
}

//INIT_VEC_SEQ
// void    initSeq(sqc& u, std::list<int>::iterator& it, std::list<int>::iterator end){
//     int i = 0;
//     u.first = it;
//     while(i < seqLen && it != end){
//         i++;
//         it++;
//     }
//     u.last = it;
//     if (it == end && i != seqLen) //secure not full, envoie struct
//         u.full = false;
//     else
//         u.full = true;
// }

sqc initStructSeq(std::list<int>::iterator& it, std::list<int>::iterator end, int idSeq, int seqLen){
    sqc u;
    int i = 0;
    u.first = it;
    while(i < seqLen && it != end){
        i++;
        it++;
    }
    u.last = it;
    if (it == end && i != seqLen) //secure not full, envoie struct
        u.full = false;
    else
        u.full = true;
    u.idSeq = idSeq;
    return (u);
}

pairer initPairing(std::list<int>& v, int seqLen){//RETURN REF?
    pairer pairing;
    int idSeq = 0;
    int i = 0;
    pairing.seqLen = seqLen;

    for(std::list<int>::iterator it = v.begin(); it != v.end(); )//IT = IT ATTENTION A LA BOUCLE INITSEQ
    {
        if (i % 2 == 0){
            idSeq++;
            pairing.min.push_back(initStructSeq(it, v.end(), idSeq, seqLen));
        }
        else
            pairing.max.push_back(initStructSeq(it, v.end(), idSeq, seqLen));
        i++;
    }
    return (pairing);
}

//SORTPAIRS

void swapRange(sqc& u1, sqc& u2){
    std::list<int>::iterator it1 = u1.first;
    std::list<int>::iterator it2 = u2.first;
    while(it1 != u1.last && it2 != u2.last)
    {
        std::iter_swap(it1,it2);
        it1++;
        it2++;
    }
    if (it1 != u1.last && it2 != u2.last)
        std::iter_swap(it1,it2);//A voir secu
}

void    sortPairs(std::list<sqc>& pairing){
    std::list<sqc>::iterator it1 = pairing.begin();
    std::list<sqc>::iterator it2 = it1 + 1;
    while(it1 != pairing.end() && it2 != pairing.end()){
        if(*(it1->last) > *(it2->last) && it2->full == true ){//ATTENTION POTENTIELLEMENT IT2 N'EXISTE PAS
            swapRange(*it1, *it2);
        }
        it1++;
        if (it1 != pairing.end())
            it2++;
    }
}//ATTENTION TU DEREFERENCES IT2->LAST, MAIS IL PEUT ETRE A END(), POTENTIELLEMENT REFAIRE TON LAST A -1
