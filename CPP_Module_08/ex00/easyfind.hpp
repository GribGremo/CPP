/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:12 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/17 16:58:06 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Containers supported in c++98: vector, deque, list, stack, queue, priority queue, set, multiset, map, multimap
Vector: Array that can grow, not really efficient reallocating, good accessing cell
Deque: Similar to vector but grow more efficiently even at beginning
List: double link list, good inserting, removing, deplacing elements, link costs more memory and no []
Stack: Operations accessible from the end(add,remove), seems to just store data
Queue: Add to end, remove from start
Priority-queue: Encore une heap mais ???
Set: Const unique values, sorted by "value"
Multiset: same but multiple identical  values allowed
Map: Hah table(key value identify and sort elements) map value(content), both associated in a pair
Multimap: Same but identical key value allowed(i imagined it useful if u want to store same object and use them(uniquely))*/

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& t, int n){
    return (std::find(t.begin(), t.end(), n)); // Use of template T::iterator might be a C type or class member, by default it's considered as as a variable or function, but we want it to be a type, so we put typename before it 
}

template <typename T>
void printResult( T& c, int v){
    typename T::iterator it = easyfind(c,v);
    if( it != c.end())
        std::cout << "Find occurence of " << v << " at index " << std::distance(c.begin(), it) << std::endl;
    else
        std::cout << "No value " << v << " found" << std::endl;
}

/*No operator [] on some containers so preferably used algorithm function that will focus on "smart pointers" with the help of containers::iterators, some containers handle theyre "items" memory not contiguously, which mean this objet memory are not ordered object 3 could be placed 1st in mepory"*/