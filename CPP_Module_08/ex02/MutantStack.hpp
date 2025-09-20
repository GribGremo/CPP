#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
// #include <deque>


template <typename T> 
class  MutantStack : public std::stack{
    private:
    std::deque<T> st;
    typename iterator;

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

    void push(T& cell){
        st.push_back(cell);
    }
    T& top(){
        return (st.back());   
    }
    void pop(){
        st.pop_back();
    };
    size_t size(){
        return (st.size());
    }
    std::deque::iterator& begin(){
        return (st.begin());
    }
    std::deque::iterator& end(){
        return (st.end());
    }

    // ++ -- iterator
};

#endif