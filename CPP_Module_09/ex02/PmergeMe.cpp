// #include "PmergeMe.hpp"
// #include "test.hpp"
#include <iostream>
#include <cmath>
#include <list>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\
|               _     ___ ____ _____              |
|              | |   |_ _/ ___|_   _|             |
|              | |    | |\___ \ | |               |
|              | |___ | | ___) || |               |
|              |_____|___|____/ |_|               |
|                                                 |
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

struct sqc_list{
    // std::list<std::list<int>::iterator> seq;
    std::list<int>::iterator first;
    std::list<int>::iterator last;
    int idSeq;
    int i;
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

// std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen);
void    initSeq(sqc_list& u, std::list<int>::iterator& it, std::list<int>::iterator end);
sqc_list initStructSeq(std::list<int>::iterator& it, std::list<int>::iterator end, int idSeq, int seqLen);
pairer initPairing(std::list<int>& v, int seqLen);
void swapRange(sqc_list& u1, sqc_list& u2);
void    sortPairs(pairer& pairing);
std::list<int> insertListFJ(pairer& pairing);


//////////////////////////////////////UTILS////////////////////////////////////////


std::list<sqc_list>::iterator getItFromId(std::list<sqc_list>& lst, int id){
    std::list<sqc_list>::iterator it = lst.begin();
    while (it != lst.end() && id != it->idSeq){
        // std::cout << "TOUR GETITFROMID" << std::endl;
        it++;
    }
    return (it);
}

std::list<sqc_list>::iterator getItFromindex(std::list<sqc_list>& lst, int id){
    std::list<sqc_list>::iterator it = lst.begin();
    while (it != lst.end() && id != it->i){
        // std::cout << "TOUR GETITFROMINDEX" << std::endl;
        it++;
    }
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


//////////////////////////////////////INSERT_LIST_FJ_JS////////////////////////////////////////


 std::list<sqc_list>::iterator binarySearch(std::list<sqc_list>& lst, std::list<sqc_list>::iterator start, std::list<sqc_list>::iterator end, int cmp){
    // std::cout << "COMPARATEUR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << cmp << std::endl;
    // std::cout <<"endid:"<< end->i<<"startid:"<< start->i << std::endl;
    int diff = end->i - start->i;
    int mid = ((diff / 2) + start->i) ;
    // std::cout << "MID:" << mid << std::endl;
    std::list<sqc_list>::iterator itmid = getItFromindex(lst, mid);
    std::list<sqc_list>::iterator res;
    // if (diff < 0)
        // std::cout <<"DIFF"<< diff << std::endl;
    if(cmp > *itmid->last){
        // std::cout << cmp << ">" << *itmid->last <<std::endl;
        if(start == end || diff < 0)
            return (getNext(lst,itmid));
        start = getNext(lst,itmid);
        if (end == lst.end())
            std::cout << "C'est la merde dans le binary search1"<<std::endl;

        // std::cout << ">>PARTIE SUPP" <<std::endl;
        res = binarySearch(lst,start,end,cmp);//partie superieure
    }
    else if (cmp < *itmid->last){
        // std::cout << cmp << "<" << *itmid->last <<std::endl;
        end = getPrev(lst,itmid);
        if(start == end || diff < 0 || end == lst.end())
            return (itmid);
        if (end == lst.end())
            std::cout << "C'est la merde dans le binary search2"<<std::endl;
        // std::cout << ">>PARTIE INFF" <<std::endl;
        res = binarySearch(lst,start,end,cmp);//partie interieure
    }
    else if (cmp == *itmid->last)
        return (itmid);

    return (res);
    // int diff = end->idSeq - start->idSeq;
    // int mid = ((diff / 2) + start->idSeq) + 1;
    // int JS = (std::pow(2,2) - std::pow(-1,2)) / 3;
    // std::list<sqc_list>::iterator searched = getItFromId(lst, mid);
    // for (int x = 2; diff <= JS; x++)
    //     JS = (std::pow(2,x) - std::pow(-1,x)) / 3;
    // // std::cout << *start->last << " " << *end->last <<std::endl;
    // // std::cout << *searched->last <<std::endl;
    // for (int i = 0; i < x; i++)//!(*searched->last > *getPrev(lst,searched)->last && *searched->last > *getNext(lst,searched)->last))
    // {
    //     if(cmp > *searched->last){
    //         if(*getNext(lst,searched)->last > cmp)
    //             return (getNext(lst,searched));
    //         binarySearch(lst,start,searched,cmp);
    //     }
    //     else if (cmp < *searched->last){
    //         if(*getPrev(lst,searched)->last < cmp)
    //             return (searched);
    //         binarySearch(lst,searched,end,cmp);
    //     }
    //     else if (cmp == *searched->last)
    //         return (searched);
    // }
}



void initIdList(std::list<sqc_list>& lst, std::list<sqc_list>::iterator& start, std::list<sqc_list>::iterator& end)
{
    int i = 1;
    for(std::list<sqc_list>::iterator it = start; it != getNext(lst,end); it++){
        // std::cout << i <<std::endl;
        it->i = i;
        i++;
    }
}


void execJS(std::list<sqc_list>& main,std::list<sqc_list>& pending,int idJS){
    std::list<sqc_list>::iterator itMinMain = main.begin();//getNext(main, main.begin());
    std::list<sqc_list>::iterator itMaxMain = getPrev(main, getItFromId(main, idJS));
    std::list<sqc_list>::iterator target;


    // std::cout << "MAIN:" <<std::endl;
    // printLstSqc(main);
    // std::cout << "PENDING:" <<std::endl;
    // printLstSqc(pending);

    for ( std::list<sqc_list>::iterator itToInsert = getItFromId(pending,idJS); itToInsert != pending.end(); itToInsert = getItFromId(pending,idJS)){
        // std::cout << "IDJS" << idJS <<std::endl;
        itMinMain = main.begin();
        itMaxMain = getPrev(main, getItFromId(main, idJS));
        // std::cout << "LAST" << *itMaxMain->last <<std::endl;

        initIdList(main,itMinMain,itMaxMain);//
        target = binarySearch(main, itMinMain, itMaxMain, *itToInsert->last);
        main.splice(target,pending,itToInsert);
        idJS--;
    }
    // printLstSqc(main);
}

void setupJS(pairer& pairing, std::list<sqc_list>& main,std::list<sqc_list>& pending, std::list<sqc_list>& rest){
    std::list<sqc_list>::iterator itmin = pairing.min.begin();
    std::list<sqc_list>::iterator itmax = pairing.max.begin();
    // printStruct(pairing);
    main.push_back(*itmin);
    itmin++;
    while(itmax != pairing.max.end() && itmax->full == true){
        main.push_back(*itmax);
        itmax++;
    }
    while(itmin != pairing.min.end()&& itmin->full == true){
        pending.push_back(*itmin);
        itmin++;
    }
    if(itmax != pairing.max.end())//PAS SUR OBLIGE?
        rest.push_back(*itmax);
    else if (itmin != pairing.min.end())
        rest.push_back(*itmin);
    // std::cout << "SETUPJS" << std::endl;
    // std:: cout << "MAIN" << std::endl;
    // printLstSqc(main);
    // std:: cout << "PENDING" << std::endl;
    // printLstSqc(pending);

}


void insertRest(std::list<sqc_list>& main, std::list<sqc_list>& pending){
    // std::list<sqc_list>::iterator endPending = pending.end();
    std::list<sqc_list>::iterator it = getPrev(pending,pending.end());
    std::list<sqc_list>::iterator itMaxMain = getPrev(main,main.end());
    std::list<sqc_list>::iterator itMinMain = main.begin();
    std::list<sqc_list>::iterator target;

    if (it == pending.end())
        return ;
    // std::cout << " it" << &it << std::endl;
    
    while(it != pending.end())
    {
        itMinMain = main.begin();
        itMaxMain = getPrev(main, getItFromId(main, it->idSeq));
        if (itMaxMain == main.end())
            std::cout << "C'est quoi cette merde??????????"<<std::endl;
        initIdList(main,itMinMain,itMaxMain);
        target = binarySearch(main,itMinMain,itMaxMain, *it->last);
        // itMaxMain = getItFromId(main, it->idSeq - 1);//C'est la regarde en bas pourquoi en bougeant ca ca deconne
        main.splice(target, pending, it);
        it = getPrev(pending, pending.end());
    }
}

//Jacosthal:Creation of main pending => until JS index higher than pending index => binarysearch on limited sequence with the help of JS
std::list<int> insertListFJ(pairer& pairing){
    std::list<sqc_list> main;
    std::list<sqc_list> pending;
    std::list<sqc_list> rest;
    // std::list<sqc_list>::iterator target;
    std::list<int> lst;
    int x = 3;

    setupJS(pairing,main,pending,rest);

    // std::cout << "MAIN:" <<std::endl;
    // printLstSqc(main);
    // std::cout << "PENDING:" <<std::endl;
    // printLstSqc(pending);
    if (pairing.max.empty())
        return (listSqcToListInt(pairing.min));

    for (int idJS = (std::pow(2,x) - std::pow(-1,x)) / 3; idJS <= pairing.max.rbegin()->idSeq; x++){//<?
        execJS(main,pending,idJS);
        idJS = (std::pow(2,x) - std::pow(-1,x)) / 3;
    }

    // std::cout << "STILL ON PENDING BEFORE INSERTREST:" << std::endl;
    // printLstSqc(pending);

    insertRest(main,pending);
    if (!rest.empty())
        main.push_back(*rest.begin());

    // std::cout << "STILL ON PENDING AFTER INSERTREST:" << std::endl;
    // printLstSqc(pending);

    lst = listSqcToListInt(main);
    // std::cout << "LIST INT APRES INSERT:" << std::endl;
    // printCont(lst);
    return (lst);
}




//////////////////////////////////////SORT_PAIRS////////////////////////////////////////V



void swapRange(sqc_list& u1, sqc_list& u2){
    std::list<int>::iterator it1 = u1.first;
    std::list<int>::iterator it2 = u2.first;

    while(it1 != u1.last && it2 != u2.last)//Potentiellement it1 != getNext(lst,u1.last) mais pas la liste, mais  ca marche normalement tkt jsute la fin est moche
    {
        std::iter_swap(it1,it2);
        it1++;
        it2++;
    }
    std::iter_swap(it1,it2);
}

void    sortPairs(pairer& pairing){
    std::list<sqc_list>::iterator itmin = pairing.min.begin();
    std::list<sqc_list>::iterator itmax = pairing.max.begin();

    while(itmin != pairing.min.end() && itmax != pairing.max.end()){
        if(*(itmin->last) > *(itmax->last) && itmax->full == true ){
            swapRange(*itmin, *itmax);
        }
        itmin++;
        itmax++;
    }
}

//////////////////////////////////////INIT_PAIRING////////////////////////////////////////

/*will create and return a structure sqc_container
It will incorporate 2 iterators representing the first and last numer of our sequence, it will also include idSeq, will be used with JS BS,
 to know wich sstructure is link to the other, will also use an index i*/
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
    u.i = 0;
    u.idSeq = idSeq;
    return (u);
}

/*Will create and return a structure pairer.
This structur incorporates 2 containers of int representing the min last int of our sequence and the max in the other,
this two form a pair, and incorporate the size of the sequence*/
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

//////////////////////////////////////MAIN////////////////////////////////////////

std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen){
    std::list<int> lst;
    pairer pairing = initPairing(v,seqLen);

    sortPairs(pairing);    
    if(seqLen * 2< v.size() / 2){
        lst = sortFJ_Container(v, seqLen * 2);
        pairing = initPairing(lst, seqLen);
    }
    lst = insertListFJ(pairing);
    return (lst);
}


//////////////////////////////////////MAINDEBUG////////////////////////////////////////


// std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen){
//     std::list<int> lst;
//     std::cout << "//////////////////////////////////REC: " << seqLen << "/////////////////////////////////" << std::endl;
//     std::cout << "LST:" << std::endl;
//     printCont(v);

//     std::cout << std::endl;
//     pairer pairing = initPairing(v,seqLen);

//     std::cout << std::endl<< "STRUCT AVANT SORTPAIR:"<<std::endl<< std::endl;
//     printStruct(pairing);

//     sortPairs(pairing);
    
//     std::cout << std::endl<< "STRUCT APRES SORTPAIR:"<<std::endl<< std::endl;
//     printStruct(pairing);

//     if(seqLen * 2 < v.size() / 2){
//         lst = sortFJ_Container(v, seqLen * 2);
//         std::cout << "//////////////////////////////////REC: " << seqLen<< "/////////////////////////////////" << std::endl;
//         std::cout << "LST:" << std::endl;
//         printCont(lst);
//         pairing = initPairing(lst, seqLen);
//     }

//     std::cout << std::endl<< "STRUCT AVANT INSERTLIST:"<<std::endl<< std::endl;
//     printStruct(pairing);

//     lst = insertListFJ(pairing);

//     std::cout << std::endl<< "LIST APRES INSERTLIST:" << std::endl<< std::endl;
//     printCont(lst);

//     return (lst);
// }




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

 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  15
                      |                        1
          |                       |            2
    |           |           |           |      3
 |     |     |     |     |     |     |     |   4

*/


// void insertRest(std::list<sqc_list>& main, std::list<sqc_list>& pending){
//     // std::list<sqc_list>::iterator endPending = pending.end();
//     std::list<sqc_list>::iterator it = getPrev(pending,pending.end());
//     std::list<sqc_list>::iterator itMaxMain;
//     std::list<sqc_list>::iterator itMinMain;
//     std::list<sqc_list>::iterator target;

//     if (it == pending.end())
//         return ;
//     // std::cout << " it" << &it << std::endl;
    
//     // if (!it->full){
//     //     endPending = it;
//     //     it = getPrev(pending, it);
//     //     std::cout << "endpending" << *endPending->last << " it" << &it << std::endl;
//     // }
//     while(it != pending.end())
//     {
//         itMinMain = main.begin();
//         itMaxMain = getItFromId(main, it->idSeq);
//         initIdList(main,itMinMain,itMaxMain);
//         target = binarySearch(main,itMinMain,itMaxMain, *it->last);
//         main.splice(target, pending, it);
//         it = getPrev(pending, pending.end());
//     }

//     // if (endPending != pending.end()){
//     //     std::cout << "AAAAAAAAAAAAAAAAAAA" <<std::endl;
//     //     main.splice(main.end(),pending);//GAFFE
//     // }
// }