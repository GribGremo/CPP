/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:00 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/04 16:25:37 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\
|             ____ _        _    ____ ____               |
|            / ___| |      / \  / ___/ ___|              |      
|           | |   | |     / _ \ \___ \___ \              |
|           | |___| |___ / ___ \ ___) |__) |             |
|            \____|_____/_/   \_\____/____/              |
|                                                        |
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~~~~*/


template <template < typename,typename> class Container>
PmergeMe<Container>::PmergeMe(){
    _res.empty = true;
    _res.execTime = 0;
    _res.containerType = "";
    _res.unitTime = "";
}

template <template < typename,typename > class Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& src){
    _res = src._res;
}

template <template < typename,typename > class Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv){
    try{
        checkContainerType(_res.containerType);
        timeSort(argc, argv);
    }
    catch(const std::exception& e)
    {
        _res.empty = true;
        _res.execTime = 0;
        _res.containerType = "";
        _res.unitTime = "";
        std::cerr << "Error: Can not build PmergeMe: " << e.what() <<std::endl;
        throw ;
    }
    _res.empty = false;
}

template <template < typename,typename > class Container>
PmergeMe<Container>::~PmergeMe(){}


/*~~~~~~~~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~~~~~~~~*/

template <template < typename,typename > class Container>
PmergeMe<Container> PmergeMe<Container>::operator=(const PmergeMe<Container>& src){
    if (this == &src)
        return (*this);
    _res = src._res;
    return (*this);
}

/*~~~~~~~~~~~~~~~~~~~~~GETTERS~~~~~~~~~~~~~~~~~~~~~*/
template <template < typename,typename > class Container>
const typename PmergeMe<Container>::result&  PmergeMe<Container>::getRes(){
    return (_res);
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\
|  _____ _____ __  __ ____  _        _  _____ _____   |
| |_   _| ____|  \/  |  _ \| |      / \|_   _| ____|  |
|   | | |  _| | |\/| | |_) | |     / _ \ | | |  _|    |
|   | | | |___| |  | |  __/| |___ / ___ \| | | |___   |
|   |_| |_____|_|  |_|_|   |_____/_/   \_\_| |_____|  |
|                                                     |
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//PUBLIC METHODS
//Return a boolean to signal if a sort has been made
template <template < typename,typename > class Container>
bool PmergeMe<Container>::empty(){
    return (_res.empty);
}

//print container content
template <template < typename,typename > class Container>
void PmergeMe<Container>::printCont(Container<int,std::allocator<int> >& c){
    for(typename Container<int,std::allocator<int> >::iterator it = c.begin(); it != c.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
}

//Check if container is sorted, return a boolean
template <template < typename,typename > class Container>
bool PmergeMe<Container>::isSorted(){
    if (_res.sorted.size() <= 1)
        return (true);

    typename Container<int, std::allocator<int> >::iterator it = _res.sorted.begin();
    typename Container<int, std::allocator<int> >::iterator prev = it;
    it++;
    while (it != _res.sorted.end())
    {
        if (*prev > *it)
            return (false);
        it++;
        prev++;
    }
    return (true);
}

//UTILS

//Generic function to check container type and init _res.containerType, this function has 2 specialisations for vector and list, if not one of those container, an eception is thrown
template <template <typename,typename> class Container>
void PmergeMe<Container>::checkContainerType(std::string& containerType){
    containerType = "Invalid container";
    throw std::runtime_error("Invalid container type");
}

//Generic function to execJS, without it i can't compile with an invalid template, compilator doesn't know i already check the type of container, he just want to create an execJS for deque(by default the generic) and find no corresponding function. I could have made explicit specialisation of execJS, but needed 2 prototypes in hpp
template <template <typename,typename> class Container>
void PmergeMe<Container>::execJS(Container<sqc, std::allocator<sqc> >& main,Container<sqc, std::allocator<sqc> >& pending,int idJS){
    (void)main;
    (void)pending;
    (void)idJS;
    throw std::runtime_error("Invalid Container type");
}

//Get iterator for a id, iterate until you findit the correct index, this is why list are so much inefficient in this exercise
template <template < typename,typename > class Container>
typename Container<typename PmergeMe<Container>::sqc,std::allocator<typename PmergeMe<Container>::sqc> >::iterator PmergeMe<Container>::getItFromId(Container<sqc,std::allocator<sqc> >& lst, int id){
    typename Container<sqc,std::allocator<sqc> >::iterator it = lst.begin();
    while (it != lst.end() && id != it->idSeq){
        it++;
    }
    return (it);
}

//METHODS

//Timer of parsing plus sort, will set _res.execTime and _res.unitTime
template <template < typename,typename > class Container>
void PmergeMe<Container>::timeSort(int argc , char **argv){
    timeval start;
    timeval end;

    gettimeofday(&start,NULL);

    parseArgs(argc, argv);
    sortFJ(1);
    
    gettimeofday(&end,NULL);
    _res.execTime = (end.tv_sec - start.tv_sec) *1000000L + (end.tv_usec - start.tv_usec);
    _res.unitTime = "μs";
    if (_res.execTime >= 1000 && _res.execTime < 1000000)
    {
        _res.unitTime = "ms";
        _res.execTime /= 1000;
    }
    else if (_res.execTime >= 1000000)
    {
        _res.unitTime = "s";
        _res.execTime /= 1000000;
    }
}

//PARSING

//if strtol of arg doesn't end at '\0' or out of bounds, or negative return false else return true
template <template < typename,typename > class Container>
bool PmergeMe<Container>::isArgValid(char* str, long int& value){
    char *end = NULL;
    errno = 0;
    value = strtol(str,&end,10);
    if (str == end || errno == ERANGE || *end != '\0' || value < 0 || value > __INT_MAX__ )
        return (false);
    return (true);
}

//Count arguments and verify arg format, if false return exception
template <template < typename,typename > class Container>
void    PmergeMe<Container>::parseArgs(int argc, char **argv){
    long int value = 0;
    if (argc < 2)
        throw std::runtime_error("Invalid number of arguments");

    for (int i = 1; i < argc; i++)
    {
        if (isArgValid(argv[i], value))
            _res.unsorted.push_back(static_cast<int>(value));
        else
            throw std::runtime_error("Invalid argument format");
    }
    _res.sorted = _res.unsorted;
}


//////////////////////////////////////DEBUG////////////////////////////////////////

template <template < typename,typename > class Container>
void PmergeMe<Container>::printFL(sqc u){
    if (u.full == false)
    std::cout << "\033[1;31m";
    while(u.first != u.last){
        std::cout << " " << *u.first;
        u.first++;
    }
    std::cout << " " << *u.first;
    std::cout << "\033[0m";
}



template <template < typename,typename > class Container>
void PmergeMe<Container>::printLstSqc(Container<sqc,std::allocator<sqc> > lst){
    for(typename Container<sqc,std::allocator<sqc> >::iterator it = lst.begin(); it != lst.end();it++){
        std::cout << "{";
        printFL(*it);
        std::cout << " }";
        std::cout << std::endl;
    }
}

template <template < typename,typename > class Container>
void PmergeMe<Container>::printStruct(pairer pairing){
    typename Container<sqc,std::allocator<sqc> >::iterator itmin = pairing.min.begin();
    typename Container<sqc,std::allocator<sqc> >::iterator itmax = pairing.max.begin();
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

//////////////////////////////////////CONVERT////////////////////////////////////////
//convert a container of structure seq, in a container of int
template <template < typename,typename > class Container>
Container<int,std::allocator<int> > PmergeMe<Container>::cSqcTocInt(Container<sqc,std::allocator<sqc> > lstSqc){
    Container<int,std::allocator<int> > lst;

    for(typename Container<sqc,std::allocator<sqc> >::iterator it = lstSqc.begin(); it != lstSqc.end(); it++){
        lst.insert(lst.end(),it->first,it->last);
        lst.push_back(*it->last); 
    }

    return (lst);   
}

//////////////////////////////////////SORT_PAIRS////////////////////////////////////////V

//This function swap the the 2 sequences of int, so min and max will be place accordingly
template <template < typename,typename > class Container>
void PmergeMe<Container>::swapRange(sqc& u1, sqc& u2){
    typename Container<int,std::allocator<int> >::iterator it1 = u1.first;
    typename Container<int,std::allocator<int> >::iterator it2 = u2.first;

    while(it1 != u1.last && it2 != u2.last)
    {
        std::iter_swap(it1,it2);
        it1++;
        it2++;
    }
    std::iter_swap(it1,it2);
}

//This function will sort by pairs, pairs are represented by 2 containers(min,max) aligned, we will swap them, if the last int of our sequence is superior to the last int of his 'pair' 
template <template < typename,typename > class Container>
void    PmergeMe<Container>::sortPairs(pairer& pairing){
    typename Container<sqc,std::allocator<sqc> >::iterator itmin = pairing.min.begin();
    typename Container<sqc,std::allocator<sqc> >::iterator itmax = pairing.max.begin();

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
template <template < typename,typename > class Container>
typename PmergeMe<Container>::sqc PmergeMe<Container>::initStructSeq(typename Container<int,std::allocator<int> >::iterator& it, typename Container<int,std::allocator<int> >::iterator end, int idSeq, int seqLen){
    sqc u;
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
template <template < typename,typename > class Container>
typename PmergeMe<Container>::pairer PmergeMe<Container>::initPairing(Container<int,std::allocator<int> >& v, int seqLen){//RETURN REF?
    pairer pairing;
    int idSeq = 0;
    int i = 0;
    pairing.seqLen = seqLen;

    for(typename Container<int,std::allocator<int> >::iterator it = v.begin(); it != v.end(); it++)//IT = IT ATTENTION A LA BOUCLE INITSEQ
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


template <template < typename,typename > class Container> 
void PmergeMe<Container>::setupJS(pairer& pairing, Container<sqc,std::allocator<sqc> >& main,Container<sqc,std::allocator<sqc> >& pending, Container<sqc,std::allocator<sqc> >& rest){
    typename Container<sqc,std::allocator<sqc> >::iterator itmin = pairing.min.begin();
    typename Container<sqc,std::allocator<sqc> >::iterator itmax = pairing.max.begin();
    
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
    if(itmax != pairing.max.end())
        rest.push_back(*itmax);
    else if (itmin != pairing.min.end())
        rest.push_back(*itmin);
}

//Jacosthal:Creation of main pending => until JS index higher than pending index => binarysearch on limited sequence with the help of JS
template <template < typename,typename > class Container> 
void PmergeMe<Container>::insertFJ(pairer& pairing){
    Container<sqc,std::allocator<sqc> > main;
    Container<sqc,std::allocator<sqc> > pending;
    Container<sqc,std::allocator<sqc> > rest;
    int x = 3;
    
    setupJS(pairing,main,pending,rest);
    if (pairing.max.empty()){
        _res.sorted = cSqcTocInt(pairing.min);
        return ;
    }
    for (int idJS = (std::pow(2,x) - std::pow(-1,x)) / 3; idJS <= pairing.max.rbegin()->idSeq; x++){//<?
        execJS(main,pending,idJS);
        idJS = (std::pow(2,x) - std::pow(-1,x)) / 3;
    }
    if (!pending.empty())
        execJS(main,pending,getPrev(pending,pending.end())->idSeq);
    if (!rest.empty())
        main.push_back(*rest.begin());
    _res.sorted = cSqcTocInt(main);
}

template <template < typename,typename > class Container> 
void PmergeMe<Container>::sortFJ(unsigned int seqLen){
    pairer pairing = initPairing(_res.sorted,seqLen);

    sortPairs(pairing);   
     
    if(seqLen * 2 <= _res.sorted.size() / 2){
        sortFJ(seqLen * 2);
        pairing = initPairing(_res.sorted, seqLen);
    }

    insertFJ(pairing);
}

//////////////////////////////////////MAINDEBUG////////////////////////////////////////

// template <template < typename,typename > class Container>
// Container<int,std::allocator<int> > PmergeMe<Container>::sortFJ_Container(Container<int,std::allocator<int> >& v, unsigned int seqLen){
//     Container<int,std::allocator<int> > lst;
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

//     if(seqLen * 2 <= v.size() / 2){//IIIIIIIIIIIIIIIIIIIIIICCCCCCCCCCCCCCCCCCCCCIIIIIIIIIIIII t'as mis <= au lieu de < PAS SUR
//         lst = sortFJ_Container(v, seqLen * 2);
//         std::cout << "//////////////////////////////////REC: " << seqLen<< "/////////////////////////////////" << std::endl;
//         std::cout << "LST:" << std::endl;
//         printCont(lst);
//         pairing = initPairing(lst, seqLen);
//     }

//     std::cout << std::endl<< "STRUCT AVANT INSERTLIST:"<<std::endl<< std::endl;
//     printStruct(pairing);

//     lst = insertFJ(pairing);

//     std::cout << std::endl<< "LIST APRES INSERTLIST:" << std::endl<< std::endl;
//     printCont(lst);

//     return (lst);
// }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\
|               _     ___ ____ _____              |
|              | |   |_ _/ ___|_   _|             |
|              | |    | |\___ \ | |               |
|              | |___ | | ___) || |               |
|              |_____|___|____/ |_|               |
|                                                 |
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


template <>
void PmergeMe<std::list>::checkContainerType(std::string& containerType){
    containerType = "std::list<int>";
}

//DEBUG

//return the it for index i, this index is used for binarysearch
template <>
std::list<PmergeMe<std::list>::sqc>::iterator PmergeMe<std::list>::getItFromindex(std::list<sqc>& lst, int id){
    std::list<sqc>::iterator it = lst.begin();
    while (it != lst.end() && id != it->i){
        it++;
    }
    return (it);
}


//UTILS

//return previous iterator, if none, return Container.end()
template <template < typename,typename > class Container> 
typename Container<typename PmergeMe<Container>::sqc, std::allocator<typename PmergeMe<Container>::sqc> >::iterator 
PmergeMe<Container>::getPrev(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator it){
    if (it == lst.begin())
        return (lst.end());
    it--;
    return (it);
}

//return next iterator, if already end, return himself
template <template < typename,typename > class Container> 
typename Container<typename PmergeMe<Container>::sqc, std::allocator<typename PmergeMe<Container>::sqc> >::iterator 
PmergeMe<Container>::getNext(Container<sqc,std::allocator<sqc> >& lst, typename Container<sqc,std::allocator<sqc> >::iterator it){
    if (it == lst.end())
        return (it);
    it++;
    return (it);
}


//////////////////////////////////////INSERT_LIST_FJ_JS////////////////////////////////////////
//binary search will compare at seq/2 recursively, until seq equal one, and retur n an iterator target to insert cmp 
template <>
std::list<PmergeMe<std::list>::sqc>::iterator PmergeMe<std::list>::binarySearch(std::list<sqc>& lst, std::list<sqc>::iterator start, std::list<sqc>::iterator end, int cmp){
    int diff = end->i - start->i;
    int mid = ((diff / 2) + start->i) ;
    std::list<sqc>::iterator itmid = getItFromindex(lst, mid);
    std::list<sqc>::iterator res;

    if(cmp > *itmid->last){
        if(start == end || diff < 0)
            return (getNext(lst,itmid));
        start = getNext(lst,itmid);
        res = binarySearch(lst,start,end,cmp);
    }
    else if (cmp < *itmid->last){
        end = getPrev(lst,itmid);
        if(/*start == end ||*/ diff < 0 || end == lst.end())
            return (itmid);
        res = binarySearch(lst,start,end,cmp);
    }
    else if (cmp == *itmid->last)
        return (itmid);

    return (res);
}



// template <>
// std::list<PmergeMe<std::list>::sqc>::iterator PmergeMe<std::list>::binarySearch(std::list<sqc>& lst, std::list<sqc>::iterator start, std::list<sqc>::iterator end, int cmp){
//     std::cout << "COMPARATEUR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << cmp << std::endl;
//     std::cout <<"endid:"<< end->i<<"startid:"<< start->i << std::endl;
//     int diff = end->i - start->i;
//     int mid = ((diff / 2) + start->i) ;
//     std::cout << "MID:" << mid << std::endl;
//     std::list<sqc>::iterator itmid = getItFromindex(lst, mid);
//     std::list<sqc>::iterator res;
//     if (diff <= 0)
//         std::cout <<"DIFF"<< diff << std::endl;
//     if(cmp > *itmid->last){
//         std::cout << cmp << ">" << *itmid->last <<std::endl;
//         if(start == end || diff < 0)
//             return (getNext(lst,itmid));
//         start = getNext(lst,itmid);
//         if (start == lst.end())
//             std::cout << "C'est la merde dans le binary search1"<<std::endl;

//         std::cout << ">>PARTIE SUPP" <<std::endl;
//         res = binarySearch(lst,start,end,cmp);//partie superieure
//     }
//     else if (cmp < *itmid->last){
//         std::cout << cmp << "<" << *itmid->last <<std::endl;
//         end = getPrev(lst,itmid);
//         if(/*start == end ||*/ diff < 0 || end == lst.end())
//             return (itmid);
//         if (end == lst.end())
//             std::cout << "C'est la merde dans le binary search2"<<std::endl;
//         std::cout << ">>PARTIE INFF" <<std::endl;
//         res = binarySearch(lst,start,end,cmp);//partie interieure
//     }
//     else if (cmp == *itmid->last)
//         return (itmid);

//     return (res);
// }


template <>
void PmergeMe<std::list>::initIdList(std::list<sqc>& lst, std::list<sqc>::iterator& start, std::list<sqc>::iterator& end)
{
    int i = 1;
    for(std::list<sqc>::iterator it = start; it != getNext(lst,end); it++){
        it->i = i;
        i++;
    }
}

template <>
void PmergeMe<std::list>::execJS(std::list<sqc>& main,std::list<sqc>& pending,int idJS){
    std::list<sqc>::iterator itMinMain = main.begin();//getNext(main, main.begin());
    std::list<sqc>::iterator itMaxMain = getPrev(main, getItFromId(main, idJS));
    std::list<sqc>::iterator target;

    for ( std::list<sqc>::iterator itToInsert = getItFromId(pending,idJS); itToInsert != pending.end(); itToInsert = getItFromId(pending,idJS)){
        itMinMain = main.begin();
        itMaxMain = getPrev(main, getItFromId(main, idJS));
        initIdList(main,itMinMain,itMaxMain);//
        target = binarySearch(main, itMinMain, itMaxMain, *itToInsert->last);
        // std::cout << "TARGET----------------------------->" << *target->last <<std::endl;
        main.splice(target,pending,itToInsert);
        idJS--;
    }
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\
|     __     _______ ____ _____ ___  ____        |
|     \ \   / / ____/ ___|_   _/ _ \|  _ \       |
|      \ \ / /|  _|| |     | || | | | |_) |      |
|       \ V / | |__| |___  | || |_| |  _ <       |
|        \_/  |_____\____| |_| \___/|_| \_\      |
|                                                |
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


template <>
void PmergeMe<std::vector>::checkContainerType(std::string& containerType){
    containerType = "std::vector<int>";
}


template <>
std::vector<PmergeMe<std::vector>::sqc>::iterator PmergeMe<std::vector>::binarySearch(std::vector<sqc>& lst, std::vector<sqc>::iterator start, std::vector<sqc>::iterator end, int cmp){
    (void)lst;
    return std::lower_bound(start, end, cmp, CmpStruct());
    
    // int diff = end->i - start->i;//C"EST LA LE PROBLEME T"A PAS INIT I
    // int mid = ((diff / 2) + start->i) ;
    // int idmid = mid - 1;
    // std::vector<sqc>::iterator res;

    // if(cmp > *(lst[idmid].last)){
    //     if(start == end || diff < 0)
    //         return (lst.begin() + (idmid + 1 ));
    //     start = lst.begin() + (idmid + 1);
    //     res = binarySearch(lst,start,end,cmp);
    // }
    // else if (cmp <  *(lst[idmid].last)){
    //     end = lst.begin() + (idmid - 1);
    //     if(/*start == end ||*/ diff < 0 || end == lst.end())
    //         return (lst.begin() + idmid);
    //     res = binarySearch(lst,start,end,cmp);
    // }
    // else if (cmp == *(lst[idmid].last))
    //     return (lst.begin() + idmid);

    // return (res);
}

template <>
void PmergeMe<std::vector>::execJS(std::vector<sqc>& main,std::vector<sqc>& pending,int idJS){
    std::vector<sqc>::iterator itMinMain = main.begin();
    std::vector<sqc>::iterator itMaxMain = getPrev(main, getItFromId(main, idJS));
    std::vector<sqc>::iterator target;

    for ( std::vector<sqc>::iterator itToInsert = getItFromId(pending,idJS); itToInsert != pending.end(); itToInsert = getItFromId(pending,idJS)){
        itMinMain = main.begin();
        itMaxMain = getItFromId(main, idJS);
        target = std::lower_bound(itMinMain, itMaxMain, *itToInsert->last, CmpStruct());// binarySearch(main, itMinMain, itMaxMain, *itToInsert->last);
        main.insert(target,*itToInsert);
        pending.erase(itToInsert);
        idJS--;
    }
}


//FAIS LES GENERIQUES POUR CALMER LE COMPILATEUR