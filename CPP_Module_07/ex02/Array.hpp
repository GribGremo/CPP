/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:43:37 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/16 17:32:07 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

class Array{
    public:
    Array():  n(0), array(NULL){}

    Array(const unsigned int s) : n(s), array(NULL) {
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

    Array(const Array& src) : n(src.n), array(NULL) {
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

    ~Array(){
        delete[] array;
    }

    Array& operator=(const Array& src){
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

    T& operator[]( unsigned int i){
        if (i >= n)
            throw(std::exception());
        return array[i];
    }


    void print_cell(int i){
        try{
            std::cout << this->array[i] << std::endl;
        }
        catch(const std::exception& e){
            throw;
        }
    }

    void printArray(){
        for(unsigned int i = 0; i < n; i++)
                std::cout << "Cell " << i + 1 << ": " << array[i] << std::endl;
        std::cout << std::endl;
    }

    void mod_cell(int i, int x){
        try{
            this->array[i] = x;
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
        }
    }

    unsigned int size()const{
        return (n);
    }
    
    private:
    unsigned int n;
    T *array;//Any type pointer
};