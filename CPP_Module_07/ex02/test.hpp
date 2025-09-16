#include <iostream>
#include "obj.hpp"
class test{
    public:
    test(){
        std::cout << "Test constructor called" << std::endl;
        a = new obj();
        std::cout << "alloc obj in test" << std::endl;
    }
    ~test(){
        std::cout << "Test destructor called" << std::endl;
        delete a;
        std::cout << "delete obj in test destructor" << std::endl;
    }

    test& operator=(const test& src){
        std::cout << "Test assignement operator called" << std::endl;
        delete a;
        std::cout << "delete obj in test operator" << std::endl;
        a = new obj(*src.a);
        std::cout << "alloc obj in test operator" << std::endl;
        return (*this);
    }
    private:
        obj *a;
};