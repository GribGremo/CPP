#ifndef SEARCHABLE_BAG_HPP
#define SEARCHABLE_BAG_HPP
#include "bag.hpp"

class searchable_bag : virtual public bag{
    virtual const bool has(int) = 0;
};

#endif