#ifndef ARRAY_BAG_HPP
#define ARRAY_BAG_HPP
#include "bag.hpp"

class array_bag : virtual public bag{
    private:
    int* value;
    int size;
    
    public:
    array_bag();
    array_bag(const array_bag& src);
    ~array_bag();

    array_bag& operator=(const array_bag& src);

    int insert(int);
    int insert(const int);
    void print()const;
    void erase();

};

#endif