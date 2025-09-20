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
    typedef typename std::deque<T>::iterator iterator;

    MutantStack(){

    }
    MutantStack(T& cell){
        st.push_back(cell);
    }
    MutantStack(const MutantStack& src){
        if (this = &src)
            this = *src;
    }
    ~MutantStack(){

    }

    MutantStack& operator=(const MutantStack& src){

    }

    void push(T cell){
        st.push_back(cell);
    }
    iterator top(){
        return (st.back());   
    }
    void pop(){
        st.pop_back();
    };
    size_t size(){
        return (st.size());
    }


    iterator begin(){
        return (st.begin());
    }
    iterator end(){
        return (st.end());
    }

    // ++ -- iterator
};

#endif