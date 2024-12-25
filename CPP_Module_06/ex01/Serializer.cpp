/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:08:48 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/25 18:03:24 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


//CONSTRUCTORS
Serializer::Serializer(){
}
Serializer::Serializer(const Serializer& src){
    (void) src;
}
Serializer::~Serializer(){
}
Serializer& Serializer::operator=(const Serializer& src){
    (void) src;
    return (*this);
}

//METHODS

uintptr_t Serializer::serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data*>(raw));
}