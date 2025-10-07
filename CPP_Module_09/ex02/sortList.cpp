#include <list>
#include <iostream>

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
        printFL(*it);
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

void sortFJ_Container(std::list<int>& v, unsigned int seqLen);
void    initSeq(sqc_list& u, std::list<int>::iterator& it, std::list<int>::iterator end);
sqc_list initStructSeq(std::list<int>::iterator& it, std::list<int>::iterator end, int idSeq, int seqLen);
pairer initPairing(std::list<int>& v, int seqLen);
void swapRange(sqc_list& u1, sqc_list& u2);
void    sortPairs(pairer& pairing);
void insertListFJ(pairer pairing);


void sortFJ_Container(std::list<int>& v, unsigned int seqLen){
    pairer pairing = initPairing(v,seqLen);
    // printCont(v);
    printStruct(pairing);
    sortPairs(pairing);
    printStruct(pairing);
    // printLstStruct(pairing);
    seqLen *= 2;
    if(seqLen < v.size() / 2)
        sortFJ_Container(v, seqLen);
    printCont(v);
    insertListFJ(pairing);
    printCont(v);
}

void insertListFJ(pairer pairing){
    std::list<sqc_list> main;
    std::list<sqc_list> pending;
    std::list<sqc_list>::iterator itmin = pairing.min.begin();
    std::list<sqc_list>::iterator itmax = pairing.max.begin();

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


    std::cout << "MAIN:" <<std::endl;
    printLstSqc(main);
    std::cout << "PENDING:" <<std::endl;
    printLstSqc(pending);
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


/*
https://vivekupadhyay125.wordpress.com/wp-content/uploads/2013/08/donald-e-knuth-the-art-of-computer-programming-vol-3.pdf  p.197
*/

/*
Pour 2.pow(x) - 1 taille de sequence, il faut x comparaisons max
 .  .  .                                       3 unites
    |                                          1 comparaison
 |     |                                       2 comparaisons max

 .  .  .  .  .  .  .                           5
          |                                    1
    |           |                              2
 |     |     |     |                           3

 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  11
                      |                        1
          |                       |            2
    |           |           |           |      3
 |     |     |     |     |     |     |     |   4
Comment deduit il la taille de ma sequence en fonction de jacobstal?
*/