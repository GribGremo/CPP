/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:43:37 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/17 13:12:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>

class Array{
    public:
    Array();
    
    Array(const unsigned int s);
    
    Array(const Array& src);
    
    ~Array();
    
    Array& operator=(const Array& src);
    
    T& operator[](const unsigned int i);
    
    const T& operator[](const unsigned int i)const;
    
    void printArray();
    void printArray()const;
    unsigned int size()const;
    
    private:
    unsigned int n;
    T *array;//Any type pointer
};

#include "Array.tpp" // Include here .tpp will not recognize Array:: if include before

#endif