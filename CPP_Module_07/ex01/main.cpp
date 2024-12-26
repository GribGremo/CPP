/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:02:13 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/26 11:01:25 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void incrChar(char& c){
    ++c;
}

int main(){
    std::string str = "123456789";
    int t[] = {0,1,2,3,4,5,6,7,8,9};

    iter(t,10,incr<int>);// You need to specify the type of incr at this type, or he doesnt know the type of that function, he can take whatever but need to know at least

    for(int i = 0; i<10;i++){
        std::cout << "Value " << i << " of array: " << t[i] << std::endl;
    }
    std::cout << std::endl;
    // iter(t,10,square<float>);//Cannot do this my array is int type, can't put float in it
    iter(t,10,square<int>);
    
    for(int i = 0; i<10;i++){
        std::cout << "Value " << i << " of array: " << t[i] << std::endl;
    }
    std::cout << std::endl;

    iter(&str[0],str.size(),incr<char>);// I change address from reference to pointer so he can accept rvalue
    std::cout <<"str: "<< str << std::endl;
    std::cout << std::endl;

    iter(&str[0],str.size(),incrChar);// I change address from reference to pointer so he can accept rvalue
    std::cout << "str: " << str << std::endl;
    std::cout << std::endl;

    iter(static_cast<char*>(NULL),str.size(),incrChar);//Here compilator doesn't understand NULL as a pointer due to implicit conversion between void* and typed pointer not allowed in C++
}

/*
lambda: anonymous function defined inline
 auto incr = [factor](int& x) { x += factor; };

functor : class or object with an operator() able to be used as a function
class Increment {
public:
    void operator()(int& x) const {
        x++; 
    }
};
*/