/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:43:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/30 18:19:45 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

class Array{
    public:
    Array(){
        array = NULL;
    }
    Array(const unsigned int s){
        array = new T[s];
    }
    Array(const Array& src){
        
    }
    ~Array(){
        
    }

    Array& operator=(const Array& src){
        
    }
    const T& operator[](const unsigned int i){
        return array[i];
    }
    
    private:
    T *array;
};