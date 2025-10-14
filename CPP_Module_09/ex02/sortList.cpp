#include <list>
#include <iostream>
#include <cmath>

struct sqc_list{
    // std::list<std::list<int>::iterator> seq;
    std::list<int>::iterator first;
    std::list<int>::iterator last;
    int idSeq;
    bool full;
};
struct pairer{
    std::list<sqc_list> min;
    std::list<sqc_list> max;
    int seqLen;
};


//DEBUG


void printFL(sqc_list u){
    if (u.full == false)
    std::cout << "\033[1;31m";
    while(u.first != u.last){
        std::cout << " " << *u.first;
        u.first++;
    }
    std::cout << " " << *u.first;
    std::cout << "\033[0m";
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

void printLstSqc(std::list<sqc_list> lst){
    for(std::list<sqc_list>::iterator it = lst.begin(); it != lst.end();it++){
        std::cout << "{";
        printFL(*it);
        std::cout << " }";
        std::cout << std::endl;
    }
}

void printStruct(pairer pairing){
    std::list<sqc_list>::iterator itmin = pairing.min.begin();
    std::list<sqc_list>::iterator itmax = pairing.max.begin();
    std::cout << "Sequence:"<< std::endl;
    while(itmin != pairing.min.end())
    {
        std::cout << "< ";
        printFL(*itmin);
        std::cout << " | ";
        if(itmax != pairing.max.end())
        printFL(*itmax);
        else
        std::cout << "EMPTY";
        std::cout << " >" << std::endl;
        itmin++;
        itmax++;
    }
    std::cout << "SeqLen: " << pairing.seqLen << std::endl;
}
// std::list<int> pairerToList(pairer pairing){
//     std::list<int> lst;
//     std::list<int>::iterator end = lst.end();
//     std::list<sqc_list>::iterator itMax = pairing.min.begin();
//     for(std::list<sqc_list>::iterator itMin = pairing.min.begin(); itMin != pairing.min.end(); itMin++){
//         // for(std::list<int>::iterator it = itMin->first; it != itMin->last;it++)
//         //     lst.push_back(*it);
//         lst.insert(end,itMin->first,itMin->last);
//         lst.push_back(*itMin->last);
//         if(itMax != pairing.max.end()){
//             // for(std::list<int>::iterator it = itMax->first; it != itMax->last;it++)
//             //     lst.push_back(*it);
//             lst.insert(end,itMax->first,itMax->last);
//             lst.push_back(*itMax->last);
//             itMax++;
//         }   
//     }
//     // printCont(lst);
//     return (lst);
// }

std::list<int> listSqcToListInt(std::list<sqc_list> lstSqc){
    std::list<int> lst;
    // printLstSqc(lstSqc);
    std::list<int>::iterator end = lst.end();
    for(std::list<sqc_list>::iterator it = lstSqc.begin(); it != lstSqc.end(); it++){
        lst.insert(end,it->first,it->last);
        lst.push_back(*it->last); 
    }
    // lst.push_back(3);
    // printCont(lst);
    return (lst);   
}

std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen);
void    initSeq(sqc_list& u, std::list<int>::iterator& it, std::list<int>::iterator end);
sqc_list initStructSeq(std::list<int>::iterator& it, std::list<int>::iterator end, int idSeq, int seqLen);
pairer initPairing(std::list<int>& v, int seqLen);
void swapRange(sqc_list& u1, sqc_list& u2);
void    sortPairs(pairer& pairing);
std::list<int> insertListFJ(pairer pairing);


std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen){
    std::list<int> lst;
    pairer pairing = initPairing(v,seqLen);

    sortPairs(pairing);
    seqLen *= 2;
    if(seqLen < v.size() / 2){
        lst = sortFJ_Container(v, seqLen);
        pairing = initPairing(lst, seqLen);
    }
    lst = insertListFJ(pairing);
    printCont(lst);
    return (lst);
}

void setupJS(pairer& pairing, std::list<sqc_list>& main,std::list<sqc_list>& pending){
    std::list<sqc_list>::iterator itmin = pairing.min.begin();
    std::list<sqc_list>::iterator itmax = pairing.max.begin();
    // printStruct(pairing);
    main.push_back(*itmin);
    itmin++;
    while(itmax != pairing.max.end() && itmax->full == true){
        main.push_back(*itmax);
        itmax++;
    }
    while(itmin != pairing.min.end()){
        pending.push_back(*itmin);
        itmin++;
    }
    if(itmax != pairing.max.end())//PAS SUR OBLIGE?
        pending.push_back(*itmax);
    // printLstSqc(main);
}

std::list<sqc_list>::iterator getItFromId(std::list<sqc_list>& lst, int id){
    std::list<sqc_list>::iterator it = lst.begin();
    while (it != lst.end() && id != it->idSeq)
        it++;
    return (it);
}

std::list<sqc_list>::iterator getPrev(std::list<sqc_list>& lst, std::list<sqc_list>::iterator it){
    if (it == lst.begin())
        return (lst.end());
    it--;
    return (it);
}

std::list<sqc_list>::iterator getNext(std::list<sqc_list>& lst, std::list<sqc_list>::iterator it){
    if (it == lst.end())
        return (it);
    it++;
    return (it);
}

 std::list<sqc_list>::iterator binarySearch(std::list<sqc_list> lst, std::list<sqc_list>::iterator start, std::list<sqc_list>::iterator end, int cmp){
    int diff = end->idSeq - start->idSeq;
    int mid = (diff / 2) + start->idSeq;
    int JS = (std::pow(2,2) - std::pow(-1,2)) / 3;
    std::list<sqc_list>::iterator searched = getItFromId(lst, mid);
    for (int x = 2; diff <= JS; x++)
        JS = (std::pow(2,x) - std::pow(-1,x)) / 3;
    // std::cout << *start->last << " " << *end->last <<std::endl;
    // std::cout << *searched->last <<std::endl;
    for (int i = 0; i < x; i++)//!(*searched->last > *getPrev(lst,searched)->last && *searched->last > *getNext(lst,searched)->last))
    {
        if(cmp > *searched->last){
            if(*getNext(lst,searched)->last > cmp)
                return (getNext(lst,searched));
            binarySearch(lst,start,searched,cmp);
        }
        else if (cmp < *searched->last){
            if(*getPrev(lst,searched)->last < cmp)
                return (searched);
            binarySearch(lst,searched,end,cmp);
        }
        else if (cmp == *searched->last)
            return (searched);
    }
}

void execJS(std::list<sqc_list>& main,std::list<sqc_list>& pending,int idJS){
    std::list<sqc_list>::iterator itMinMain = getNext(main, main.begin());
    std::list<sqc_list>::iterator itMaxMain = getPrev(main, getItFromId(main, idJS - 1));
    std::list<sqc_list>::iterator target;

    for ( std::list<sqc_list>::iterator itToInsert = getItFromId(pending,idJS); itToInsert != pending.end(); itToInsert = getPrev(pending,itToInsert)){
        itMaxMain = getPrev(main, getItFromId(main, idJS));
        target = binarySearch(main, itMinMain, itMaxMain, *itToInsert->last);
        main.splice(target,pending,itToInsert);
        idJS--;
    }
    // printLstSqc(main);
}

std::list<int> insertListFJ(pairer pairing){
    std::list<sqc_list> main;
    std::list<sqc_list> pending;
    std::list<int> lst;
    int idJS = (std::pow(2,3) - std::pow(-1,3)) / 3;//3 tout simplement?
    setupJS(pairing,main,pending);

    std::cout << "MAIN:" <<std::endl;
    printLstSqc(main);
    std::cout << "PENDING:" <<std::endl;
    printLstSqc(pending);
    for (int x = 3; idJS < pairing.max.rbegin()->idSeq; x++){
        // std::cout << "TOUR" << std::endl;
        execJS(main,pending,idJS);
        idJS = (std::pow(2,x) - std::pow(-1,x)) / 3;
    }
    if (pending.begin()!=pending.end())
        main.splice(main.end(),pending);//GAFFE
    lst = listSqcToListInt(main);
    // printCont(lst);
    return (lst);
}


//INIT_VEC_SEQ
// void    initSeq(sqc_list& u, std::list<int>::iterator& it, std::list<int>::iterator end){
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

sqc_list initStructSeq(std::list<int>::iterator& it, std::list<int>::iterator end, int idSeq, int seqLen){
    sqc_list u;
    int i = 0;
    u.first = it;
    while(i < seqLen - 1 && it != end){
        i++;
        it++;
    }
    if(it != end){
        u.full = true;
        u.last = it;
    }
    else{
        u.full = false;
        u.last = --it;
    }
    u.idSeq = idSeq;
    return (u);
}

pairer initPairing(std::list<int>& v, int seqLen){//RETURN REF?
    pairer pairing;
    int idSeq = 0;
    int i = 0;
    pairing.seqLen = seqLen;

    for(std::list<int>::iterator it = v.begin(); it != v.end(); it++)//IT = IT ATTENTION A LA BOUCLE INITSEQ
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

void swapRange(sqc_list& u1, sqc_list& u2){
    std::list<int>::iterator it1 = u1.first;
    std::list<int>::iterator it2 = u2.first;
    while(it1 != u1.last && it2 != u2.last)
    {
        std::iter_swap(it1,it2);
        it1++;
        it2++;
    }
    // if (it1 != u1.last && it2 != u2.last)
        std::iter_swap(it1,it2);//A voir secu WARNING VRAIMENT CA PUE(NORMALEMENT LES 2 EXISTENT ET LES 2 SONT PLEINS)
}

void    sortPairs(pairer& pairing){
    std::list<sqc_list>::iterator itmin = pairing.min.begin();
    std::list<sqc_list>::iterator itmax = pairing.max.begin();
    while(itmin != pairing.min.end() && itmax != pairing.max.end()){
        if(*(itmin->last) > *(itmax->last) && itmax->full == true ){//ATTENTION POTENTIELLEMENT IT2 N'EXISTE PAS
            swapRange(*itmin, *itmax);
        }
        itmin++;
        itmax++;
    }
}//ATTENTION TU DEREFERENCES IT2->LAST, MAIS IL PEUT ETRE A END(), POTENTIELLEMENT REFAIRE TON LAST A -1

// 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
/*
https://vivekupadhyay125.wordpress.com/wp-content/uploads/2013/08/donald-e-knuth-the-art-of-computer-programming-vol-3.pdf  p.197
*/

/*
Pour 2.pow(x) - 1 taille de sequence, il faut x comparaisons max
 *  *  *                                       3 unites
 .  |  .                                       1 comparaison
 |     |                                       2 comparaisons max

 *  *  *  *  *  *  *                           5
 .  .  .  |  .  .  .                           1
 .  |  .     .  |  .                           2
 |     |     |     |                           3

 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  11
                      |                        1
          |                       |            2
    |           |           |           |      3
 |     |     |     |     |     |     |     |   4

*/