#include <iostream>

class obj{
    public:
    obj(){
    }
    obj& operator=(const obj& src){
        (void)src;
        return (*this);
    }
    ~obj(){}
    private:
        
};