#include <iostream>
#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
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

    // additional test
    std::cout << "additional tests" << std::endl;
    MutantStack<int>::reverse_iterator itr = mstack.rbegin();
    std::cout << "REBEG: " << *itr << std::endl;
    itr = mstack.rend();
    std::cout << "REEND: " << *(--itr) << std::endl;
    MutantStack<int>::const_iterator itc = mstack.cbegin();
    itc++;
    // *itc =15; //const so impossible to change value at this iterator
    MutantStack<int>::const_reverse_iterator itrc = mstack.crbegin();
    std::cout << "rcb: " << *itrc << std::endl;
    itrc++;
    std::cout << "rcb+1: " << *itrc << std::endl;
    // *itrc = 15; //same here
    MutantStack<int,std::vector<int> > test;
    test.push(1);
    test.push(2);
    test.push(3);
    std::cout << test.top() << std::endl;
    test.pop();
    std::cout << test.top() << std::endl;
    MutantStack<int, std::vector<int> >::iterator t = test.begin();
    std::cout << *t << std::endl;
    t++;
    std::cout << *t << std::endl;



    //vector
    std::cout << "VECTOR RESULT" << std::endl;
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    std::cout << vec.back() << std::endl;//back close to top
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
    
    return 0;
}
