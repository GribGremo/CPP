#ifndef BAG_HPP
#define BAG_HPP

class bag{

    public:
    virtual int insert(int) = 0;
    virtual int insert(const int) = 0;
    virtual void print()const = 0;
    virtual void erase() = 0;

};

#endif

/*        Bag               ← abstract base class
         ↑
    -----------------
    |               |
ArrayBag         TreeBag      ← concrete implementations of Bag
    ↑               ↑
    |               |
SearchableArrayBag  SearchableTreeBag  ← inherit from SearchableBag
     \             /
      \           /
     SearchableBag      ← inherits from Bag, adds has()
     
Set ← inherits from Bag, overrides add() to prevent duplicates*/
