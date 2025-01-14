/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:43:37 by sylabbe           #+#    #+#             */
/*   Updated: 2025/01/14 19:36:08 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

class Array{
    public:
    Array(){
        array = NULL;
        n = 0;
    }

    Array(const unsigned int s){
        this->n = s;
        array = new T[s];
        for (unsigned int i = 0; i < n; i++)
        {
            array[i] = T(); //by using T() i will initialise to any default type of my type, if number, put to 0, if a class, will use the default constructor of it
        }
    }

    Array(const Array& src){
        array = new T[src.n];
        n = src.n;
        for (unsigned int i = 0; i < src.n; i++)
        {
            array[i] = src.array[i];
        }
    }

    ~Array(){
        delete[] array;
    }

    Array& operator=(const Array& src){
        if (this == &src)
            return (*this);
        delete[] array;
        n = src.n;
        array = new T[src.n];// A VOIR
        for (unsigned int i = 0; i < src.n; i++)
        {
            array[i] = src.array[i];
        }
        return (*this);
    }

    T& operator[]( unsigned int i){
        if (i >= n)
            throw(std::exception());
        return array[i];
    }
    
    private:
    unsigned int n;
    T *array;
};