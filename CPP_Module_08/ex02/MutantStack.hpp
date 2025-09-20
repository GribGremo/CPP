#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
// #include <deque>


template <typename T> 
class  MutantStack : public std::stack{
    private:
    std::deque<T> st;

    public:

    MutantStack(){

    }
    MutantStack(T& cell){
        st.push_back(cell);
    }
    MutantStack(const MutantStack& src){
        if (this = src)
            this = *src;
    }
    ~MutantStack(){

    }

    MutantStack& operator=(const MutantStack& src){

    }

    void push(T& cell);//
    T& top();// Renvoie reference de element de type INT ou TEMPLATE
    void pop();
    size_t size();
    std::deque::iterator& begin();
    std::deque::iterator& enf();

    // ++ -- iterator
    // std::stack
};

#endif