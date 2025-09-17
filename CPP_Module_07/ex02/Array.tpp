//CONSTRUCTORS/DESTRUCTOR

    /*Visual studio seem to not understand the late include in .hpp(don't recognize Array<T>), compilator still succeed,
     type is Array<T>, not Array::
     It seems that .tpp might disappeared to the profit of C++20 Modules*/
    template <typename T>
    Array<T>::Array():  n(0), array(NULL){}

    template <typename T>
    Array<T>::Array(const unsigned int s) : n(s), array(NULL) {
        try{
            array = new T[n];
            for (unsigned int i = 0; i < n; i++)
                array[i] = T();
        }
        catch(const std::bad_alloc& e){
            delete[] array;
            array = NULL;
            n = 0;
            throw;
        }
    }

    template <typename T>
    Array<T>::Array(const Array& src) : n(src.n), array(NULL) {
        try{
            array = new T[n];
            for (unsigned int i = 0; i < src.n; i++)
                array[i] = src.array[i];
        }
        catch(...){
            delete[] array;
            array = NULL;
            n = 0;
            throw;
        }
    }

    template <typename T>
    Array<T>::~Array(){
        delete[] array;
    }

//OPERATORS
    template <typename T>
    Array<T>& Array<T>::operator=(const Array<T>& src){
        T *newArray = NULL;
        if (this == &src)
            return (*this);
        try{
            newArray = new T[src.n];
            for (unsigned int i = 0; i < src.n; i++)
                newArray[i] = src.array[i];
            delete[] array;
            n = src.n;
            array = newArray;
        }
        catch(...){
            delete[] newArray;
            n = 0;
            throw;
        }
        return (*this);
    }

    template <typename T>
    T& Array<T>::operator[](const unsigned int i){
        if (i >= n)
            throw(std::exception());
        return array[i];
    }

    template <typename T>
    const T& Array<T>::operator[](const unsigned int i)const{
        if (i >= n)
            throw(std::exception());
        return array[i];
    }

//METHODS

    template <typename T>
    void Array<T>::printArray(){
        for(unsigned int i = 0; i < n; i++)
                std::cout << "Cell " << i + 1 << ": " << array[i] << std::endl;
        std::cout << std::endl;
    }

    template <typename T>
    void Array<T>::printArray()const{
        for(unsigned int i = 0; i < n; i++)
                std::cout << "Cell " << i + 1 << ": " << array[i] << std::endl;
        std::cout << std::endl;
    }

    template <typename T>
    unsigned int Array<T>::size()const{
        return (n);
    }