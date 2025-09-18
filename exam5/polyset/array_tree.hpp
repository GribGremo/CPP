#ifndef ARRAY_TREE_HPP
#define ARRAY_TREE_HPP
#include "bag.hpp"

class array_tree : virtual public bag{
    private:
    int* value;
    int size;
    
    public:
    array_tree();
    array_tree(const array_tree& src);
    ~array_tree();

    array_tree& operator=(const array_tree& src);

    int insert(int);
    int insert(const int);
    void print()const;
    void erase();

};

#endif