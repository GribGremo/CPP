#include <iostream>
#include <list>
#include <cmath>


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



void printFL(sqc_list u);
void printCont(std::list<int>& c);
void printContIt(std::list<std::list<int>::iterator>& c);
void printLstSqc(std::list<sqc_list> lst);
void printStruct(pairer pairing);

std::list<int> listSqcToListInt(std::list<sqc_list> lstSqc);
std::list<sqc_list>::iterator getItFromId(std::list<sqc_list>& lst, int id);
std::list<sqc_list>::iterator getItFromindex(std::list<sqc_list>& lst, int id);
std::list<sqc_list>::iterator getPrev(std::list<sqc_list>& lst, std::list<sqc_list>::iterator it);
std::list<sqc_list>::iterator getNext(std::list<sqc_list>& lst, std::list<sqc_list>::iterator it);

std::list<sqc_list>::iterator binarySearch(std::list<sqc_list>& lst, std::list<sqc_list>::iterator start, std::list<sqc_list>::iterator end, int cmp);
void initIdList(std::list<sqc_list>& lst, std::list<sqc_list>::iterator& start, std::list<sqc_list>::iterator& end);
void execJS(std::list<sqc_list>& main,std::list<sqc_list>& pending,int idJS);
void setupJS(pairer& pairing, std::list<sqc_list>& main,std::list<sqc_list>& pending, std::list<sqc_list>& rest);
void insertRest(std::list<sqc_list>& main, std::list<sqc_list>& pending);
std::list<int> insertListFJ(pairer& pairing);

void swapRange(sqc_list& u1, sqc_list& u2);
void    sortPairs(pairer& pairing);

sqc_list initStructSeq(std::list<int>::iterator& it, std::list<int>::iterator end, int idSeq, int seqLen);
pairer initPairing(std::list<int>& v, int seqLen);

std::list<int> sortFJ_Container(std::list<int>& v, unsigned int seqLen);
