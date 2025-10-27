#include <iostream>
#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
    //mutantstack
    std::cout << "MUTANTSTACK RESULT" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout <<std::endl;

    //vector
    std::cout << "VECTOR RESULT" << std::endl;

    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    std::cout << vec.back() << std::endl;
    vec.pop_back();
    std::cout << vec.size() << std::endl;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    //[...]
    vec.push_back(0);
    std::vector<int>::iterator itv = vec.begin();
    std::vector<int>::iterator itev = vec.end();
    ++itv;
    --itv;
    
    while (itv != itev)
    {
        std::cout << *itv << std::endl;
        ++itv;
    }
    std::vector<int> sv(vec);
    std::cout <<std::endl;

    //list
    std::cout << "LIST RESULT" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator itl = lst.begin();
    std::list<int>::iterator itel = lst.end();
    ++itl;
    --itl;
    
    while (itl != itel)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }
    std::list<int> l(lst);
    std::cout <<std::endl;
    
    // additional test
    std::cout << "additional tests" << std::endl;
    MutantStack<int>::reverse_iterator itr = mstack.rbegin();
    std::cout << "REBEG: " << *itr << std::endl;
    itr = mstack.rend();
    std::cout << "REEND: " << *(--itr) << std::endl;
    MutantStack<int>::const_iterator itc = mstack.cbegin();
    itc++;
    std::cout << "ITC:" << *itc <<std::endl;
    MutantStack<int>::const_reverse_iterator itrc = mstack.crbegin();
    std::cout << "RCB: " << *itrc << std::endl;
    itrc++;
    std::cout << "RCB+1: " << *itrc << std::endl;
    MutantStack<int,std::vector<int> > test;
    test.push(1);
    test.push(2);
    test.push(3);
    std::cout << "TOP" << test.top() << std::endl;
    test.pop();
    std::cout << "TOP" << test.top() << std::endl;
    MutantStack<int, std::vector<int> >::iterator t = test.begin();
    std::cout << "SIMPLE:" << *t << std::endl;
    t++;
    std::cout << "SIMPLE:" << *t << std::endl;
    std::cout <<std::endl;

    std::cout << "TEST STACK VEC:" <<std::endl;
    MutantStack<int, std::vector<int> > msvec;
    msvec.push(1);
    msvec.push(2);
    msvec.push(3);
    MutantStack<int, std::vector<int> >::iterator itmsvec = msvec.begin();
    std::cout << "MSVEC:" << *itmsvec << " " << *++itmsvec << " " << *++itmsvec <<std::endl;
    std::cout <<std::endl;

    std::cout << "TEST STACK LIST:" <<std::endl;
    MutantStack<int, std::list<int> > mslst;
    mslst.push(1);
    mslst.push(2);
    mslst.push(3);
    MutantStack<int, std::list<int> >::iterator itmslst = mslst.begin();
    std::cout << "MSLST:" << *itmslst << " " << *++itmslst << " " << *++itmslst <<std::endl;
    std::cout <<std::endl;
   

    std::cout << "TEST OPERATOR=:" <<std::endl;

    MutantStack<int, std::list<int> > mslst2 = mslst;

    MutantStack<int, std::list<int> >::iterator itmslst2 = mslst2.begin();
    std::cout << "MSLST2:" << *itmslst2 << " " << *++itmslst2 << " " << *++itmslst2 <<std::endl;
    std::cout <<std::endl;

    std::cout << "TEST COPY CONSTRUCTOR:" <<std::endl;

    MutantStack<int, std::list<int> > mslst3(mslst);

    MutantStack<int, std::list<int> >::iterator itmslst3 = mslst3.begin();
    std::cout << "MSLST3:" << *itmslst3 << " " << *++itmslst3 << " " << *++itmslst3 <<std::endl;
    std::cout <<std::endl;

    std::cout << "TEST OPERATOR= ERASE:" <<std::endl;

    mslst3 = mslst2;
    MutantStack<int, std::list<int> >::iterator itmslst3_ = mslst3.begin();
    std::cout << "MSLST3:" << *itmslst3_ << " " << *++itmslst3_ << " " << *++itmslst3_ <<std::endl;

    return 0;
}
